CREATE DATABASE solnascente;
USE solnascente;

/* TABELAS PARA PESSOAS */
CREATE TABLE Pessoa(
	idPessoa INT NOT NULL AUTO_INCREMENT,
    nome VARCHAR(100) NOT NULL,
    cpf CHAR(11) NOT NULL,
    dataNascimento DATE NOT NULL,
    
    PRIMARY KEY(idPessoa)
);

CREATE TABLE Funcionario(
	idFuncionario INT NOT NULL AUTO_INCREMENT,
    idPessoa_FK INT NOT NULL,
    
    PRIMARY KEY(idFuncionario, idPessoa_FK),
    CONSTRAINT FK_FUNCIONARIO_PESSOA
    FOREIGN KEY(idPessoa_FK) REFERENCES Pessoa(idPessoa)
);

CREATE TABLE Porteiro(
	idPorteiro INT NOT NULL AUTO_INCREMENT,
    idFuncionario_FK INT NOT NULL,
    
    PRIMARY KEY(idPorteiro, idFuncionario_FK),
    CONSTRAINT FK_PORTEIRO_FUNCIONARIO
    FOREIGN KEY(idFuncionario_FK) REFERENCES Funcionario(idFuncionario)    
);

CREATE TABLE Zelador(
	idZelador INT NOT NULL AUTO_INCREMENT,
    idFuncionario_FK INT NOT NULL,

	PRIMARY KEY(idZelador, idFuncionario_FK),
    CONSTRAINT FK_ZELADOR_FUNCIONARIO
    FOREIGN KEY(idFuncionario_FK) REFERENCES Funcionario(idFuncionario)
);

CREATE TABLE Condomino(
	idCondomino INT NOT NULL AUTO_INCREMENT,
    idPessoa_FK INT NOT NULL,
    ap CHAR(4) NOT NULL,

	PRIMARY KEY(idCondomino, idPessoa_FK),
    CONSTRAINT FK_CONDOMINO_PESSOA
    FOREIGN KEY(idPessoa_FK) REFERENCES Pessoa(idPessoa)
);

CREATE TABLE Sindico(
	idSindico INT NOT NULL AUTO_INCREMENT,
    idCondomino_FK INT NOT NULL,

	PRIMARY KEY(idSindico, idCondomino_FK),
    CONSTRAINT FK_SINDICO_CONDOMINO 
    FOREIGN KEY(idCondomino_FK) REFERENCES Condomino(idCondomino)
);

CREATE TABLE Subsindico(
	idSubsindico INT NOT NULL AUTO_INCREMENT,
    idCondomino_FK INT NOT NULL,

	PRIMARY KEY(idSubsindico, idCondomino_FK),
    CONSTRAINT FK_SUBSINDICO_CONDOMINO 
    FOREIGN KEY(idCondomino_FK) REFERENCES Condomino(idCondomino)
);

/* OUTRAS TABELAS */
CREATE TABLE AchadosPerdidos(
	idAchadosPerdidos INT NOT NULL AUTO_INCREMENT,
    idZelador_FK INT NOT NULL,
    item VARCHAR(30) NOT NULL,
    descricao TINYTEXT NOT NULL,
    localAchado VARCHAR(100) NOT NULL,

	PRIMARY KEY(idAchadosPerdidos, idZelador_FK),
    CONSTRAINT FK_ACHADOSPERDIDOS_ZELADOR
    FOREIGN KEY(idZelador_FK) REFERENCES Zelador(idZelador)
);

CREATE TABLE Telefone(
	idTelefone INT NOT NULL AUTO_INCREMENT,
    idPessoa_FK INT NOT NULL,
    ddd CHAR(2) NOT NULL,
    numero VARCHAR(10) NOT NULL,

	PRIMARY KEY(idTelefone, idPessoa_FK),
    CONSTRAINT FK_TELEFONE_PESSOA 
    FOREIGN KEY(idPessoa_FK) REFERENCES Pessoa(idPessoa)
);

