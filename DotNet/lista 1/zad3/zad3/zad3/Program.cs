using System;
using System.Reflection;

namespace zad3
{
    class Example
    {
        private void PrivateMethod()
        {
            Console.Write("This is a private method!");
        }
        public void PublicMetod()
        {
            Console.Write("This is a public method#");
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            TimeSpan Czas;
            DateTime Start, Stop;

            Start = DateTime.Now;
            for (int i = 0; i < 10000; i++) 
            {
                typeof(Example).GetMethod("PrivateMethod", BindingFlags.NonPublic | BindingFlags.Instance).Invoke(new Example(), null);
            }
            Stop = DateTime.Now;
            Czas = Stop - Start;
            Console.WriteLine("Czas dla metody prywatniej: " + Czas);

            Start = DateTime.Now;
            for (int i = 0; i < 10000; i++)
            {
                Example ex = new Example();
                ex.PublicMetod();
            }
            Stop = DateTime.Now;
            Czas = Stop - Start;
            Console.WriteLine("Czas dla metody publicznej: " + Czas);
        }
    }
}
