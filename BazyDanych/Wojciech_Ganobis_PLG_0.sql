-- Wojciech Ganobis, PLG
-- Zadanie 1
SELECT creationdate::date FROM posts 
WHERE body LIKE '%Turing%'
ORDER BY creationdate DESC;

-- Zadanie 2
SELECT id, title FROM posts
WHERE creationdate > '2018-10-10'
	AND EXTRACT(MONTH FROM creationdate) BETWEEN 9 AND 12
	AND title IS NOT NULL
	AND score >= 9
ORDER BY title;

-- Zadanie 3
SELECT DISTINCT displayname, reputation FROM users U
	JOIN posts P ON P.owneruserid = U.id
	JOIN comments C ON C.postid = P.id
WHERE body LIKE '%deterministic%'
	AND C.text LIKE '%deterministic%'
ORDER BY reputation DESC;
-- Zadanie 4
(SELECT displayname FROM users U
JOIN posts P ON P.owneruserid = U.id) 
EXCEPT 
(SELECT displayname FROM users U
JOIN comments C ON C.userid = U.id)
ORDER By displayname LIMIT 10;
