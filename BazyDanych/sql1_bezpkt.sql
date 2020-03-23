1.
1)
CREATE DOMAIN semestry AS varchar CHECK 
	((NOT NULL) AND ((VALUE = 'zimowy') OR (VALUE = 'letni')));
2)
CREATE SEQUENCE numer_semestru;
SELECT SETVAL('numer_semestru', MAX(semestr_id)) FROM semestr;
ALTER TABLE semestr ALTER COLUMN semestr_id SET DEFAULT NEXTVAL('numer_semestru');
ALTER SEQUENCE numer_semestru OWNED BY semestr.semestr_id;
3)
a) ALTER TABLE semestr ADD COLUMN semestr semestry DEFAULT 'zimowy';
b) ALTER TABLE semestr ADD COLUMN rok char(9);
4)
UPDATE semestr SET semestr='letni' WHERE nazwa LIKE '%letni%';
UPDATE semestr SET rok = SUBSTRING(nazwa FROM POSITION('/' IN nazwa) -4 FOR 9);
5)
ALTER TABLE semestr DROP COLUMN nazwa;
6)
ALTER TABLE semestr ALTER COLUMN semestr SET DEFAULT
	CASE WHEN extract(month FROM current_date) BETWEEN 1 AND 6
		THEN 'letni' 
		ELSE 'zimowy'
	END;

ALTER TABLE semestr ALTER COLUMN rok SET DEFAULT
	CASE WHEN extract(month FROM current_date) BETWEEN 1 AND 6
		THEN extract(year FROM current_date)-1||'/'||extract(year FROM current_date)
		ELSE extract(year FROM current_date)||'/'||extract(year FROM current_date)+1
	END;
