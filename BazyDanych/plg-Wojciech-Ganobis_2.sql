-- Wojciech Ganobis, plg
-- Zadanie 1
CREATE VIEW ranking
(displayname, liczba_odpowiedzi) 
AS
SELECT
U1.displayname, COUNT(P1.id)
FROM posts P1
JOIN posts P2 ON P1.acceptedanswerid = P2.id
JOIN users U1 ON P2.owneruserid = U1.id
GROUP BY U1.displayname
ORDER BY count DESC, displayname;


-- Zadanie 2
SELECT id, displayname, reputation FROM ((SELECT U1.id, U1.displayname, U1.reputation, U1.creationdate FROM users U1
													LEFT JOIN badges B1 ON B1.userid = U1.id
													JOIN (SELECT U4.id, COUNT(*) FROM users U4
														JOIN comments C4 ON C4.userid = U4.id
														WHERE EXTRACT(YEAR FROM C4.creationdate) = 2020
														GROUP BY U4.id)
														C1 ON C1.id = U1.id
													WHERE 
															U1.upvotes > (SELECT AVG(upvotes) FROM	(SELECT DISTINCT(U2.id), U2.upvotes FROM users U2
																						      JOIN badges B2 ON B2.userid = U2.id
																						      WHERE B2.name LIKE 'Enlightened') AS foo_in)
															AND
															C1.count > 1)
													EXCEPT 
														(SELECT U3.id, U3.displayname, U3.reputation, U3.creationdate FROM users U3
														JOIN badges B3 ON B3.userid = U3.id
														WHERE B3.name LIKE 'Enlightened')) AS foo
ORDER BY creationdate;

-- Zadanie 3
WITH RECURSIVE RECURRENCE AS (
	SELECT U1.id, U1.displayname FROM users U1
	JOIN posts P1 ON P1.owneruserid = U1.id
	WHERE P1.body LIKE '%recurrence%'
	UNION
	SELECT U2.id, U2.displayname FROM users U2
	JOIN comments C1 ON C1.userid = U2.id
	JOIN posts P1 ON P1.id = C1.postid
	JOIN users U3 ON U3.id = P1.owneruserid
	JOIN RECURRENCE R1 ON R1.id = U3.id)
	SELECT R2.id, R2.displayname FROM RECURRENCE R2;