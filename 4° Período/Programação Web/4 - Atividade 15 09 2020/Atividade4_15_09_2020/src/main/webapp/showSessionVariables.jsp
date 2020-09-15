<%-- 
    Document   : showSessionVariables
    Created on : 15/09/2020, 17:20:53
    Author     : Gustavo
--%>

<%@page import="java.util.ArrayList"%>
<%@page import="java.util.Collections"%>
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>JSP Page</title>
    </head>
    <body>
        <h1>Show Session Variables</h1>
        <% ArrayList<String> attributes = Collections.list(request.getSession().getAttributeNames());
        for(String attribute : attributes) {
        %>
            <% out.println(attribute); %><br>
        <% } %>
    </body>
</html>
