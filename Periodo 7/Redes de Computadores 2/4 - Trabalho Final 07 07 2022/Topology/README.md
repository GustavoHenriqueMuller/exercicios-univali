# PROJETO DE REDE PARA UMA UNIVERSIDADE

Este trabalho tem como objetivo desenvolver um projeto de rede que atenda às necessidades de uma universidade. 

## Instruções para executar o arquivo .pkt
- Abrir a CLI do roteador backbone;
- Inserir o comando "enable". A senha é "pass";
- Inserir o comando "config";
- Inserir o comando "router bgp 1000";
- Inserir o comando "redistribute ospf 1 match external".

Os passos acima são necessários para possibilitar a comunicação entre os computadores da rede interna e o computador da ISP.
Ele basicamente faz com que o roteador backbone externalize as rotas do OSPF, de forma que a ISP possa se comunicar com os dispositivos da rede.
Entretanto, o Packet Tracer não está salvando esta configuração, de forma que este processo se faz necessário toda vez que a simulação é reaberta.
