-- Wojciech Ganobis, plg
-- Zadanie 1a
ALTER TABLE comments 
ADD COLUMN lasteditdate timestamp
DEFAULT now()
NOT NULL;

UPDATE comments 
SET lasteditdate = comments.creationdate;
-- Zadanie 1b
CREATE TABLE commenthistory (id SERIAL PRIMARY KEY, commentid INTEGER, creationdate TIMESTAMP, text TEXT);
-- Zadanie 2
CREATE OR REPLACE FUNCTION update_comments()
RETURNS TRIGGER AS
$X$
BEGIN
	IF(OLD.creationdate <> NEW.creationdate)
		THEN NEW.creationdate = OLD.creationdate;
	END IF;
		IF (NEW.id <> OLD.id OR
		NEW.postid <> OLD.postid OR
		NEW.lasteditdate <> NEW.lasteditdate)
		THEN 
			RAISE EXCEPTION 'Nie zmieniaj id, postid oraz lasteditdate!';
	END IF;
	IF(NEW.text <> OLD.text)
		THEN
			NEW.lasteditdate = now();
			INSERT INTO commenthistory(commentid, creationdate, text)
			VALUES(OLD.id, OLD.lasteditdate, OLD.text);
	END IF;
	RETURN NEW;
END
$X$ LANGUAGE plpgsql;

CREATE TRIGGER on_update
BEFORE UPDATE ON comments 
FOR EACH ROW EXECUTE PROCEDURE update_comments();
--Zadanie 3
CREATE OR REPLACE FUNCTION add_comment()
RETURNS TRIGGER AS
$X$
BEGIN
	NEW.lasteditdate = NEW.creationdate;
END
$X$ LANGUAGE plpgsql;

CREATE TRIGGER on_insert 
AFTER INSERT ON comments 
FOR EACH ROW EXECUTE PROCEDURE add_comment();
