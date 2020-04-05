using System;
using System.Collections.Generic;

namespace zad4
{
    public class ListHelper
    {
        internal static List<T> ConvertAll<T2, T>(List<T2> list, Converter<T2, T> converter)
        {
            List<T> list_out = new List<T>();
            foreach (T2 elem in list)
            {
                list_out.Add(converter(elem));
            }
            return list_out;
        }

        internal static List<T> FindAll<T>(List<T> list, Func<T, bool> func)
        {
            List<T> list_out = new List<T>();
            foreach(T elem in list)
            {
                if (func(elem))
                    list_out.Add(elem);
            }
            return list_out;
        }

        internal static int RemoveAll<T>(List<T> list, Func<T, bool> func)
        {
            int counter = 0;
            List< T > list_temp = new List<T>();
            foreach(T elem in list)
            {
                if (func(elem))
                {
                    list_temp.Add(elem);
                    counter++;
                }
            }
            foreach(T elem in list_temp)
            {
                list.Remove(elem);
            }
            return counter;
        }

        internal static void Sort<T>(List<T> list)
        {
            for(int i = 0; i < list.Count; i++)
            {
                for(int j = 0; j < list.Count - 1; j++)
                {
                    if(Convert.ToInt32(list[j]).CompareTo(Convert.ToInt32(list[j+1])) > 0)
                    {
                        T tmp = list[j];
                        list[j] = list[j + 1];
                        list[j + 1] = tmp;
                    }
                }
            }
        }

        internal static void ForEach<T>(List<T> list, Action<object> p)
        {
            foreach(T elem in list)
            {
                p(elem);
            }
        }
    }
    class Program
    {
        private static void write_list(List<int> l)
        {
            Console.WriteLine("Your list:");
            ListHelper.ForEach(l, x => Console.Write(x + " "));
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
            for (int i = 0; i < 50; i++)
            {
                list1.Add(i);
            }

            write_list(list1);

            List<int> list2 = ListHelper.ConvertAll(list1, x => 4 * x);
            write_list(list2);

            List<int> list3 = ListHelper.FindAll(list2, find_div20);
            write_list(list3);

            Console.WriteLine($"Remove {ListHelper.RemoveAll(list1, find_div20)} elements form list1");
            write_list(list1);

            List<int> list4 = new List<int>();
            list4.Add(34);
            list4.Add(12);
            list4.Add(99);
            list4.Add(122);
            list4.Add(756);
            list4.Add(-34);
            write_list(list4);
            ListHelper.Sort(list4);
            write_list(list4);
        }
    }
}
