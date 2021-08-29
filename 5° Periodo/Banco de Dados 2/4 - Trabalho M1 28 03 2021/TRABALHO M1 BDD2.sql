/***************************************************************************
				INÍCIO: QUESTÃO 1
***************************************************************************/

CREATE TABLE Estado (
	id SERIAL,
	nome VARCHAR(100),
	uf VARCHAR(2),
	
	PRIMARY KEY (id)
);

CREATE TABLE Cidade (
	id SERIAL,
	id_estado INT,
	
	nome VARCHAR(100),
	
	PRIMARY KEY (id),
	FOREIGN KEY (id_estado) REFERENCES Estado(id)
);

CREATE TABLE Mae (
	id SERIAL,
	id_cidade INT,
	
	nome VARCHAR(100),
	logradouro VARCHAR(200),
	numero INT,
	bairro VARCHAR(60),
	cep VARCHAR(9),
	fixo VARCHAR(14),
	celular VARCHAR(15),
	data_nascimento DATE,
	
	PRIMARY KEY (id),
	FOREIGN KEY (id_cidade) REFERENCES Cidade(id)
);

CREATE TABLE Especialidade (
	id SERIAL,
	nome VARCHAR(100),
	
	PRIMARY KEY(id)
);

CREATE TABLE Medico (
	crm SERIAL,
	id_especialidade INT,
	id_cidade INT,
	
	nome VARCHAR(100),
	logradouro VARCHAR(200),
	numero INT,
	bairro VARCHAR(60),
	cep VARCHAR(9),
	celular VARCHAR(15),
	fixo VARCHAR(14),
	salario DECIMAL (10,2),
	status SMALLINT,
	
	PRIMARY KEY (crm),
	FOREIGN KEY (id_especialidade) REFERENCES Especialidade(id),
	FOREIGN KEY (id_cidade) REFERENCES Cidade(id)
);

CREATE TABLE Nascimento (
	id SERIAL,
	id_mae INT,
	crm_medico INT,
	
	nome VARCHAR(100),
	data_nascimento DATE,
	peso DECIMAL(5,3),
	altura SMALLINT,
	sexo SMALLINT,
	
	PRIMARY KEY (id),
	FOREIGN KEY (id_mae) REFERENCES Mae(id),
	FOREIGN KEY (crm_medico) REFERENCES Medico(crm)
);

CREATE TABLE Agendamento (
	id SERIAL,
	id_nascimento INT,
	
	inicio TIMESTAMP,
	fim TIMESTAMP,
	
	PRIMARY KEY (id),
	FOREIGN KEY (id_nascimento) REFERENCES Nascimento(id)
);

/***************************************************************************
				FIM: QUESTÃO 1
***************************************************************************/
/***************************************************************************
				INÍCIO: QUESTÃO 2
***************************************************************************/

INSERT INTO Estado (nome, uf) VALUES ('Santa Catarina', '42'), ('Rio Grande do Sul', '43'), ('Paraná', '41');
INSERT INTO Cidade (id_estado, nome) VALUES (1, 'Balneário Camboriú'), (2, 'Porto Alegre'), (3, 'Curitiba');
INSERT INTO Mae (id_cidade, nome, logradouro, numero, bairro, cep, fixo, celular, data_nascimento) VALUES
			(1, 'ABC', 'Casa 1', 25, 'Centro', '123456789', '11111111111111', '111111111111111', '1960-05-23'),
			(1, 'XYZ', 'Casa 2', 40, 'Algum bairro', '123456789', '22222222222222', '222222222222222', '1980-01-02'),
			(2, 'FGH', 'Casa 3', 8, 'Sei lá', '123456789', '33333333333333', '333333333333333', '1995-10-18');
INSERT INTO Especialidade(nome) VALUES ('Dermatologia'), ('Cardiologia'), ('Neurocirurgia');
INSERT INTO Medico(id_especialidade, id_cidade, nome, logradouro, numero, bairro, cep, fixo, celular, salario, status) VALUES
			(2, 2, 'Médico 1', 'Algum lugar', 10, 'Centro', '123456789', '11111111111111', '111111111111111', 8000, 1),
			(1, 2, 'Médico 2', 'Uma casa', 55, 'Centro', '123456789', '22222222222222', '222222222222222', 6000, 0),
			(3, 1, 'Médico 3', 'Um apartamento', 92, 'Algum bairro', '123456789', '33333333333333', '333333333333333', 12000, 1);
