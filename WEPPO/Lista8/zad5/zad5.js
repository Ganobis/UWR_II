var mssql = require('mssql');
async function main() {
    var conn = new mssql.ConnectionPool(
        'server=localhost,1433;database=temp;user id=wojtek;password=1234567890abcde');
    try {
        //w Microsoft SQL Menagment Server dodano tabele OSOBY z: id(PK, autonumerowanie, NOT NULL, int), imie(nchar(20), NOT NULL), nazwisko(nchar(20), NOT NULL), plec(nchar(10), NOT NULL), nr_telefonu(nchar(9))
        //Dodano również drugą tabele MIEJSCA_PRACY z: id(PK, autonumerowanie, NOT NULL, int), nazwa(nchar(20), NOT NULL)
        //Dodano również trzecią tablele OSOBY_DO_MIEJSCA_PRACY z: id(PK, autonumerowanie, NOT NULL, int), id_osoby(int, NOT NULL), id_miejsca_pracy(int, NOT NULL)
        //Dodatno także klucz opcy w tabeli OSOBY_DO_MIEJSCA_PRACY w kolumnie id_miejsca_pracy do tabeli MIEJSCA_PRACY w kolumnie id oraz drugi klucz w kolumnie id_osoby do tabeli OSOBY w kolumnie id
        await conn.connect();
        var request = new mssql.Request(conn);
        //dodanie miejsca pracy, potem osoby, pobranie id z obu zapytań i dodanie do tabeli łączącej w relecji wiele do wielu dodanych elementów
        var result = await request.query('insert into MIEJSCA_PRACY values (\'Nokia\') select scope_identity() as id;');
        var result2 = await request.query('insert into OSOBY values (\'Zbigniew\', \'Frodo\', \'mezczyzna\', \'511335123\') select scope_identity() as id;');
        await request.query(`insert into OSOBY_DO_MIEJSCA_PRACY values (${result.recordset[0].id}, ${result2.recordset[0].id});`);
        await conn.close();
    }
    catch (err) {
        if (conn.connected)
            conn.close();
        console.log(err);
    }
}
main();