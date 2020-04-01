-- Wojciech Ganobis, PLG
-- Zadanie 1
SELECT U.id, U.reputation, U.displayname, COUNT(DISTINCT P.id) FROM users U
	JOIN posts P ON P.owneruserid = U.id
	JOIN postlinks PL ON PL.postid = P.id
WHERE
	PL.linktypeid = 3
	AND PL.relatedpostid IS NOT NULL
GROUP BY U.id, U.reputation, U.displayname
ORDER BY count DESC, U.displayname
LIMIT 20;

-- Zadanie 2
SELECT U.id, U.displayname, U.reputation, COUNT(C.id), AVG(C.score) FROM users U
	JOIN badges B ON B.userid = U.id
	LEFT JOIN posts P ON P.owneruserid = U.id
	LEFT JOIN comments C ON P.id = C.postid
WHERE B.name = 'Fanatic'
	GROUP BY U.id, U.reputation, U.displayname
HAVING COUNT(C.id) < 100
ORDER BY count DESC, U.displayname
LIMIT 20;

-- Zadanie 3
ALTER TABLE users 
	ADD CONSTRAINT PK_users PRIMARY KEY (id);

ALTER TABLE badges
	ADD CONSTRAINT FK_badges_users FOREIGN KEY (userid) REFERENCES users(id) DEFERRABLE;

ALTER TABLE posts DROP COLUMN viewcount;

DELETE FROM posts WHERE ((body IS NULL) OR (body = ''));

-- Zadanie 4
CREATE SEQUENCE id_posts;

SELECT SETVAL('id_posts', MAX(id)) FROM posts;

ALTER TABLE posts ALTER COLUMN id
	SET DEFAULT nextval('id_posts');

INSERT INTO posts(posttypeid, parentid, owneruserid, body, score, creationdate)
	SELECT 3, C.postid, C.userid, C.text, C.score, C.creationdate FROM comments C;


