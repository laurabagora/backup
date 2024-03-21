--
-- Homework 5: SQL-DDL
-- @author: Laura Guerrero, lmg479
-- NAU, CS 345, Fall 2023
--

--
-- Output 1: start fresh
-- ---------------------
--

-- AI prompt: Create a database with mysql, information_schema, performance_schema, and sys
CREATE DATABASE mysql;
CREATE DATABASE information_schema;
CREATE DATABASE performance_schema;
CREATE DATABASE sys;
SHOW DATABASES;

--
-- Output 2: initialization
-- ------------------------
--
CREATE DATABASE airline_db;
SHOW DATABASES;

--
-- Output 3: inspect the database
-- ---------------------------
--
-- AI prompt: how to access the tables within airline_db
USE airline_db;
SHOW TABLES;

--
-- Output 4: the Pilot table
-- -------------------------
--
-- AI prompt: how to access the pilot table within airline_db
SELECT * FROM pilot;

--
-- Output 5: the Airport table
-- ---------------------------
--
SELECT * FROM airport;

--
-- Output 6: the Flight table
-- --------------------------
--
SELECT * FROM flight;

--
-- Output 7: the Connect table
-- ---------------------------
--
SELECT * FROM connect;

--
-- Output 8: check the work so far
-- -------------------------------
--
SHOW TABLES;

--
-- Output 9: change Connect
-- ------------------------
--
-- AI prompt: how to add pilot identification to the table
ALTER TABLE connect ADD COLUMN pilot_identification VARCHAR(10) NOT NULL;
DESC connect;

--
-- Output 10: change Connect
-- -------------------------
--
-- AI prompt: how to change pilot_identificaitn to pilot_id
ALTER TABLE connect CHANGE COLUMN pilot_identification pilot_id VARCHAR(10) NOT NULL;
DESC connect;

--
-- Output 11: change Connect
-- -------------------------
--
-- AI prompt: how to change pilot_identificaitn to pilot_id
ALTER TABLE connect CHANGE COLUMN pilot_identification pilot_id VARCHAR(10) NOT NULL;
DESC connect;

--
-- Output 12: change Connect
-- -------------------------
--
-- AI prompt: how to change varchar to int
ALTER TABLE connect MODIFY COLUMN pilot_id INT NOT NULL;
DESC connect;

--
-- Output 13: change Pilot
-- ----------------------------
--
-- AI prompt: how to delete address
ALTER TABLE pilot DROP COLUMN airline_address;
DESC pilot;

--
-- Output 14: change Connect
-- -------------------------
--
-- AI prompt: how to change connect name to stopover
RENAME TABLE connect TO stopover;
SHOW TABLES;

--
-- Output 15: clean up
-- -------------------
--
DROP TABLE IF EXISTS pilot, airport, flight, stopover;
SHOW TABLES;

--
-- Output 16: clean up
-- -------------------
--
DROP DATABASE IF EXISTS airline_db;
SHOW DATABASES;

--
-- end script
--
