1.



4.
SELECT COUNT(DISTINCT nazwa) nazwa 
FROM przedmiot JOIN przedmiot_semestr USING (kod_przed)
	JOIN grupa USING (kod_przed_sem)
WHERE rodzaj_zajec='e' AND rodzaj = 'o';

7.
SELECT COUNT(*) nazwisko FROM uzytkownik 
WHERE nazwisko LIKE 'Kabacki%';

10.
SELECT COUNT(*) kod_grupy FROM grupa 
	JOIN przedmiot_semestr USING (kod_przed_sem)
	JOIN semestr USING (semestr_id)
	JOIN przedmiot USING (kod_przed) 
WHERE semestr.nazwa = 'Semestr zimowy 2017/2018'
	AND (rodzaj_zajec = 'c' OR rodzaj_zajec = 'C')
	AND przedmiot.nazwa = 'Logika dla informatyków';

15.
SELECT COUNT(*) kod_grupy FROM grupa
	JOIN uzytkownik USING (kod_uz)
WHERE uzytkownik.nazwisko = 'Kanarek'
	AND (rodzaj_zajec = 'r' OR rodzaj_zajec = 'R'); 
