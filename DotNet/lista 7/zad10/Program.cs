using System;
using System.IO;
using System.Reflection;

namespace zad10
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine(Read.Get("file.txt"));
        }       
    }

    class Read
    {
        public static string Get(string nazwa)
        {
            var assembly = Assembly.GetExecutingAssembly();
            using (Stream stream = assembly.GetManifestResourceStream($"zad10.{nazwa}"))
            using (StreamReader reader = new StreamReader(stream))
            {
                    return reader.ReadToEnd();
            }
        }
    }
}
