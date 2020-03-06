using System;

namespace zad1
{
    class Program
    {
        private static bool prosta_funkcja(int liczba)
        {
            int liczba1 = liczba;
            int suma = 0;
            while (liczba1 != 0)
            {
                int curr = liczba1 % 10;
                liczba1 /= 10;
                suma += curr;
                if ((curr != 0) && (liczba%curr != 0))
                {
                    return false;
                }
            }
            if ((suma != 0) && (liczba%suma == 0))
                return true;
            return false;
        }
        static void Main(string[] args)
        {
            for (int i=0;i<100000;i++)
            {
                if (prosta_funkcja(i))
                    Console.WriteLine(i);
            }
        }
    }
}