CREATE TABLE Ocorrencia(
	idOcorrencia INT NOT NULL AUTO_INCREMENT,
    idPessoa_FK INT NOT NULL,
    titulo VARCHAR(30) NOT NULL,
    descricao TINYTEXT,
    dataOcorrido DATE NOT NULL,
    horarioOcorrido TIME NOT NULL,

	PRIMARY KEY(idOcorrencia, idPessoa_FK),
    CONSTRAINT FK_OCORRENCIA_PESSOA
    FOREIGN KEY(idPessoa_FK) REFERENCES Pessoa(idPessoa)
);

CREATE TABLE Lugar(
	idLugar INT NOT NULL AUTO_INCREMENT,
    nome VARCHAR(60) NOT NULL,
    
    PRIMARY KEY(idLugar)
);

CREATE TABLE Reserva(
	idReserva INT NOT NULL AUTO_INCREMENT,
    idPessoa_FK INT NOT NULL,
    idLugar_FK INT NOT NULL,
    dataReserva DATE NOT NULL,

	PRIMARY KEY(idReserva, idPessoa_FK, idLugar_FK),

    CONSTRAINT FK_RESERVA_PESSOA
    FOREIGN KEY(idPessoa_FK) REFERENCES Pessoa(idPessoa),
    
    CONSTRAINT FK_RESERVA_LUGAR
    FOREIGN KEY(idLugar_FK) REFERENCES Lugar(idLugar)
);

/* FUNÇÕES */
DELIMITER $$

CREATE PROCEDURE DeletePessoaAndDependencies(IN idToDelete INT)
BEGIN
	UPDATE AchadosPerdidos SET idZelador_FK = NULL WHERE idZelador_FK = idToDelete;
    UPDATE Ocorrencia SET idPessoa_FK = NULL WHERE idPessoa_FK = idToDelete;
    UPDATE Reserva SET idPessoa_FK = NULL WHERE idPessoa_FK = idToDelete;
	DELETE FROM Zelador WHERE idFuncionario_FK = idToDelete;
	DELETE FROM Porteiro WHERE idFuncionario_FK = idToDelete;
	DELETE FROM Funcionario WHERE idPessoa_FK = idToDelete;
	DELETE FROM Subsindico WHERE idCondomino_FK = idToDelete;
	DELETE FROM Sindico WHERE idCondomino_FK = idToDelete;
	DELETE FROM Condomino WHERE idPessoa_FK = idToDelete;
    DELETE FROM Telefone WHERE idPessoa_FK = idToDelete;
	DELETE FROM Pessoa WHERE idPessoa = idToDelete;
END $$
DELIMITER ;

/* COMANDOS SQL PARA CADA TABELA */
-- PESSOA
INSERT INTO Pessoa(nome, cpf, dataNascimento) VALUES
("Gustavo Henrique Stahl Müller", "10067916988", "2002/02/20"),
("Paulo Henrique Rohling", "12345678911", "2001/07/14"),
("Gabriela Hang Busquirolli", "65412378952", "2003/12/22"),
("John Doe", "11987654321", "1970/05/23"),
("Phil Collins", "37593017481", "1866/01/08"),

("Bjarne Stroustrup", "49265981284", "1872/11/23"),
("Rodrigo Lyra", "15478932565", "2003/12/22"),
("Lucas Debatin", "12395865421", "1995/01/20"),
("Eduardo Alves", "45124536500", "1990/07/19"),
("Carlos Bughi", "14785236985", "1985/05/14"),

("José da Silva", "65412378952", "2003/12/22"),
("Paulo de Souza", "48625412042", "2000/04/12"),
("Henrique Damasceno", "63517845695", "1960/01/01"),
("Leonardo Pinto", "14532632512", "1999/02/27"),
("Márcio Klabunde", "37845995666", "1977/02/28"),

