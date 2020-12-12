package Servlets;

import java.io.IOException;
import Classes.Register;
import com.google.gson.Gson;
import java.io.PrintWriter;
import java.util.stream.Collectors;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 *
 * @author Gustavo
 */
public class RegisterValidate extends HttpServlet {
    private boolean isNumeric(String strNum) {
        if (strNum == null) {
            return false;
        }
        
        try {
            double d = Double.parseDouble(strNum);
        } catch (NumberFormatException nfe) {
            return false;
        }
        
        return true;
    }
    
    protected void processRequest(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        String json = request.getReader().lines().collect(Collectors.joining(System.lineSeparator()));
        Gson gsonDecoder = new Gson();
        Register register = gsonDecoder.fromJson(json, Register.class);
        
        if(register.name.equals("") || register.CPF.equals("") || register.email.equals("") || register.CEP.equals("") ||
                register.addressNumber.equals("") || register.addressComplement.equals("") || register.debtValue.equals("") ||
                register.debtObject.equals("") || register.debtSituation.equals("") || register.processNumber.equals("")) {
            
            response.setStatus(406);
            return;
        }
        
        if(!isNumeric(register.CPF) || !isNumeric(register.CEP) || !isNumeric(register.addressNumber) ||
                !isNumeric(register.debtValue) || !isNumeric(register.processNumber)) {
            
            response.setStatus(406);
            return;
        }
        
        PrintWriter writer = new PrintWriter(register.name + ".json", "UTF-8");
        writer.println(json);
        writer.close();
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        processRequest(request, response);
    }
}