INSERT INTO Nascimento(id_mae, crm_medico, nome, data_nascimento, peso, altura, sexo) VALUES
			(3, 2, 'Gustavo', '2002-02-20', 0.5, 0.25, 0),
			(1, 3, 'Carla', '2001-04-17', 0.4, 0.3, 1),
			(2, 1, 'Otávio', '2021-04-12', 0.6, 0.35, 0);
INSERT INTO Agendamento(id_nascimento, inicio, fim) VALUES
			(1, '2002-02-20 10:23:54', '2002-02-20 10:23:54'),
			(2, '2001-04-17 10:23:54', '2001-04-17 10:23:54'),
			(3, '1999-11-09 10:23:54', '1999-11-09 10:23:54');

/***************************************************************************
				FIM: QUESTÃO 2
***************************************************************************/
/***************************************************************************
				INÍCIO: QUESTÃO 3
***************************************************************************/

/*---------------------------
   INÍCIO: QUESTÃO 3.1
---------------------------*/

CREATE OR REPLACE FUNCTION nascimentosNoPeriodo(mes INTEGER, ano INTEGER) RETURNS TABLE(crm INTEGER, nome VARCHAR(100), quantidade BIGINT) AS
$$
	SELECT M.crm, M.nome, COUNT(*) as quantidade
	FROM Nascimento N
	INNER JOIN Medico M ON
	N.crm_medico = M.crm
	WHERE EXTRACT(MONTH FROM N.data_nascimento) = mes AND EXTRACT(YEAR FROM N.data_nascimento) = ano
	GROUP BY M.crm
	ORDER BY COUNT(*) DESC, M.nome ASC;
$$
LANGUAGE SQL;

DROP FUNCTION nascimentosNoPeriodo();

SELECT * FROM Nascimento;
SELECT * FROM Medico;
SELECT * FROM nascimentosNoPeriodo(2, 2002);

/*---------------------------
     FIM: QUESTÃO 3.1
---------------------------*/
/*---------------------------
   INÍCIO: QUESTÃO 3.2
---------------------------*/

CREATE OR REPLACE FUNCTION mediaMaesEmUF(uf_param VARCHAR(2)) RETURNS FLOAT AS
$$
	SELECT AVG(DATE_PART('year', NOW() :: date) - DATE_PART('year', Mae.data_nascimento :: date))
	FROM (Mae INNER JOIN Cidade ON Mae.id_cidade = Cidade.id INNER JOIN Estado ON Cidade.id_estado = Estado.id)
	WHERE Estado.uf = uf_param;
$$
LANGUAGE SQL;

SELECT * FROM Mae;
SELECT mediaMaesEmUF('42');

/*---------------------------
     FIM: QUESTÃO 3.2
---------------------------*/
/*---------------------------
   INÍCIO: QUESTÃO 3.3
---------------------------*/

CREATE OR REPLACE FUNCTION sexoBebesPorMedico(crm_param INTEGER) RETURNS TABLE(sexo SMALLINT, quantidade BIGINT) AS
$$
	SELECT sexo, COUNT(*)
	FROM Nascimento
	WHERE crm_medico = crm_param
	GROUP BY sexo;
$$
LANGUAGE SQL;

-- masculino = 0 e feminino = 1
SELECT * FROM Nascimento;
SELECT * FROM sexoBebesPorMedico(3);

/*---------------------------
     FIM: QUESTÃO 3.3
---------------------------*/
/*---------------------------
   INÍCIO: QUESTÃO 3.4
---------------------------*/

