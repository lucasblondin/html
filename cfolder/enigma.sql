--CREATE DATABASE CHESS_ENIGMA

USE CHESS_ENIGMA

DROP TABLE AUTEUR;
DROP TABLE ENIGME;
DROP TABLE COUPS;


CREATE TABLE AUTEUR(
	id_aut int not null primary key,
	nom_aut varchar(50),
	prenom_aut varchar(50));

CREATE TABLE ENIGME(
	id_enigme int not null primary key,
	date_enigme date,
	id_aut int references AUTEUR(id_aut));
	
CREATE TABLE COUPS(
	num_coups int not null,
	id_enigme int references ENIGME(id_enigme),
	coup varchar(20),
	description varchar(250),
	PRIMARY KEY (num_coups,id_enigme));
INSERT INTO AUTEUR(id_aut, nom_aut, prenom_aut) VALUES
    (1, 'Tibor', 'Orban'),
    (2, 'test','test');
    
INSERT INTO ENIGME(id_enigme, date_enigme, id_aut) VALUES
    (1, '1976-01-01', 1),
    (2, '2020-03-03', 2);
    
INSERT INTO COUPS(num_coups, id_enigme, coup) VALUES
    (1, '1', 'e2-e4'),
    (2, '1', 'e7-e6'),
    (3, '1', 'Ff1-b5'),
    (4, '1', 'Re8-e7'),
    (5, '1', 'Fb5xd7'),
    (6, '1', 'c7-c6'),
    (7, '1', 'Fd7-e8'),
    (8, '1', 'Re7xe8');
INSERT INTO COUPS(num_coups, id_enigme, coup) VALUES
    (1, '2', 'd2-d4'),
    (2, '2', 'e7-e6'),
    (3, '2', 'c1-g5'),
    (4, '2', 'g8-f6');
INSERT INTO COUPS(num_coups, id_enigme, coup) VALUES
    (1, '3', 'f2-f4'),
    (2, '3', 'e7-e6'),
    (3, '3', 'g2-g4'),
    (4, '3', 'Qd8-h4 mat');




