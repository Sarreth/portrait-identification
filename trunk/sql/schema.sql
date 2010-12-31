CREATE ROLE "user" LOGIN
  PASSWORD 'user';

CREATE DATABASE identification
  WITH OWNER = "user"
       ENCODING = 'UTF8';

CREATE TABLE persons
(
  id serial NOT NULL,
  person_firstname character varying NOT NULL,
  person_lastname character varying,
  person_patronymic character varying,
  CONSTRAINT persons_pkey PRIMARY KEY (id)
)
ALTER TABLE persons OWNER TO "user";

CREATE TABLE points
(
  id serial NOT NULL,
  x integer NOT NULL,
  y integer NOT NULL,
  point_number integer NOT NULL,
  person_id integer NOT NULL,
  CONSTRAINT points_pkey PRIMARY KEY (id),
  CONSTRAINT points_person_id_fkey FOREIGN KEY (person_id)
      REFERENCES persons (id) MATCH SIMPLE
      ON UPDATE CASCADE ON DELETE CASCADE,
  CONSTRAINT points_person_id_key UNIQUE (person_id, point_number)
)
ALTER TABLE points OWNER TO "user";
