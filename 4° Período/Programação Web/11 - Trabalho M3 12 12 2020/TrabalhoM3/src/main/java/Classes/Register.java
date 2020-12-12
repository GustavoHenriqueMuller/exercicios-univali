package Classes;

/**
 *
 * @author Gustavo
 */
public class Register {
    public String name;
    public String CPF;
    public String email;
    public String CEP;
    public String addressNumber;
    public String addressComplement;
    public String debtValue;
    public String debtObject;
    public String debtSituation;
    public String processNumber;

    public Register(String name, String CPF, String email, String CEP, String addressNumber,
            String addressComplement, String debtValue, String debtObject, String debtSituation, String processNumber) {
        this.name = name;
        this.CPF = CPF;
        this.email = email;
        this.CEP = CEP;
        this.addressNumber = addressNumber;
        this.addressComplement = addressComplement;
        this.debtValue = debtValue;
        this.debtObject = debtObject;
        this.debtSituation = debtSituation;
        this.processNumber = processNumber;
    }
}
