import { Injectable } from "@angular/core";

@Injectable({ providedIn: "root" })
export class ElectronService {

  private electron: any;

  constructor() {
    if (this.isElectron) {
      // @ts-ignore
      this.electron = window.electron;
    }
  }

  get isElectron(): boolean {
    const userAgent = navigator.userAgent.toLocaleLowerCase();
    return userAgent.indexOf(" electron/") > -1;
  }

  dialog(method: string, config: any): any {
    return this.electron.dialog(method, config);
  }

  childProcess(method: string, ...args: any): any {
    return this.electron.childProcess(method, ...args);
  }

  fs(method: string, ...args: any): any {
    return this.electron.fs(method, ...args);
  }
}
