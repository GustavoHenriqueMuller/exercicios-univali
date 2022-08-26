import { Injectable } from "@angular/core";
import { BehaviorSubject, concatMap, filter, from, map, Observable, Observer, share, tap } from "rxjs";
import { ElectronService } from "../electron/electron.service";

@Injectable({ providedIn: "root" })
export class FileService {

  private actualFilePath$: BehaviorSubject<string | undefined>;
  public executablePath$: BehaviorSubject<string | undefined>;
  private notSaved$: BehaviorSubject<boolean>;

  private onConsoleMessage$: Observer<string>;
  private readonly emitConsoleMessage$: Observable<string>;

  private onScope$: Observer<string>;
  private readonly emitScope$: Observable<string>;

  constructor(private electronService: ElectronService) {
    this.emitConsoleMessage$ = new Observable<string>(observer => this.onConsoleMessage$ = observer)
      .pipe(share());
    this.emitScope$ = new Observable<string>(observer => this.onScope$ = observer)
      .pipe(share());
    this.actualFilePath$ = new BehaviorSubject<string>(undefined);
    this.executablePath$ = new BehaviorSubject<string>(undefined);
    this.notSaved$ = new BehaviorSubject<boolean>(true);
  }

  save$(code: string): Observable<string> {
    if (!!this.actualFilePath$.getValue()) {
      return this.saveFileInDisk$(this.actualFilePath$.getValue(), code);
    }

    return this.saveCP2File$()
      .pipe(
        concatMap((filePath) => this.saveFileInDisk$(filePath, code))
      );
  }

  open$(): Observable<string> {
    return this.openCP2File$()
      .pipe(
        tap(() => this.setStateToSaved()),
        concatMap(((filePath) => this.getFileContent$(filePath)))
      );
  }

  setExecutable$(): Observable<string> {
    return this.openDialogAndGetFilePath$("showOpenDialogSync")
      .pipe(
        tap((filePath: string) => this.executablePath$.next(filePath)),
      );
  }

  execute$(filePath: string): Observable<Array<string>> {
    return from(this.electronService.childProcess("execSync", `\"${this.executablePath$.getValue()}\" \"${filePath}\"`))
      .pipe(
        map((result: any) => new TextDecoder().decode(result)),
        map((result: string) => result.split("\n").map(s => s.trim()).filter(s => s.length > 0)),
        tap((result: Array<string>) => {
          const scopes = result.filter(s => s.startsWith("[SCOPES] ")).map(s => s.substring(9));
          if (scopes.length > 0) {
            this.onScope$.next(scopes[0]);
          }
        }),
        tap((result: Array<string>) => {
          const messages = result.filter(s => !s.startsWith("[SCOPES] "));
          messages.forEach(value => this.onConsoleMessage$.next(value));
        }),
      );
  }

  // new$(): Observable<string> {
  //   if (!this.notSaved$.getValue()) {
  //     return this.openDialogAndGetFilePath$("showSaveDialogSync")
  //       .pipe(
  //         tap(() => this.setStateToSaved()),
  //         tap((filePath) => this.saveFileInDisk(filePath, ""))
  //       );
  //   }
  //
  //   return this.confirmToCloseWithoutSaving$()
  //     .pipe(
  //       tap(() => this.setStateToSaved()),
  //       map((filePath) => this.getFileContent(filePath))
  //     );
  // }


  get consoleMessage$(): Observable<string> {
    return this.emitConsoleMessage$;
  }

  get scopes$(): Observable<string> {
    return this.emitScope$;
  }

  get isNotSaved$(): Observable<boolean> {
    return this.notSaved$.asObservable();
  }

  get executableIsDefined(): boolean {
    return !!this.executablePath$.getValue();
  }

  public setStateToNotSaved() {
    this.notSaved$.next(true);
  }

  private setStateToSaved() {
    this.notSaved$.next(false);
  }

  private getFileContent$(filePath: string): Observable<string> {
    this.actualFilePath$.next(filePath);
    return from(this.electronService.fs("readFileSync", filePath))
      .pipe(
        map((code: any) => new TextDecoder().decode(code))
      );
  }

  private saveFileInDisk$(filePath: string, code: string): Observable<string> {
    return from(this.electronService.fs("writeFileSync", filePath, code, "utf-8"))
      .pipe(
        tap(() => {
          this.setStateToSaved();
          this.actualFilePath$.next(filePath);
        }),
        map(() => filePath)
      );
  }

  public confirmToCloseWithoutSaving$(): Observable<number> {
    const options = {
      type: "warning",
      buttons: ["Salvar", "Não salvar", "Cancelar"],
      defaultId: 0,
      title: "IDE",
      cancelId: 2,
      message: "Deseja salvar as alterações?",
      detail: "Suas alterações serão perdidas se você não as salvar",
    };

    return from(this.electronService.dialog("showMessageBoxSync", options))
      .pipe(
        map((response) => response as number)
      );
  }

  public openDialogAndGetFilePath$(mode: "showSaveDialogSync" | "showOpenDialogSync"): Observable<string> {
    return from(this.electronService.dialog(mode, {}))
      .pipe(
        filter((filePath) => !!filePath),
        map((filePath: any) => Array.isArray(filePath) ? filePath[0] : filePath),
      );
  }

  private openCP2File$(): Observable<string> {
    return this.openDialogAndGetFilePath$("showOpenDialogSync")
      .pipe(
        map((filePath: string) => {
          const array = filePath.split("\\");
          return (array.length > 1 && array[array.length - 1].split(".").length === 1) ? filePath + ".cp2" : filePath;
        })
      );
  }

  private saveCP2File$(): Observable<string> {
    return this.openDialogAndGetFilePath$("showSaveDialogSync")
      .pipe(
        map((filePath: string) => {
          const array = filePath.split("\\");
          return (array.length > 1 && array[array.length - 1].split(".").length === 1) ? filePath + ".cp2" : filePath;
        })
      );
  }
}
