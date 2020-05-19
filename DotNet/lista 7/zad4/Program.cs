using System;
using System.Threading;

namespace zad4
{
    class Program
    {
        static void Main(string[] args)
        {
            Random Rand = new Random();
            const int liczba_krzesel = 3;
            Semaphore poczekalnia = new Semaphore(liczba_krzesel, liczba_krzesel);
            Semaphore krzeslo = new Semaphore(1, 1);
            Semaphore krzeslo_barbera = new Semaphore(0, 1);
            Semaphore blokada = new Semaphore(0, 1);
            bool koniec = false;
            void Barber()
            {
                while (!koniec)
                {
                    Console.WriteLine("Barber śpi");
                    krzeslo_barbera.WaitOne();
                    if (!koniec)
                    {
                        Console.WriteLine("Barber obcina...");
                        Thread.Sleep(500);
                        Console.WriteLine("Barber skończył obcinać!");
                        blokada.Release();
                    }
                    else
                    {
                        Console.WriteLine("Barber śpi");
                    }
                }
                return;
            }
            void Customer(Object number)
            {
                int Number = (int)number;
                Console.WriteLine("Klient {0} idzie do barbera...", Number);
                Thread.Sleep(Rand.Next(1, 5) * 1000);
                Console.WriteLine("Klient {0} przyszedł!", Number);
                poczekalnia.WaitOne();
                Console.WriteLine("Klient {0} wchodzi do poczekani...", Number);
                krzeslo.WaitOne();
                poczekalnia.Release();
                Console.WriteLine("Klient {0} budzi barbera...", Number);
                krzeslo_barbera.Release();
                blokada.WaitOne();
                krzeslo.Release();
                Console.WriteLine("Klient {0} wychodzi...", Number);
            }
            Thread BarberThread = new Thread(Barber);
            BarberThread.Start();
            Thread[] Customers = new Thread[10];
            for (int i = 0; i < 10; i++)
            {
                Customers[i] = new Thread(new ParameterizedThreadStart(Customer));
                Customers[i].Start(i);
            }
            for (int i = 0; i < 10; i++)
            {
                Customers[i].Join();
            }
            koniec = true;
            krzeslo_barbera.Release();

            BarberThread.Join();
            Console.WriteLine("Koniec pracy!");
        }
    }
}