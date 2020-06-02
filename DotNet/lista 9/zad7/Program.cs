using System;
using System.Linq;
using System.Text;
using System.Xml.Linq;

namespace zad7
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("LINQ TO XML - Podaj pierwszą literę nazwiska: ");
            char pierwszaLitera = Console.ReadKey().KeyChar;

            string wypisz = "";
            XDocument xdoc = XDocument.Load("dane.xml");

            var studenci = from s in xdoc.Descendants("{studenci}Osoba")
                              select s;

            Console.WriteLine();

            foreach (var st in studenci)
            {
                char drugaDuza = ' ';
                int i = 0;
                while (drugaDuza.Equals(' '))
                {
                    i++;
                    if (Char.IsUpper(st.Value, i))
                        drugaDuza = st.Value[i];
                }
                if (drugaDuza == Char.ToLower(pierwszaLitera) || drugaDuza == Char.ToUpper(pierwszaLitera)) // Tak poniważ drugi argument to nazwisko, czyli druga duża litera
                    wypisz += st.Value + "\n";
            }

            Console.WriteLine(wypisz);

            Console.ReadKey();
        }
    }
}
