using System;
using System.Globalization;
namespace zad8
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.OutputEncoding = System.Text.Encoding.UTF8;
            CultureInfo plPL = new CultureInfo("pl-PL");
            DateTimeFormatInfo dtfi = plPL.DateTimeFormat;
            foreach (string name in dtfi.MonthGenitiveNames)
            {
                Console.WriteLine("\"{0}\"", name);
            }
            foreach (string name in dtfi.AbbreviatedMonthGenitiveNames)
            {
                Console.WriteLine("\"{0}\"", name);
            }
            DateTime myDate = DateTime.Now;
            string us = myDate.ToString("dddd, dd MMMM yyyy", new CultureInfo("en-GB"));
            string de = myDate.ToString("dddd, dd MMMM yyyy", new CultureInfo("de-DE"));
            string fr = myDate.ToString("dddd, dd MMMM yyyy", new CultureInfo("fr-FR"));
            string ru = myDate.ToString("dddd, dd MMMM yyyy", new CultureInfo("ru-RU"));
            string ar = myDate.ToString("dddd, dd MMMM yyyy", new CultureInfo("ar-DZ"));
            string cz = myDate.ToString("dddd, dd MMMM yyyy", new CultureInfo("cz-CZ"));
            string pl = myDate.ToString("dddd, dd MMMM yyyy", new CultureInfo("pl-PL"));
            

            Console.WriteLine(us);
            Console.WriteLine(de);
            Console.WriteLine(fr);
            Console.WriteLine(ru);
            Console.WriteLine(ar);
            Console.WriteLine(cz);
            Console.WriteLine(pl);
        }
    }
}
