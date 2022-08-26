import { Directive } from "@angular/core";
import { UnsubscribeDirective } from "../unsubscribe/unsubscribe.directive";
import { ISelection } from "../../model/interfaces/selection";

@Directive()
export class TextEditorDirective extends UnsubscribeDirective {

  private selection: ISelection;
  private lastValue: string;

  constructor() {
    super();
  }

  protected handleKeydownEvent(event: any) {
    this.selection = this.getSelectionFromEvent(event);
    this.lastValue = "";

    switch (event.key) {
      case "Tab":
        this.tabKeydown(event);
        break;
      case "{":
        this.scopeStartKeydown(event, "{}");
        break;
      case "(":
        this.scopeStartKeydown(event, "()");
        break;
      case "[":
        this.scopeStartKeydown(event, "[]");
        break;
      case "\"":
        this.scopeStartKeydown(event, "\"\"");
        break;
      case "\'":
        this.scopeStartKeydown(event, "\'\'");
        break;
      case "}":
      case ")":
      case "]":
        this.scopeEndKeydown(event);
        break;
      case "Enter":
        this.enterKeydown(event);
        break;
      default:
        break;
    }
  }

  private tabKeydown(event: any): void {
    this.preventEvent(event);
    event.target.value = this.selection.before + "\t" + this.selection.after;
    event.target.selectionStart = event.target.selectionEnd = this.selection.start + 1;
    this.lastValue = event.target.value;
  }

  private scopeStartKeydown(event: any, characters: string): void {
    this.preventEvent(event);
    event.target.value = this.selection.before + characters + this.selection.after;
    event.target.selectionStart = event.target.selectionEnd = this.selection.start + 1;
    this.lastValue = event.target.value;
  }

  private scopeEndKeydown(event: any): void {
    if (this.selection.after.startsWith(event.key)) {
      this.preventEvent(event);
      event.target.selectionStart = event.target.selectionEnd = this.selection.start + 1;
    }
  }

  private enterKeydown(event: any): void {
    if (!event.shiftKey) {
      this.preventEvent(event);

      const tabs = this.getTabsAmountOfCurrentLine();
      const keys = this.selection.before.endsWith("{") && this.selection.after.startsWith("}");
      const parentheses = this.selection.before.endsWith("(") && this.selection.after.startsWith(")");
      const brackets = this.selection.before.endsWith("[") && this.selection.after.startsWith("]");

      if (keys || parentheses || brackets) {
        const indentation = "\n" + "\t".repeat(tabs + 1) + "\n" + "\t".repeat(tabs);
        event.target.value = this.selection.before + indentation + this.selection.after;
        event.target.selectionStart = event.target.selectionEnd = this.selection.start + tabs + 2;
      } else {
        const indentation = "\n" + "\t".repeat(tabs);
        event.target.value = this.selection.before + indentation + this.selection.after;
        event.target.selectionStart = event.target.selectionEnd = this.selection.start + tabs + 1;
      }

      this.lastValue = event.target.value;
    }
  }

  private getTabsAmountOfCurrentLine(): number {
    const linesBefore = this.selection.before.split("\n");
    const actualLine = linesBefore.at(linesBefore.length - 1);

    let count = 0;
    while (actualLine[count] === "\t") {
      count++;
    }

    return count;
  }

  protected preventEvent(event: Event): void {
    event.preventDefault();
    event.stopPropagation();
    event.stopImmediatePropagation();
  }

  protected getSelectionFromEvent(event: any): ISelection {
    return {
      start: event.target.selectionStart,
      end: event.target.selectionEnd,
      value: event.target.value as string,
      before: (event.target.value as string).substring(0, event.target.selectionStart),
      after: (event.target.value as string).substring(event.target.selectionEnd)
    };
  }

  protected get lastEventValue(): string {
    return this.lastValue;
  }

}
