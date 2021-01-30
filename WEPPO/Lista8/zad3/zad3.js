var mssql = require('mssql');
async function main() {
    var conn = new mssql.ConnectionPool(
        'server=localhost,1433;database=temp;user id=wojtek;password=1234567890abcde');
    try {
        //w Microsoft SQL Menagment Server dodano tabele z: ID(PK, autonumerowanie, NOT NULL, int), imie(nchar(20), NOT NULL), nazwisko(nchar(20), NOT NULL), plec(nchar(10), NOT NULL), nr_telefonu(nchar(9))
        await conn.connect();
        var request = new mssql.Request(conn);
        await request.query('delete from OSOBY where plec=\'kobieta\';'); //to wywołanie usuwa wszystkie kobiety z tabeli
        await request.query('update OSOBY set imie=\'Andrzej\' where imie=\'Krzysztof\' and nazwisko=\'Duda\''); //wszystkie rekordy tabeli gdzie imie to Krzysztof, a nazwisko Duda zmieniają imie na Andrzej
        await conn.close();
    }
    catch (err) {
        if (conn.connected)
            conn.close();
        console.log(err);
    }
}
main();