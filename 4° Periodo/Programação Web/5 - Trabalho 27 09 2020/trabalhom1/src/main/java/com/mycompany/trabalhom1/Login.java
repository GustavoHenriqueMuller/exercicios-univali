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
public class Login extends HttpServlet {
    
    private void back(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        response.sendRedirect(request.getContextPath());
    }

    private void gotoRestrito(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        response.setContentType("text/html;charset=UTF-8");
        
        RequestDispatcher dispatcher = getServletContext().getRequestDispatcher("/WEB-INF/restrito.jsp");
        dispatcher.forward(request, response);
    }
    
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        back(request, response);
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        
        String usuario = request.getParameter("usuario");
        String senha = request.getParameter("senha");
        String manterConectado = request.getParameter("manterConectado");
        
        if(usuario.equals("gustavo") && senha.equals("oi")) {
            String cookieValue = (manterConectado == null) ? ("false") : ("true");
            Cookie ck1 = new Cookie("manterConectado", cookieValue);
            Cookie ck2 = new Cookie("usuario", usuario);
            
            response.addCookie(ck1);
            response.addCookie(ck2);
            
            request.setAttribute("usuario", usuario);
            
            gotoRestrito(request, response);
        } else {
            back(request, response);
        }
    }
}
