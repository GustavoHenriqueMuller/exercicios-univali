import { ChangeDetectionStrategy, Component, OnInit, ViewEncapsulation } from "@angular/core";
import { ISymbol } from "../../model/domain/Symbol";
import { BehaviorSubject, map } from "rxjs";
import { FileService } from "../../../core/services";
import { UnsubscribeDirective } from "../../directives";

@Component({
  changeDetection: ChangeDetectionStrategy.OnPush,
  selector: "app-symbol-table",
  templateUrl: "./symbol-table.component.html",
  styleUrls: ["./symbol-table.component.scss"],
  encapsulation: ViewEncapsulation.None,
})
export class SymbolTableComponent extends UnsubscribeDirective implements OnInit {

  actualSymbolList$: BehaviorSubject<Array<ISymbol>>;

  constructor(private fileService: FileService) {
    super();
    this.actualSymbolList$ = new BehaviorSubject<Array<ISymbol>>([]);
  }

  ngOnInit(): void {
    this.addSubscription(this.fileService.scopes$
      .pipe(
        map((scopes) =>
          (JSON.parse(scopes) as Array<ISymbol>).sort((a, b) => a.scope - b.scope)
        )
      )
      .subscribe(this.actualSymbolList$));
  }

  get symbolKeys(): any {
    return Object.getOwnPropertyNames(new ISymbol());
  }
}
