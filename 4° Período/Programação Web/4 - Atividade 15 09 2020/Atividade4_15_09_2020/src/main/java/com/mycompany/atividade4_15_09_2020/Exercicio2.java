/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.mycompany.atividade4_15_09_2020;

import java.io.IOException;
import java.io.PrintWriter;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

public class Exercicio2 extends HttpServlet {
    protected void processRequest(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        response.setContentType("text/html;charset=UTF-8");
        
        // Cria um novo atributo
        if(request.getParameter("nome") == "" || request.getParameter("valor") == ""){
            return;
        }
        
        HttpSession s = request.getSession();
        s.setAttribute("nome", request.getParameter("nome"));
        s.setAttribute("valor", request.getParameter("valor"));        
        s.setMaxInactiveInterval(10);
        
        // Redireciona para o mostrador de cookies
        response.sendRedirect(request.getContextPath() + "/showSessionVariables.jsp");
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
