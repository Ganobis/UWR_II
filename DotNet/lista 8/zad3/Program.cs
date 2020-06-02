using System;
using System.Linq;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Configuration;
using System.Data.Linq;
using zad2;
using System.Runtime.CompilerServices;

namespace zad3
{
    class Program
    {
        static void Main(string[] args)
        {
            try{
                using (var context = new SampleDataContext(@"server=DESKTOP-E7580\SQLEXPRESS;database=zad2;integrated security=true") )
                {
                	//Dodawanie rekordu do bazy danych
                    Student nowy = new Student();
                    nowy.Imię = "Alina";
                    nowy.Nazwisko = "Abacka";
                    Miejscowosc temp = new Miejscowosc();
                    temp.Nazwa = "Bielsko";
                    nowy.Miejscowosc = temp;
                    nowy.DataUrodzenia = new DateTime(2000,1,1);
                    context.Student.InsertOnSubmit(nowy);
                    //Usuwanie rekordu z bazy danych
                    var usum = context.Student.Where(p => p.Imię.StartsWith("Basia"));
                    Student susun = usum.FirstOrDefault();
                    context.Student.DeleteOnSubmit(susun);
                    //Modyfikacja
                    var zmianamiasta = context.Student.Where(p => p.Imię.StartsWith("Danuta"));
                    Student szmiana = zmianamiasta.FirstOrDefault();
                    szmiana.Miejscowosc = context.Miejscowosc.Where(m => m.Nazwa.StartsWith("Poznan")).FirstOrDefault();
                    context.SubmitChanges();
                }
            }
            catch (Exception e)
            {
                Console.WriteLine(e.Message);
            }
        }
    }
}