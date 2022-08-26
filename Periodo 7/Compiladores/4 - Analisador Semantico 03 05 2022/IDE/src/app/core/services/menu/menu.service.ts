import { Injectable } from "@angular/core";
import { filter, Observable, Observer, share } from "rxjs";

/**
 * TODO Rohling - Transformar menu em enum
 */
@Injectable({ providedIn: "root" })
export class MenuService {

  private onAction$: Observer<number>;
  private readonly action$: Observable<number>;

  constructor() {
    this.action$ = new Observable<number>(observer => this.onAction$ = observer)
      .pipe(share());
  }

  get saveAction$(): Observable<number> {
    return this.action$.pipe(filter(((action) => action === 0)));
  }

  get openAction$(): Observable<number> {
    return this.action$.pipe(filter(((action) => action === 1)));
  }

  get newAction$(): Observable<number> {
    return this.action$.pipe(filter(((action) => action === 2)));
  }

  get buildAction$(): Observable<number> {
    return this.action$.pipe(filter(((action) => action === 3)));
  }

  get setExecutableAction$(): Observable<number> {
    return this.action$.pipe(filter(((action) => action === 4)));
  }

  saveFile(): void {
    this.onAction$.next(0);
  }

  openFile(): void {
    this.onAction$.next(1);
  }

  newFile(): void {
    this.onAction$.next(2);
  }

  buildFile(): void {
    this.onAction$.next(3);
  }

  setExecutable(): void {
    this.onAction$.next(4);
  }
}
