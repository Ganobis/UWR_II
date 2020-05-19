using System;
using System.Collections.Generic;

namespace zad_2
{
    class Program
    {
        static void Main(string[] args)
        {
            NonGenericNoDuplicate nonGenericNoDuplicate = new NonGenericNoDuplicate(4);
            nonGenericNoDuplicate.Add("przyklad");
            nonGenericNoDuplicate.Add("prlad");
            nonGenericNoDuplicate.Add(true);
            Console.WriteLine(nonGenericNoDuplicate.ToString());
            nonGenericNoDuplicate.Add("przyklad");
            nonGenericNoDuplicate.Add(12.12);
            nonGenericNoDuplicate.Add(4);
            nonGenericNoDuplicate.Add(true);
            Console.WriteLine(nonGenericNoDuplicate.ToString());
            nonGenericNoDuplicate.Wyczysc();
            Console.WriteLine(nonGenericNoDuplicate.ToString());
        }
    }

    class NonGenericNoDuplicate
    {
        private List<object> array;

        public NonGenericNoDuplicate()
        {
            array = new List<object>();
        }

        public NonGenericNoDuplicate(object t)
        {
            array = new List<object>();
            array.Add(t);
        }

        public void Wyczysc()
        {
            array.Clear();
        }

        public string SprawdzTyp(int numer)
        {
            return array[numer].GetType().ToString();
        }

        public object SprawdzZawartosc(int numer)
        {
            return array[numer];
        }

        public void Add(Object zawartosc)
        {
            for (int i = 0; i < array.Count; i++)
            {
                if (array[i].Equals(zawartosc))
                {
                    Console.WriteLine("Taki element już instnieje!");
                    return;
                }
            }
            array.Add(zawartosc);
        }
        public override string ToString()
        {
            if (array.Count == 0)
                return "Lista jest pusta!";
            else
            {
                string ret = "";
                foreach (object i in array)
                {
                    ret += i + ", ";
                }
                return ret;
            }
        }
    }
}