CREATE OR REPLACE PROCEDURE medicoExiste(crm_medico_param INTEGER) AS
$$
	BEGIN
		IF EXISTS(SELECT crm FROM Medico WHERE crm = crm_medico_param) THEN
			-- Médico está inativo; Lançamos uma exceção:
			IF (SELECT status FROM Medico WHERE crm = crm_medico_param) = 0 THEN
				RAISE EXCEPTION 'Médico de CRM % está inativo.', crm_medico_param;
			END IF;			
		ELSE
			-- CRM do médico não existe; Lançamos uma exceção:
			RAISE EXCEPTION 'Não existe nenhum médico de CRM %.', crm_medico_param;
		END IF;
	END;
$$
LANGUAGE plpgsql;

CREATE OR REPLACE PROCEDURE inserirNascimento(id_mae_param INTEGER, crm_medico_param INTEGER, nome_param VARCHAR(100), data_nascimento_param DATE,
	peso_param NUMERIC, altura_param SMALLINT, sexo_param SMALLINT) AS
$$
	BEGIN
		IF NOT EXISTS(SELECT id FROM Mae WHERE id = id_mae_param) THEN
			-- ID da mãe não existe; Lançamos uma exceção:
			RAISE EXCEPTION 'Não existe nenhuma mãe de ID %.', id_mae_param;
		END IF;
		
		-- Essa função lançará exceções caso o médico não exista ou esteja inativo.
		CALL medicoExiste(crm_medico_param);
		
		INSERT INTO Nascimento (id_mae, crm_medico, nome, data_nascimento, peso, altura, sexo) VALUES
		(id_mae_param, crm_medico_param, nome_param, data_nascimento_param, peso_param, altura_param, sexo_param);
	END;
$$
LANGUAGE plpgsql;

SELECT * FROM Nascimento;
SELECT * FROM Mae;
SELECT * FROM Medico;
CALL inserirNascimento(2, 1, 'Mais um bebê' :: VARCHAR(100), '1996-02-20' :: DATE, 0.3 :: NUMERIC, 6 :: SMALLINT, 1 :: SMALLINT);

/*---------------------------
     FIM: QUESTÃO 3.4
---------------------------*/
/*---------------------------
   INÍCIO: QUESTÃO 3.5
---------------------------*/

CREATE OR REPLACE FUNCTION salarioLiquidoMedico(crm_medico_param integer, mes_param integer, ano_param integer) RETURNS NUMERIC(10,2) AS
$$
	DECLARE
		salarioMedico NUMERIC(10, 2);
		idCidadeMedico INTEGER;
		qntNascimentos INTEGER = 0;
		qntNascimentosDeslocados INTEGER = 0;
		linhaAtual RECORD;
	BEGIN
		-- Essa função lançará exceções caso o médico não exista ou esteja inativo.
		CALL medicoExiste(crm_medico_param);
		
		-- Pega o valor padrão do salário do médico.
		SELECT salario INTO salarioMedico FROM Medico WHERE crm = crm_medico_param;
		
		-- Pega a quantidade de nascimentos do médico em um certo período.
		SELECT COUNT(*) INTO qntNascimentos FROM nascimentosNoPeriodo(mes_param, ano_param) WHERE crm = crm_medico_param;
		
		-- Adiciona o valor por quantidade de nascimentos.
		salarioMedico := salarioMedico + 4000 * qntNascimentos;
		
		-- Pega o id_cidade do médico.
		SELECT id_cidade INTO idCidadeMedico FROM Medico WHERE crm = crm_medico_param;
		
		-- Calcula quantos nascimentos foram em cidades diferentes.
		FOR linhaAtual IN (SELECT id_cidade FROM (Nascimento INNER JOIN Mae ON id_mae = Mae.id)
			WHERE crm_medico = crm_medico_param AND
			EXTRACT(MONTH FROM Nascimento.data_nascimento) = mes_param AND
			EXTRACT(YEAR FROM Nascimento.data_nascimento) = ano_param)
			LOOP			
			
			IF linhaAtual.id_cidade != idCidadeMedico THEN
				qntNascimentosDeslocados := qntNascimentosDeslocados + 1;
			END IF;
		END LOOP;
		
		-- Retira do salário do médico os custos de transporte por nascimento deslocado.
		salarioMedico := salarioMedico - 500 * qntNascimentosDeslocados;
		
		return salarioMedico;
	END;