("Antonio Nunes", "14839187231", "1400/04/08"),
("Giorno Giovanna", "54927384610", "1992/11/27");

UPDATE Pessoa SET nome = "Bjarne Stroustroup" WHERE idPessoa = 5;
UPDATE Pessoa SET nome = "John Epic" WHERE idPessoa = 3;

CALL DeletePessoaAndDependencies(1);
CALL DeletePessoaAndDependencies(2);
CALL DeletePessoaAndDependencies(3);

-- CONDOMINO
INSERT INTO Condomino(idPessoa_FK, ap) VALUES
(1, "101"),
(2, "102"),
(3, "201"),
(4, "202"),
(5, "301"),
(6, "302"),
(7, "401"),
(8, "402"),
(9, "501"),
(10, "502"),
(11, "601"),
(12, "602"),
(13, "701"),
(14, "702"),
(15, "801");

UPDATE Condomino SET ap = "4101" WHERE idCondomino = 1;
UPDATE Condomino SET ap = "8104" WHERE idCondomino = 3;

CALL DeletePessoaAndDependencies(1);
CALL DeletePessoaAndDependencies(2);
CALL DeletePessoaAndDependencies(3);

-- SINDICO
INSERT INTO Sindico(idCondomino_FK) VALUES
(1), (2), (3), (4), (5);

UPDATE Sindico SET idCondomino_FK = 1 WHERE idSindico = 2;
UPDATE Sindico SET idCondomino_FK = 2 WHERE idSindico = 1;

CALL DeletePessoaAndDependencies(1);
CALL DeletePessoaAndDependencies(2);
CALL DeletePessoaAndDependencies(3);

-- SUBSINDICO
INSERT INTO Subsindico(idCondomino_FK) VALUES
(6), (7), (8), (9), (10);

UPDATE Subsindico SET idCondomino_FK = 1 WHERE idSubsindico = 2;
UPDATE Subsindico SET idCondomino_FK = 2 WHERE idSubsindico = 1;

CALL DeletePessoaAndDependencies(1);
CALL DeletePessoaAndDependencies(2);
CALL DeletePessoaAndDependencies(3);

-- FUNCIONARIO
INSERT INTO Funcionario(idPessoaFK) VALUES
(6), (7), (8), (9), (10);

UPDATE Funcionario SET idPessoaFK = 1 WHERE idFuncionario = 2;
UPDATE Funcionario SET idPessoaFK = 2 WHERE idFuncionario = 1;

CALL DeletePessoaAndDependencies(1);
CALL DeletePessoaAndDependencies(2);
CALL DeletePessoaAndDependencies(3);

-- PORTEIRO
INSERT INTO Porteiro(idFuncionario_FK) VALUES
(1), (2), (3), (4), (5);

UPDATE Porteiro SET idFuncionario_FK = 1 WHERE idPorteiro = 2;
UPDATE Porteiro SET idFuncionario_FK = 2 WHERE idPorteiro = 1;

CALL DeletePessoaAndDependencies(1);
CALL DeletePessoaAndDependencies(2);
CALL DeletePessoaAndDependencies(3);

-- ZELADOR
INSERT INTO Zelador(idFuncionario_FK) VALUES
(2), (3), (4), (5), (6);

UPDATE Zelador SET idFuncionario_FK = 1 WHERE idZelador = 2;
UPDATE Zelador SET idFuncionario_FK = 2 WHERE idZelador = 1;

CALL DeletePessoaAndDependencies(1);
CALL DeletePessoaAndDependencies(2);
CALL DeletePessoaAndDependencies(3);

-- TELEFONE
INSERT INTO Telefone(idPessoa_FK, ddd, numero) VALUES
(1, "47", "96229480"),
(2, "15", "94557208"),
(3, "39", "99672345"),
(4, "86", "94981017"),
(5, "23", "99456709");

