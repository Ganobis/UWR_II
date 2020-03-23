using System;
using System.Collections;
using System.Collections.Generic;

namespace zad1
{
    class Comparision
    {
        private TimeSpan Czas;
        private DateTime Start, Stop;
        private int ex_sum;
        private int tests;

        public Comparision(int tests) { this.tests = tests; }

        private void time_start()
        {
            ex_sum = 0;
            Start = DateTime.Now;
        }

        private void time_stop(string txt)
        {
            Stop = DateTime.Now;
            Czas = Stop - Start;
            Console.WriteLine("Czas dla " + txt + ": " + Czas);
        }


        public void Dictionary()
        {
            Random rnd = new Random();
            time_start();
            Dictionary<int, int> dict = new Dictionary<int, int>();
            for(int i = 0; i < tests; i++)
                dict.Add(i, rnd.Next(0, 10000));
            for (int i = tests - 1; i >= 0; i--)
                ex_sum += dict[i];
            for (int i = 0; i < tests; i++)
                dict.Remove(i);
            time_stop("Dictionary<T,K>");
        }

        public void Hashtable()
        {
            Random rnd = new Random();
            time_start();
            Hashtable hashtable = new Hashtable();
            for (int i = 0; i < tests; i++)
                hashtable.Add(i, rnd.Next(0, 10000));
            for (int i = tests - 1; i >= 0; i--)
                ex_sum += (int)hashtable[i];
            for (int i = 0; i < tests; i++)
                hashtable.Remove(i);
            time_stop("Hashtable");
        }

        public void List()
        {
            time_start();
            List<int> list1 = new List<int>();
            for (int i = 0; i < tests; i++)
                list1.Add(i);
            foreach (int num in list1)
                ex_sum += num;
            for (int i = 0; i < tests; i++)
                list1.Remove(i);
            time_stop("List<T>");

        }
        public void ArratList()
        {
            time_start();
            ArrayList arrayList = new ArrayList();
            for (int i = 0; i < tests; i++)
                arrayList.Add(i);
            foreach (int num in arrayList)
                ex_sum += num;
            for (int i = 0; i < tests; i++)
                arrayList.Remove(i);
            time_stop("ArrayList");
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            Comparision c = new Comparision(100000);
            c.List();
            c.ArratList();
            c.Dictionary();
            c.Hashtable();
        }
    }
}
