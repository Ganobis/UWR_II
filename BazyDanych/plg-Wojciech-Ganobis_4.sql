-- Wojciech Ganobis, PLG
-- Zadanie 1
SELECT B.name AS odznaka, COUNT(P.id) AS liczba FROM badges B
JOIN posts P ON B.userid = P.owneruserid
GROUP BY B.name
ORDER BY liczba DESC;

-- Zadanie 2
SELECT DISTINCT SUBSTRING(CAST(foo.regexp_matches AS text), 2, STRPOS(CAST(foo.regexp_matches AS text), ',')-2) AS slowa FROM (SELECT DISTINCT REGEXP_MATCHES(comments.text,
																												  '(\w{3,})\s+\1([^\w]|$)',
																												  'g') FROM comments) AS foo
ORDER BY slowa;

-- Zadanie 3a
ALTER TABLE users
ADD CONSTRAINT main_users PRIMARY KEY(id);
ALTER TABLE posts 
ADD CONSTRAINT foreign_posts
FOREIGN KEY (owneruserid) REFERENCES users(id)
DEFERRABLE INITIALLY DEFERRED;

--Zadanie 3b

--Oznaczenie tego pola jako NOT NULL ma sens jeżeli będizmey mieli inną np funkcje która będzie pobierać dane z pola owneruserid. Z moich obserwacji wynika że NULL w tym miejscu pojawia się jeżeli konto które dodało post, zostało usunięte. Moje pomysły na usunięcie NULLa z tej kolumny to a) Numerowanie ujemnym ID kont usuniętych(to znaczy, że pierwsze usunięte konto dostanie id -1, drugie -2 itd), można stworzyć wównież kolumne w users, która będzie mówić czy konto jest usunięte czy nie. b) Wrzucenie wszystkich nieaktywnych kont pod ID np 0 lub MAX_INT. Zaleta pierwszego sposobu to unikalność id usuniętych kont, będzie można łatwo wyszukać np wszyskie posty konkretnego usunięte konta. Zaletą drugiego sposobu jest Szybkie wyklucznie nieaktywnych kont. Wadą obu metod jest konieczność przeglądania wszystkich id po usunięciu konta i zmiana ich na nowe id. Moim zdaniem nie ma sensu zmieniać tego pola jako NOT NULL, powieważ wprowadzi to dodatkowe komplikacje.