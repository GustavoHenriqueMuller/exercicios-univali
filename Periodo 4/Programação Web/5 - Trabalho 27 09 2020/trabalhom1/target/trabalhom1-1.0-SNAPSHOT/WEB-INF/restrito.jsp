<%-- 
    Document   : restrito
    Created on : 25/09/2020, 10:56:19
    Author     : Gustavo
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>Restrito</title>
    </head>
    <body>
        <h1>Página Restrita</h1>
        
        <% 
           out.println("Olá, " + request.getAttribute("usuario"));
        %>
        
        <form action="Logout">
            <button type="submit">Logout</button>
        </form>        
    </body>
</html>
