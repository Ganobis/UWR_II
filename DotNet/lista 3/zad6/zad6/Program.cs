using System;
using System.Collections.Generic;
using System.Linq;

namespace zad6
{
    class Program
    {
        static void Main(string[] args)
        {
            List<string> list = new List<string>();
            try
            {
                System.IO.StreamReader streamReader = new System.IO.StreamReader("log.txt");
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
            var list_trim = from x in list
                             select x.Split(" ").ElementAt(1);
            var query = (from y in (from x in list_trim
                                    group x by x.Split(" ").ElementAt(0) into gr
                                    select new
                                    {
                                        ip = gr.Key,
                                        sum = gr.Count(),
                                    })
                         orderby y.sum descending
                         select y).Take(3);

            foreach (var item in query)
                Console.WriteLine(item.ip + " " + item.sum);
        }
    }
}
