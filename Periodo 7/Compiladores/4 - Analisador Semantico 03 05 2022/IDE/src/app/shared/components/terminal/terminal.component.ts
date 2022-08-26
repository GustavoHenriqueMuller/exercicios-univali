import { ChangeDetectionStrategy, Component, ElementRef, OnInit, ViewChild, ViewEncapsulation } from "@angular/core";
import { FormBuilder, FormGroup } from "@angular/forms";
import { FileService } from "../../../core/services";
import { UnsubscribeDirective } from "../../directives";

@Component({
  changeDetection: ChangeDetectionStrategy.OnPush,
  selector: "app-terminal",
  templateUrl: "./terminal.component.html",
  styleUrls: ["./terminal.component.scss"],
  encapsulation: ViewEncapsulation.None,
})
export class TerminalComponent extends UnsubscribeDirective implements OnInit {

  form: FormGroup;

  @ViewChild("terminal", {static: true}) terminalEditor!: ElementRef;

  constructor(public formBuilder: FormBuilder, public fileService: FileService) {
    super();
    this.form = this.formBuilder.group({ terminal: "" });
  }

  ngOnInit(): void {
    this.form.get("terminal").disable();

    this.addSubscription(this.fileService.consoleMessage$
      .subscribe((message) => {
        this.terminal = message;
        setTimeout(() => {
          this.terminalEditor.nativeElement.scrollTop = this.terminalEditor.nativeElement.scrollHeight;
        });
      }));
  }

  public cleanTerminal(): void {
    this.form.get("terminal").setValue("");
  }

  protected set terminal(value: string) {
    this.form.get("terminal").setValue(`${this.terminal}> ${value}\n`);
  }

  protected get terminal(): string {
    return this.form.getRawValue().terminal;
  }

}
