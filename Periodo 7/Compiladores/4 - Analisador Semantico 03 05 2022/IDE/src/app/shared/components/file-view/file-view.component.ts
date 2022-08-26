import { ChangeDetectionStrategy, Component, OnInit, ViewChild, ViewEncapsulation } from "@angular/core";
import { concatMap, filter, take } from "rxjs";
import { FormBuilder } from "@angular/forms";
import { ElectronService, FileService, MenuService } from "../../../core/services";
import { UnsubscribeDirective } from "../../directives";
import { MonacoEditorComponent, MonacoEditorLoaderService } from "@materia-ui/ngx-monaco-editor";
import * as customTheme from "assets/local/customTheme.json";
import * as tokens from "assets/local/token.json";
import * as configuration from "assets/local/configuration.json";

@Component({
  changeDetection: ChangeDetectionStrategy.OnPush,
  selector: "app-file-view",
  templateUrl: "./file-view.component.html",
  styleUrls: ["./file-view.component.scss"],
  encapsulation: ViewEncapsulation.None,
})
export class FileViewComponent extends UnsubscribeDirective implements OnInit {

  public code: string;
  public options: any;

  @ViewChild(MonacoEditorComponent) editor: MonacoEditorComponent;

  constructor(private electronService: ElectronService, private formBuilder: FormBuilder,
              private fileService: FileService, private menuService: MenuService,
              private monacoLoaderService: MonacoEditorLoaderService) {
    super();
    this.code = "";
    this.options = { theme: "cp2Theme", language: "cp2", fontSize: "16" };

    this.monacoLoaderService.isMonacoLoaded$.pipe(
      filter(isLoaded => isLoaded),
      take(1),
    ).subscribe(() => {
      this.registerLanguage();
      this.registerTheme();
    });
  }

  ngOnInit(): void {
    this.addMenuBehavior();

    this.addSubscription(this.fileService.executablePath$
      .subscribe(console.log));
  }

  addMenuBehavior(): void {
    this.addSubscription(this.menuService.saveAction$
      .pipe(
        concatMap(() => this.fileService.save$(this.code))
      )
      .subscribe());


    this.addSubscription(this.menuService.openAction$
      .pipe(
        concatMap(() => this.fileService.open$())
      )
      .subscribe((result) => this.editor.writeValue(result)));


    this.addSubscription(this.menuService.buildAction$
      .pipe(
        concatMap(() => this.fileService.save$(this.code)),
        filter(() => this.fileService.executableIsDefined),
        concatMap((filePath) => this.fileService.execute$(filePath))
      )
      .subscribe());


    this.addSubscription(this.menuService.setExecutableAction$
      .pipe(
        concatMap(() => this.fileService.setExecutable$())
      )
      .subscribe());

    // this.addSubscription(this.menuService.newAction$
    //   .pipe(
    //     concatMap(() => {
    //       this.fileService.
    //       this.fileService.confirmToCloseWithoutSaving$()
    //     }),
    //   )
    //   .subscribe());
  }

  registerTheme(): void {
    monaco.editor.defineTheme("cp2Theme", customTheme.default);
  }

  registerLanguage(): void {
    monaco.languages.register({ id: "cp2" });
    monaco.languages.setLanguageConfiguration("cp2", configuration.default);
    monaco.languages.setMonarchTokensProvider("cp2", this.generateTokenList());
  }

  /** Temporário */
  keydownEvent() {
    this.fileService.setStateToNotSaved();
  }

  private generateTokenList(): any {
    return {
      tokenizer: {
        root: [
          ...(tokens.default as Array<any>).map(token => [new RegExp(token.regex, "g"), token.name]),
          [/\/\*/, "blockComment", "@comment"]
        ],
        comment: [
          [/\*\//, "blockComment", "@pop"],
          [/./, "blockComment.content"],
        ],
      }
    };
  }
}
