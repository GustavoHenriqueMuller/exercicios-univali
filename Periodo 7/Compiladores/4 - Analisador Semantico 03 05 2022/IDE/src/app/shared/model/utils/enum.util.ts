export class EnumUtil {

  /**
   * Exporta os valores da enum para um array de um tipo especificado.
   *
   * @param classEnum Enum
   */
  public static arrayValues<EnumObject>(classEnum: any): Array<EnumObject> {
    return Object.values(classEnum).filter(value => typeof value === "object").map(value => value as EnumObject);
  }

  /**
   * Exporta um valor da enum para um objeto de um tipo especificado.
   *
   * @param objectEnum Objeto pertencente à enum.
   */
  public static getEnumValue<EnumObject>(objectEnum: any): EnumObject {
    return objectEnum as EnumObject;
  }

  /**
   * Exporta um valor da enum para um objeto utilizando o identificador.
   *
   * @param key identificador do valor pertencente a enum.
   * @param classEnum Enum
   */
  public static getEnumValueByKey(key: string, classEnum: any): any {
    const targetKey = Object.keys(classEnum).find(value => value.toLowerCase() === key.toLowerCase());
    return targetKey ? classEnum[targetKey] : undefined;
  }
}