UPDATE Telefone SET ddd = "13" WHERE idTelefone = 2;
UPDATE Telefone SET numero = "1234567891" WHERE idTelefone = 1;

DELETE FROM Telefone WHERE ddd = "47";
DELETE FROM Telefone WHERE numero LIKE "99";
DELETE FROM Telefone WHERE idTelefone = 1;

-- ACHADOS E PERDIDOS
INSERT INTO AchadosPerdidos(idZelador_FK, item, descricao, localAchado) VALUES
(1, "Boné Azul", "Um boné azul de beisebol.", "Banheiro"),
(2, "Ventilador", "Um ventilador.", "Piscina"),
(3, "Teclado", "Um teclado.", "Hall de Entrada"),
(4, "Mouse", "Um mouse.", "Elevador"),
(5, "Monitor", "Um monitor.", "Sala de jogos");

UPDATE AchadosPerdidos SET item = "Almofada" WHERE idAchadosPerdidos = 2;
UPDATE AchadosPerdidos SET descricao = "Uma almofada." WHERE item LIKE "Almofada";

DELETE FROM AchadosPerdidos WHERE item LIKE "Almofada";
DELETE FROM AchadosPerdidos WHERE localAchado LIKE "Hall de Entrada";
DELETE FROM AchadosPerdidos WHERE idAchadosPerdidos = 4;

-- OCORRÊNCIAS
INSERT INTO Ocorrencia(idPessoa_FK, titulo, descricao, dataOcorrido, horarioOcorrido) VALUES
(1, "Elevador preso", "O ELEVADOR ESTÁ PRESO.", "13/08/2020", "20:26"),
(2, "Piscina não-épica", "Piscina tá não-épica.", "21/04/2019", "04:30"),
(3, "Ar-condicionado não funciona", "Alguém arruma o ar-condicionado.", "04/08/2020", "14:30"),
(4, "Banco de dados parou de funcionar", "Alguém chama o DBA!", "04/01/2020", "06:09"),
(5, "Cansei de fazer insert", "Mas tenho que continuar seguindo em frente.", "13/08/2020", "20:28");

UPDATE Ocorrencia SET titulo = "Portão de entrada parou de funcionar" WHERE idOcorrencia = 5;
UPDATE Ocorrencia SET descricao = "Arrumar o mais cedo possível." WHERE idOcorrencia = 5;

DELETE FROM AchadosPerdidos WHERE dataOcorrido LIKE "2020";
DELETE FROM AchadosPerdidos WHERE dataOcorrido LIKE "2019";
DELETE FROM AchadosPerdidos WHERE titulo LIKE "Piscina";

-- RESERVAS
INSERT INTO Reserva(idPessoa_FK, idLugar_FK, dataReserva) VALUES
(5, 1, "27/04/2019"),
(4, 2, "19/12/2020"),
(3, 3, "30/01/2018"),
(2, 4, "04/09/2020"),
(1, 5, "12/10/2020");

UPDATE Reserva SET idLugar_FK = 1 WHERE idReserva = 2;
UPDATE Reserva SET idLugar_FK = 2 WHERE idReserva = 1;

DELETE FROM Reserva WHERE dataOcorrido LIKE "2020";
DELETE FROM Reserva WHERE dataOcorrido LIKE "2019";
DELETE FROM Reserva WHERE idPessoa_FK = 1;

-- LUGAR
INSERT INTO Lugar(nome) VALUES
("Piscina"),
("Salão de Jogos"),
("Hall de entrada"),
("Elevador 1"),
("Elevador 2");

UPDATE Lugar SET nome = "Elevador de Serviço" WHERE idLugar = 5;
UPDATE Lugar SET nome = "Piscina Coberta" WHERE idLugar = 1;

DELETE FROM Lugar WHERE nome LIKE "Elevador";
DELETE FROM Lugar WHERE nome LIKE "Piscina";
DELETE FROM Lugar WHERE idLugar = 2;










