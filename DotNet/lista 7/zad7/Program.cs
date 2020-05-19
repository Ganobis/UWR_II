using System;
using System.Messaging;
using System.IO;
using System.Threading;

namespace zad7
{
    class Program
    {
        static void Main()
        {
            Program wyslij = new Program();
            Program odvierz = new Program();

            Kolejka(@".\Private$\TextsQueue");
            while (true)
            {
                if (DateTime.Now.Second % 10 == 0)
                {
                    for (int i = 0; i < 10; i++)
                    {
                        wyslij.Wyslij(i.ToString());
                    }

                }
                odvierz.Odbierz();
            }

        }
        public static void Kolejka(string s)
        {
            MessageQueue kolejka = null;
            try
            {
                if (!MessageQueue.Exists(s))
                    kolejka = MessageQueue.Create(s);
                else
                    kolejka = new MessageQueue(s);
            }
            catch (MessageQueueException e)
            {
                Console.WriteLine(e.Message);
            }
            finally
            {
                kolejka.Close();
            }
        }


        public void Wyslij(string tresc)
        {
            try
            {

                MessageQueue kolejka = new MessageQueue(@".\Private$\TextsQueue");

                Message wyadomosc = new Message
                {
                    Body = tresc
                };

                kolejka.Send(wyadomosc);
            }
            catch (ArgumentException e)
            {
                Console.WriteLine(e.Message);
            }
        }
        public void Odbierz()
        {

            try
            {
                MessageQueue kolejka = new MessageQueue(@".\Private$\TextsQueue")
                {
                    Formatter = new BinaryMessageFormatter()
                };

                Message wiadomosc = kolejka.Receive();
                string tresc = (string)wiadomosc.Body;
                Console.WriteLine(tresc);
                Thread.Sleep(1000);
            }

            catch (MessageQueueException e)
            {
                Console.WriteLine(e.Message);
            }


            catch (InvalidOperationException e)
            {
                Console.WriteLine(e.Message);
            }

            catch (IOException e)
            {
                Console.WriteLine(e.Message);
            }
        }
    }
}
