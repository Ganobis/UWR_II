using System;
using System.Collections.Generic;
using System.Linq;

namespace zad5
{
    class Program
    {
        static void Main(string[] args)
        {
            List<string> list_peron = new List<string>();
            List<string> list_acc = new List<string> ();
            try
            {
                System.IO.StreamReader streamReader_per = new System.IO.StreamReader("person.txt");
                System.IO.StreamReader streamReader_acc = new System.IO.StreamReader("account.txt");
                string line;
                while ((line = streamReader_per.ReadLine()) != null)
                {
                    list_peron.Add(line);
                }    
                while ((line = streamReader_acc.ReadLine()) != null)
                {
                    list_acc.Add(line);
                }
            }
            catch (Exception e)
            {
                Console.WriteLine("The file could not be read:");
                Console.WriteLine(e.Message);
            }
            var query = from elem1 in list_peron
                        join elem2 in list_acc
                        on elem1.Split(" ").ElementAt(2) equals elem2.Split(" ").ElementAt(0)
                        select elem1 + " " + elem2.Split(" ").ElementAt(1);

            foreach (var elem in query)
                Console.WriteLine(elem);
        }
    }
}