$$
LANGUAGE plpgsql;

SELECT * FROM Mae;
SELECT * FROM Nascimento;
SELECT * FROM Medico;
SELECT * FROM nascimentosNoPeriodo(2, 2002);
SELECT * FROM salarioLiquidoMedico(3, 2, 2002);

/***************************************************************************
				FIM: QUESTÃO 3
***************************************************************************/
/***************************************************************************
				INÍCIO: QUESTÃO 4
***************************************************************************/

/*---------------------------
   INÍCIO: QUESTÃO 4.1
---------------------------*/

CREATE OR REPLACE FUNCTION aoInserirNascimento() RETURNS TRIGGER AS
$$
	BEGIN
		-- Se o médico desse CRM estiver inativo ou não existir, exceções serão lançadas.
		CALL medicoExiste(NEW.crm_medico);
		
		RETURN NEW;
	END;
$$
LANGUAGE plpgsql;

SELECT * FROM Nascimento;
CREATE TRIGGER triggerAoInserirNascimento BEFORE INSERT ON Nascimento
FOR EACH ROW EXECUTE PROCEDURE aoInserirNascimento();

/*---------------------------
     FIM: QUESTÃO 4.1
---------------------------*/
/*---------------------------
   INÍCIO: QUESTÃO 4.2
---------------------------*/

CREATE OR REPLACE FUNCTION aoAtualizarMedico() RETURNS TRIGGER AS
$$
	DECLARE
		qntNascimentos INTEGER;
	BEGIN
		-- Checa se o ID passou de 0 para 1 (inativo para ativo).
		IF NEW.status = 0 AND OLD.status = 1 THEN
			-- Pega a quantidade de nascimentos que foram feitos no mês atual.
			SELECT COUNT(*) INTO qntNascimentos FROM Nascimento
			WHERE crm_medico = OLD.crm AND
			EXTRACT(MONTH FROM data_nascimento) = EXTRACT(MONTH FROM NOW()) AND
			EXTRACT(YEAR FROM data_nascimento) = EXTRACT(YEAR FROM NOW());
			
			IF qntNascimentos > 0 THEN
				RAISE EXCEPTION 'Médico de CRM % fez/fará um nascimento nesse mês.', OLD.crm;
			END IF;
		END IF;
		
		RETURN NEW;
	END;
$$
LANGUAGE plpgsql;

SELECT * FROM Medico;
SELECT * FROM Nascimento;
CREATE TRIGGER triggerAoAtualizarMedico BEFORE UPDATE ON Medico
FOR EACH ROW EXECUTE PROCEDURE aoAtualizarMedico();

UPDATE Medico SET status = 0 WHERE crm = 1;

/*---------------------------
     FIM: QUESTÃO 4.2
---------------------------*/
/*---------------------------
   INÍCIO: QUESTÃO 4.3
---------------------------*/

CREATE OR REPLACE FUNCTION aoAtualizarSalarioMedico() RETURNS TRIGGER AS
$$
	BEGIN
		IF NEW.salario > OLD.salario * 1.5 THEN
			RAISE EXCEPTION 'Salário novo (% R$) do médico de CRM % excede em 1.5x o seu salário original (% R$).', NEW.salario, OLD.crm, OLD.salario;
		ELSEIF NEW.salario < OLD.salario * 0.5 THEN
			RAISE EXCEPTION 'Salário novo (% R$) do médico de CRM % é menor do que metade do seu salário original (% R$).', NEW.salario, OLD.crm, OLD.salario;
		END IF;
		
		RETURN NEW;
	END;
$$
LANGUAGE plpgsql;

CREATE TRIGGER triggerAoAtualizarSalarioMedico BEFORE UPDATE ON Medico
FOR EACH ROW EXECUTE PROCEDURE aoAtualizarSalarioMedico();

SELECT * FROM Medico;
UPDATE Medico SET salario = 13000 WHERE crm = 1; -- Muito alto
UPDATE Medico SET salario = 3000 WHERE crm = 1; -- Muito baixo

