-- 108, BRIN, range_inclusion_ops, =		--Wojciech Ganobis, 301519
--Ten typ indeksu (BRIN) dobrze działa dla dużych danych w których pewne komórki mają ze sobą naturalną koleracje pomiędzy ich lokalizacją w tabeli.
--range_inclusion_ops działa dla 'any range type'. Można nim sprawdzić czy zakres jest większy, równy bądź mnijeszy
--" = " operator = sprawdza czy są równe

--Wklejamy baze z zapisów, którą otrzymaliśmy kiedyś do ćwiczeń samodzielnych.
--Importujemy ją komendą \i baz.dmp
--Tworzymy tableke do testowania z posortowanymi danymi z wybor z ucięciem godzin z daty:
CREATE TABLE testy (kod_grupy int, kod_uz int, data date);
INSERT INTO testy (kod_grupy, kod_uz, data) SELECT * FROM wybor ORDER BY data;
--Użycie VACCUM ANALYZE zaby usunąć "śmieci"
VACUUM ANALYZE testy;
--Robimy pierwszy test
EXPLAIN ANALYZE SELECT data FROM testy WHERE CAST(data AS date) = '2016-01-14';
--                                                      QUERY PLAN                                                      
----------------------------------------------------------------------------------------------------------------------
-- Seq Scan on testy  (cost=10000000000.00..10000000377.61 rows=34 width=4) (actual time=0.006..1.272 rows=128 loops=1)
--   Filter: (data = '2016-01-14'::date)
--   Rows Removed by Filter: 20961
-- Planning time: 0.081 ms
-- Execution time: 3.370 ms




-- I drugi
EXPLAIN ANALYZE SELECT data FROM testy WHERE CAST(data AS date) = '2016-09-30';
--   
-------------------------------------------------------------------------------------------------------------------------
-- Seq Scan on testy  (cost=10000000000.00..10000000377.61 rows=1549 width=4) (actual time=1.917..6.128 rows=1549 loops=1)
--   Filter: (data = '2016-09-30'::date)
--   Rows Removed by Filter: 19540
-- Planning time: 0.099 ms
-- Execution time: 6.407 ms


--Teraz dodajemy indeksy
CREATE INDEX ON testy USING BRIN (data);
--Użycie VACCUM ANALYZE zaby usunąć "śmieci"
VACUUM ANALYZE testy;
--A teraz dodajemy dokładnie te same zapytania.
EXPLAIN ANALYZE SELECT data FROM testy WHERE CAST(data AS date) = '2016-01-14';
--                                                           QUERY PLAN                                                           
--------------------------------------------------------------------------------------------------------------------------------
-- Bitmap Heap Scan on testy  (cost=12.04..389.65 rows=34 width=4) (actual time=0.056..5.932 rows=128 loops=1)
--   Recheck Cond: (data = '2016-01-14'::date)
--   Rows Removed by Index Recheck: 20961
--   Heap Blocks: lossy=114
--   ->  Bitmap Index Scan on testy_data_idx1  (cost=0.00..12.03 rows=21089 width=0) (actual time=0.032..0.032 rows=1280 loops=1)
--         Index Cond: (data = '2016-01-14'::date)
-- Planning time: 0.098 ms
-- Execution time: 2.594 ms




--I drugie zapytanie
EXPLAIN ANALYZE SELECT data FROM testy WHERE CAST(data AS date) = '2016-09-30';
--                                              QUERY PLAN                                               
---------------------------------------------------------------------------------------------------------
-- Seq Scan on testy  (cost=0.00..377.61 rows=1549 width=4) (actual time=1.038..3.104 rows=1549 loops=1)
--   Filter: (data = '2016-09-30'::date)
--   Rows Removed by Filter: 19540
-- Planning time: 0.090 ms
-- Execution time: 5.259 ms


--WNIOSKI:
--Jak widać dodanie indeksów troszkę przyspiesza program.