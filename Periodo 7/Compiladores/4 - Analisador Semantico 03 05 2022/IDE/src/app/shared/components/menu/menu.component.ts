import { ChangeDetectionStrategy, Component, OnInit, ViewEncapsulation } from "@angular/core";
import { FileService, MenuService } from "../../../core/services";

@Component({
  changeDetection: ChangeDetectionStrategy.OnPush,
  selector: "app-menu",
  templateUrl: "./menu.component.html",
  styleUrls: ["./menu.component.scss"],
  encapsulation: ViewEncapsulation.None,
})
export class MenuComponent implements OnInit {

  constructor(public menuService: MenuService, public fileService: FileService) { }

  ngOnInit(): void {
  }

}
