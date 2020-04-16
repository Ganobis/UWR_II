using System;
using System.Collections.Generic;
using System.Linq;

namespace zad3
{
    class Program
    {
        static void Main(string[] args)
        {
            List<string> list = new List<string>();
            try
            {
                System.IO.StreamReader streamReader = new System.IO.StreamReader("file.txt");
                string line;
                while ((line = streamReader.ReadLine()) != null)
                {
                    list.Add(line);
                }
            }
            catch (Exception e)
            {
                Console.WriteLine("The file could not be read:");
                Console.WriteLine(e.Message);
            }
            var query = list.GroupBy(x => x[0].ToString()).OrderBy(x => x.Key);
            
            foreach (var item in query)
                Console.Write(item.Key + " ");
        }
    }
}
