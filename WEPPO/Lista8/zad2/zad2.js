var mssql = require('mssql');
async function main() {
    var conn = new mssql.ConnectionPool(
        'server=localhost,1433;database=temp;user id=wojtek;password=1234567890abcde');
    try {
        //w Microsoft SQL Menagment Server dodano tabele z: ID(PK, autonumerowanie, NOT NULL, int), imie(nchar(20), NOT NULL), nazwisko(nchar(20), NOT NULL), plec(nchar(10), NOT NULL), nr_telefonu(nchar(9))
        await conn.connect();
        var request = new mssql.Request(conn);
        var result = await request.query('insert into OSOBY values (\'Maria\', \'Dzwon\', \'kobieta\', \'794116233\') select scope_identity()');
        result.recordset.forEach(r => {
            console.log(r);
        })
        await conn.close();
    }
    catch (err) {
        if (conn.connected)
            conn.close();
        console.log(err);
    }
}
main();