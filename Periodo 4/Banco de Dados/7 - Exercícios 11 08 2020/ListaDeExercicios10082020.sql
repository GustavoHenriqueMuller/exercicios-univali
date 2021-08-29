-- QUESTÃO 1: "Criar a base de dados “escola” com as seguintes tabelas:"
CREATE SCHEMA escola;
USE escola;

CREATE TABLE aluno(
	id INT PRIMARY KEY NOT NULL AUTO_INCREMENT,
    nome VARCHAR(60)
);

CREATE TABLE disciplina(
	id INT PRIMARY KEY NOT NULL AUTO_INCREMENT,
    nome VARCHAR(60),
    cargaHoraria SMALLINT(3)
);

CREATE TABLE professor(
	id INT PRIMARY KEY NOT NULL AUTO_INCREMENT,
	nome VARCHAR(60)
);

CREATE TABLE turma(
	id INT PRIMARY KEY NOT NULL AUTO_INCREMENT,
    idDisciplina INT NOT NULL,
    CONSTRAINT fkTurmaDisciplina FOREIGN KEY(idDisciplina) REFERENCES disciplina(id),
    idProfessor INT NOT NULL,
    CONSTRAINT fkTurmaProfessor FOREIGN KEY(idProfessor) REFERENCES professor(id),
    ano YEAR
);

CREATE TABLE alunoTurma(
	idAluno INT NOT NULL,
    CONSTRAINT fkAlunoTurmaAluno FOREIGN KEY (idAluno) REFERENCES aluno(id),
    idTurma INT NOT NULL,
    CONSTRAINT fkAlunoTurmaTurma FOREIGN KEY (idTurma) REFERENCES turma(id)
);

-- QUESTÃO 2: "Inserir os registros:"
INSERT INTO aluno(nome) VALUES ("Ana"), ("José"), ("Maria"), ("Beatriz"), ("Pedro"), ("Bruno"), ("Matheus");

INSERT INTO disciplina(nome, cargaHoraria) VALUES ("Banco de Dados", 60),
												  ("POO", 60),
												  ("Algoritmos", 60),
												  ("Estrutura de Dados", 60),
												  ("Engenharia de Software", 60);

INSERT INTO professor(nome) VALUES ("Paulo"), ("Lucas"), ("Alex"), ("Felipe"), ("Beatriz");
INSERT INTO turma(idDisciplina, idProfessor, ano) VALUES (1, 2, 2020), (2, 3, 2020), (3, 1, 2020), (4, 5, 2020), (5, 4, 2020);
INSERT INTO alunoTurma(idAluno, idTurma) VALUES (1, 1), (1, 2), (1, 3), (1, 5), (2, 1), (3, 2), (3, 3), (4, 1), (4, 4), (5,2), (6, 1), (7, 1), (7, 4);

-- QUESTÃO 3: "Criar o SQL das seguintes consultas:"
-- a) Mostre a quantidade de alunos que estão na turma da disciplina de Algoritmos.
SELECT COUNT(aluno.id) FROM aluno, alunoTurma, turma
WHERE aluno.id = alunoTurma.idAluno AND alunoTurma.idTurma = turma.id AND turma.idDisciplina = 3;

-- b) Mostre a quantidade de alunos em cada disciplina (mostrar o nome da disciplina).
SELECT disciplina.nome, COUNT(*) FROM aluno, alunoTurma, turma, disciplina
WHERE aluno.id = alunoTurma.idAluno AND alunoTurma.idTurma = turma.id AND turma.idDisciplina = disciplina.id
GROUP BY disciplina.nome;

-- c) Mostre o nome das disciplinas com o nome dos professores da aluna Ana.
SELECT disciplina.nome, professor.nome FROM aluno, alunoTurma, turma, professor, disciplina
WHERE aluno.nome LIKE "Ana" AND aluno.id = alunoTurma.idAluno AND alunoTurma.idTurma = turma.id AND turma.idProfessor = professor.id AND turma.idDisciplina = disciplina.id;

-- d) Mostre a quantidade de alunos por professor (mostrar o nome do professor).
SELECT professor.nome prof, COUNT(*) qnt FROM aluno, alunoTurma, turma, professor
WHERE aluno.id = alunoTurma.idAluno AND alunoTurma.idTurma = turma.id AND turma.idProfessor = professor.id
GROUP BY professor.nome;

-- e) Mostre o nome de todos os alunos do professor Paulo.
SELECT aluno.nome FROM aluno, alunoTurma, turma, professor
WHERE aluno.id = alunoTurma.idAluno AND alunoTurma.idTurma = turma.id AND turma.idProfessor = professor.id AND professor.nome LIKE "Paulo";

-- f) Mostre qual o nome do aluno que está fazendo o maior número de disciplinas.
SELECT aluno.nome, COUNT(*) qnt FROM aluno, alunoTurma, turma, disciplina
WHERE aluno.id = alunoTurma.idAluno AND alunoTurma.idTurma = turma.id AND turma.idDisciplina = disciplina.id
GROUP BY aluno.nome
ORDER BY COUNT(*) DESC
LIMIT 0, 1;
