var mssql = require('mssql');
async function main() {
    var conn = new mssql.ConnectionPool(
        'server=localhost,1433;database=temp;user id=wojtek;password=1234567890abcde');
    try {
        //w Microsoft SQL Menagment Server dodano tabele OSOBY z: id(PK, autonumerowanie, NOT NULL, int), imie(nchar(20), NOT NULL), nazwisko(nchar(20), NOT NULL), plec(nchar(10), NOT NULL), nr_telefonu(nchar(9), id_miejsca_pracy(int))
        //Dodano również drugą tabele MIEJSCA_PRACY z: id(PK, autonumerowanie, NOT NULL, int), nazwa(nchar(20), NOT NULL)
        //Dodatno także klucz opcy w tabeli OSOBA w kolumnie id_miejsca_pracy do tabeli MIEJSCA_PRACY w kolumnie id
        await conn.connect();
        var request = new mssql.Request(conn);
        //Dodanie firmy Nokie i odrazu dodanie osoby Zbigniew Frodo
        var result = await request.query('insert into MIEJSCA_PRACY values (\'Nokia\') select scope_identity() as id;');
        await request.query(`insert into OSOBY values (\'Zbigniew\', \'Frodo\', \'mezczyzna\', \'511335123\', ${result.recordset[0].id});`);
        await conn.close();
    }
    catch (err) {
        if (conn.connected)
            conn.close();
        console.log(err);
    }
}
main();