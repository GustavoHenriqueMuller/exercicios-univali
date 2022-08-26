export class ISymbol {
  scope: number;
  name: string;
  type: string;
  isArray: boolean;
  isConst: boolean;
  isRef: boolean;
  isInitialized: boolean;
  isUsed: boolean;
  isInDeclaration: boolean;
  isFunction: boolean;
  parameters: string;

  constructor() {
    this.scope = null;
    this.name = null;
    this.type = null;
    this.isArray = null;
    this.isConst = null;
    this.isRef = null;
    this.isInitialized = null;
    this.isUsed = null;
    this.isInDeclaration = null;
    this.isFunction = null;
    this.parameters = null;
  }
}
