Na pasta "trabalho6-front-end", execute:

-> "npm install" para instalar as dependências.
-> "npm run" para executar o aplicativo React na porta 3000.

Na pasta "trabalho6-server", execute:

-> "npm install" para instalar as dependências.
-> "nodemon ." para executar a API na porta 8080.

Eu deixei a conexão do MongoDB aberta para qualquer IP, então em teoria
você deve ser capaz de executar a aplicação sem problemas do seu computador.

Caso não dê certo, você deverá:
-> Criar um cluster no MongoDB.
-> Criar uma database chamada "boardData".
-> Dentro da database "boardData", criar duas coleções: "thread" e "post".