/*---------------------------
     FIM: QUESTÃO 4.3
---------------------------*/
/*---------------------------
   INÍCIO: QUESTÃO 4.4
---------------------------*/

CREATE OR REPLACE FUNCTION aoAtualizarNascimento() RETURNS TRIGGER AS
$$
	DECLARE
		propriedade VARCHAR;
	BEGIN	
		IF NEW.nome IS NULL OR NEW.nome = '' THEN
			propriedade := 'nome';
		ELSEIF NEW.data_nascimento IS NULL THEN
			propriedade := 'data de nascimento';
		ELSEIF NEW.peso IS NULL OR NEW.peso = 0 THEN
			propriedade := 'peso';
		ELSEIF NEW.altura IS NULL OR NEW.altura = 0 THEN
			propriedade := 'altura';
		ELSEIF NEW.sexo IS NULL THEN
			propriedade := 'sexo';
		END IF;		
	
		IF propriedade != '' THEN
			RAISE EXCEPTION 'Propriedade "%" é nula ou vazia.', propriedade;
		END IF;
		
		RETURN NEW;
	END;
$$
LANGUAGE plpgsql;

CREATE TRIGGER triggerAoAtualizarNascimento BEFORE UPDATE ON Nascimento
FOR EACH ROW EXECUTE PROCEDURE aoAtualizarNascimento();

SELECT * FROM Nascimento;
UPDATE Nascimento SET nome = '' WHERE id = 1; -- nome vazio
UPDATE Nascimento SET nome = 'Algum nome aleatório', peso = 0 WHERE id = 1; -- peso vazio

/*---------------------------
     FIM: QUESTÃO 4.4
---------------------------*/
/*---------------------------
   INÍCIO: QUESTÃO 4.5
---------------------------*/

CREATE OR REPLACE FUNCTION aoAgendar() RETURNS TRIGGER AS
$$
	DECLARE
		inicio TIME;
		fim TIME;
		diaDaSemana VARCHAR;
	BEGIN
		inicio := CAST(NEW.inicio AS TIME);
		fim := CAST(NEW.fim AS TIME);
		diaDaSemana := to_char(NEW.inicio, 'Day');		
	
		IF diaDaSemana = 'Saturday ' OR diaDaSemana = 'Sunday ' THEN
			-- Não há expediente nos fins de semana (sábado e domingo).
			RAISE EXCEPTION 'Não é possível fazer um agendamento no dia/horário "%", pois está num fim de semana.', New.inicio;
			
		ELSEIF NOT ((inicio >= '8:00:00' AND inicio < '12:00:00') AND (fim > '8:00:00' AND fim <= '12:00:00')) AND
			   NOT ((inicio >= '13:30:00' AND inicio < '17:30:00') AND (fim > '13:30:00' AND fim <= '17:30:00')) THEN
			   
			-- Horário inválido.
			RAISE EXCEPTION 'Horário que começa as % e termina as % é inválido.', inicio, fim;
		END IF;		
		
		RETURN NEW;
	END;
$$
LANGUAGE plpgsql;

CREATE TRIGGER triggerAoAgendar BEFORE UPDATE OR INSERT ON Agendamento
FOR EACH ROW EXECUTE PROCEDURE aoAgendar();

SELECT * FROM Agendamento;
INSERT INTO Agendamento (id_nascimento, inicio, fim) VALUES (1, '2002-02-20 07:30:54', '2002-02-20 8:30:00'); -- Começa muito cedo.
INSERT INTO Agendamento (id_nascimento, inicio, fim) VALUES (1, '2002-02-20 08:30:00', '2002-02-20 14:00:00'); -- Termina muito tarde.
INSERT INTO Agendamento (id_nascimento, inicio, fim) VALUES (1, '2002-02-23 08:30:00', '2002-02-23 11:00:00'); -- Em fim de semana.
INSERT INTO Agendamento (id_nascimento, inicio, fim) VALUES (1, '2002-02-20 08:30:00', '2002-02-20 9:30:00'); -- Correto.
/*---------------------------
     FIM: QUESTÃO 4.5
---------------------------*/