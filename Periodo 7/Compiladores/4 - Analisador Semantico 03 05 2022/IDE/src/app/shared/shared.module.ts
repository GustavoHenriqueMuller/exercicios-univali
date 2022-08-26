import { NgModule } from "@angular/core";
import { CommonModule } from "@angular/common";

import { TranslateModule } from "@ngx-translate/core";

import {
  FileViewComponent,
  IconComponent,
  MenuComponent,
  PageNotFoundComponent,
  TerminalComponent
} from "./components/";
import { WebviewDirective } from "./directives/";
import { FormsModule, ReactiveFormsModule } from "@angular/forms";
import { MonacoEditorModule } from "@materia-ui/ngx-monaco-editor";
import { ModalComponent } from "./components/modal/modal.component";
import { SymbolTableComponent } from "./components/symbol-table/symbol-table.component";

@NgModule({
  declarations: [
    PageNotFoundComponent, WebviewDirective, MenuComponent, FileViewComponent, TerminalComponent, IconComponent, ModalComponent,
    SymbolTableComponent
  ],
    imports: [CommonModule, TranslateModule, FormsModule, ReactiveFormsModule, MonacoEditorModule],
  exports: [TranslateModule, WebviewDirective, FormsModule, MenuComponent, FileViewComponent, TerminalComponent, SymbolTableComponent]
})
export class SharedModule {}
