<%-- 
    Document   : showCookies
    Created on : 15/09/2020, 16:54:30
    Author     : Gustavo
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@page import="javax.servlet.http.Cookie"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>JSP Page</title>
    </head>
    <body>
        <h1>Show Cookies</h1>
        <% Cookie cookies[] = request.getCookies();
        for(int i = 0; i < cookies.length; i++) {
        %>
            <% out.println(cookies[i].getName()); %>: <% out.println(cookies[i].getValue()); %><br>
        <% } %>
    </body>
</html>
