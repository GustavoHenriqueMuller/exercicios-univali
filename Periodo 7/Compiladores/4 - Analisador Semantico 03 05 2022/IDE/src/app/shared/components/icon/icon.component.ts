import { ChangeDetectionStrategy, Component, Input, OnInit } from "@angular/core";
import { Icon, IconEnum } from "../../model/enums/icon.enum";
import { EnumUtil } from "../../model/utils/enum.util";

@Component({
  changeDetection: ChangeDetectionStrategy.OnPush,
  selector: "app-icon",
  templateUrl: "./icon.component.html",
  styleUrls: ["./icon.component.scss"],
})
export class IconComponent implements OnInit {

  @Input() public icon: IconEnum | string | undefined;

  @Input() public clazz: string | string[] | Set<string> | { [clazz: string]: any };
  @Input() public alignLeft: boolean;
  @Input() public alignRight: boolean;
  @Input() public container: string | string[] | Set<string> | { [clazz: string]: any };

  public iconValue: Icon;

  constructor() {
    this.icon = IconEnum.FOLDER;
    this.clazz = "text-white";
    this.alignLeft = false;
    this.alignRight = false;
    this.container = [];
    this.iconValue = EnumUtil.getEnumValueByKey("FOLDER", IconEnum);
  }

  ngOnInit(): void {
    if (typeof this.icon === "string") {
      this.icon = this.icon === "" ? IconEnum.FOLDER : EnumUtil.getEnumValueByKey(this.icon, IconEnum);
    }
    this.iconValue = EnumUtil.getEnumValue<Icon>(this.icon);
  }

}
