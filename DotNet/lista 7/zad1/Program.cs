using System;
using System.Globalization;

namespace zad1
{
    class Program
    {
        static void Main(string[] args)
        {
            Complex z = new Complex(4, 3);
            Console.WriteLine(String.Format("{0}", z));
            Console.WriteLine(String.Format("{0:d}", z));
            Console.WriteLine(String.Format("{0:w}", z));
            Complex x = new Complex();
            Console.WriteLine(String.Format("{0}", x));
        }
    }
    class Complex : IFormattable
    {
        private int rzeczywista, urojona;
        public Complex() => rzeczywista = urojona = 0;
        public Complex(int x, int i)
        {
            rzeczywista = x;
            urojona = i;
        }
        public static Complex operator + (Complex a, Complex b) =>
            new Complex(a.rzeczywista + b.rzeczywista, a.urojona + b.urojona);

        public static Complex operator - (Complex a, Complex b) =>
            new Complex(a.rzeczywista - b.rzeczywista, a.urojona - b.urojona);

        public static Complex operator * (Complex a, Complex b) =>
            new Complex(a.rzeczywista * b.rzeczywista - a.urojona * b.urojona, a.rzeczywista * b.urojona + a.urojona * b.rzeczywista);

        public override string ToString()
        {
            return this.ToString("D", CultureInfo.CurrentCulture);
        }

        public string ToString(string format)
        {
            return this.ToString(format, CultureInfo.CurrentCulture);
        }

        public string ToString(string format, IFormatProvider provider)
        {
            if (String.IsNullOrEmpty(format)) format = "D";
            if (provider == null) provider = CultureInfo.CurrentCulture;
            switch (format.ToUpperInvariant())
            {
                case "D":
                    return rzeczywista.ToString() + "+" + urojona.ToString() + "i";
                case "W":
                    return "[" + rzeczywista.ToString() + "," + urojona.ToString() + "]";
                default:
                    throw new FormatException(String.Format("zly format"));
            }
        }



    }
}