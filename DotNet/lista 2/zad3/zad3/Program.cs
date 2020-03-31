using System;
using System.Collections.Generic;

namespace zad3
{
    class Program
    {
        private static void write_list(List<int> l)
        {
            Console.WriteLine("Your list:");
            foreach (int i in l)
            {
                Console.Write(i + " ");
            }
            Console.WriteLine();
        }
        private static bool find_div20(int x)
        {
            if (x % 20 == 0)
                return true;
            return false;
        }
        static void Main(string[] args)
        {
            List<int> list1 = new List<int>();
            for(int i = 0; i < 50; i++)
            {
                list1.Add(i);
            }

            write_list(list1);

            List<int> list2 = list1.ConvertAll(x => 4 * x);
            write_list(list2);

            List<int> list3 = list2.FindAll(find_div20);
            write_list(list3);

            Console.WriteLine($"Remove {list1.RemoveAll(match: find_div20)} elements form list1");
            write_list(list1);

            List<int> list4 = new List<int>();
            list4.Add(34);
            list4.Add(12);
            list4.Add(99);
            list4.Add(122);
            list4.Add(756);
            list4.Add(-34);
            write_list(list4);
            list4.Sort();
            write_list(list4);
        }
    }
}
