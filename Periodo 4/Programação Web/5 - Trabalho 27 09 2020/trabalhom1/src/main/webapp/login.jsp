<%-- 
    Document   : login
    Created on : 25/09/2020, 10:40:02
    Author     : Gustavo
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>Login</title>
    </head>
    <body>
        <h1>Login</h1>
        <p>Usar usuário "gustavo" e senha "oi"</p>
        
        <form action="Login" method="post">
            <label for="usuario">Usuário: </label>
            <input name="usuario" type="text"/><br>
            
            <label for="senha">Senha: </label>
            <input name="senha" type="password"/><br>
            
            <label for="manterConectado">Manter Conectado: </label>
            <input name="manterConectado" type="checkbox"/><br>
            
            <input type="submit"/>
        </form>
    </body>
</html>
