import { ChangeDetectionStrategy, Component, OnInit } from "@angular/core";

@Component({
  changeDetection: ChangeDetectionStrategy.OnPush,
  selector: "app-modal",
  templateUrl: "./modal.component.html",
  styleUrls: ["./modal.component.scss"]
})
export class ModalComponent implements OnInit {

  constructor() { }

  ngOnInit(): void {
  }

}
