using System;
using System.Reflection;

namespace zad3
{
    class Example
    {
        private void PrivateMethod()
        {
            Console.WriteLine("This is a private method!");
        }
        public void PublicMetod()
        {
            Console.WriteLine("This is a public method#");
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            DateTime Start, Stop;

            Start = DateTime.Now;
            typeof(Example).GetMethod("PrivateMethod", BindingFlags.NonPublic | BindingFlags.Instance).Invoke(new Example(), null);
            Stop = DateTime.Now;

            TimeSpan Czas = Stop - Start;
            Console.WriteLine("Czas dla metody prywatniej: " + Czas);

            Start = DateTime.Now;
            Example ex = new Example();
            ex.PublicMetod();
            Stop = DateTime.Now;

            Czas = Stop - Start;
            Console.WriteLine("Czas dla metody publicznej: " + Czas);
        }
    }
}
