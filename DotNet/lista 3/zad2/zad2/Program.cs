using System;
using System.Collections.Generic;
using System.Linq;

namespace zad2
{
    class Program
    {
        static void Main(string[] args)
        {
            List<int> list = new List<int>();
            try
            {
                System.IO.StreamReader streamReader = new System.IO.StreamReader("file.txt");
                string line;
                while ((line = streamReader.ReadLine()) != null)
                {
                    list.Add(Convert.ToInt32(line));
                }
            }
            catch (Exception e)
            {
                Console.WriteLine("The file could not be read:");
                Console.WriteLine(e.Message);
            }
            var query = from number in list
                        where number > 100
                        orderby number descending
                        select number;
            foreach (var element in query)
                Console.Write(element + " ");

            Console.WriteLine();

            var query2 = list.Where(x => x > 100).OrderByDescending(x => x);
            foreach (var element in query2)
                Console.Write(element + " ");
        }
    }
}
