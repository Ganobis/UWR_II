using Microsoft.Office.Interop.Excel;
using System;
using System.Data.OleDb;

namespace zad1
{
    class Program
    {
        static void Main(string[] args)
        {
            string oledbConnectString = "Provider=Microsoft.ACE.OLEDB.12.0;" +
            @"Data Source=xxx.xlsx;" +
            "Extended Properties=\"Excel 12.0;HDR=YES\";";
            OleDbConnection connection = new OleDbConnection(oledbConnectString);
            OleDbCommand command = new OleDbCommand("SELECT * FROM[xxx$]", connection);

            try
            {
                connection.Open();
                OleDbDataReader reader = command.ExecuteReader();

                while (reader.Read())
                {
                    for(int i = 0; i < 3; i++)
                        Console.Write(reader[i].ToString() + " ");
                    Console.WriteLine("");
                }

                reader.Close();
            }
            catch (Exception ex)
            {
                Console.Write("" + ex.Message);
                connection.Close();
            }
        }
    }
}
