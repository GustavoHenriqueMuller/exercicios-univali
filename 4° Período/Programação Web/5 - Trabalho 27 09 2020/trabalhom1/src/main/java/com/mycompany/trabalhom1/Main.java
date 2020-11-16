/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.mycompany.trabalhom1;

import java.io.IOException;
import java.io.PrintWriter;
import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.http.Cookie;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 *
 * @author Gustavo
 */
public class Main extends HttpServlet {
    
    private boolean isManterConectado(HttpServletRequest request) {
        Cookie cookies[] = request.getCookies();
        
        for(Cookie cookie : cookies){
            if(cookie.getName().equals("manterConectado") && cookie.getValue().equals("true")) {
                return true;
            }
        }
        
        return false;
    }
    
    private String getCookie(HttpServletRequest request, String cookieName) {
        Cookie cookies[] = request.getCookies();
        
        for(Cookie cookie : cookies){
            if(cookie.getName().equals(cookieName)) {
                return cookie.getValue();
            }
        }
        
        return "";
    }

    protected void processRequest(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        if(getCookie(request, "manterConectado").equals("true")) {
            request.setAttribute("usuario", getCookie(request, "usuario"));            
           
            RequestDispatcher dispatcher = getServletContext().getRequestDispatcher("/WEB-INF/restrito.jsp");
            dispatcher.forward(request, response);
        } else {
            response.sendRedirect(request.getContextPath() + "/login.jsp");
        }
    }

    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        processRequest(request, response);
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        processRequest(request, response);
    }
}
