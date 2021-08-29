package Servlets;

import com.google.gson.Gson;
import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import Classes.User;

/**
 *
 * @author Gustavo
 */
public class Login extends HttpServlet {    
    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        String jwt = request.getHeader("Authorization");
        Gson gsonDecoder = new Gson();
        User user = gsonDecoder.fromJson(jwt, User.class);
        
        if(user != null) {            
            if(!user.username.equals("asd") || !user.password.equals("123")) {
                response.setStatus(401);
            }
        } else {
            response.setStatus (401);
        }
    }
}
