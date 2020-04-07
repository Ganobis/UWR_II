using System;
using System.Linq;

namespace zad7
{
    class Program
    {
        static void Main(string[] args)
        {
            var item = new { Field1 = "The value1", Field2 = 5 };
            var list = new[] { item }.ToList();
            list.Add(new { Field1 = "The value2", Field2 = 2 });
            foreach (var v in list)
            {
                Console.WriteLine("Field1={0}, Field2={1}", v.Field1, v.Field2);
            }
        }
    }
}
