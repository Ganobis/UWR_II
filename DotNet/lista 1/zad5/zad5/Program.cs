using System;

namespace zad5
{
    /// <summary>
    /// This program write on console all naturak numbers from 1 to 100 000,
    /// whith are divisible by every digit and sume of all digit.
    /// </summary>
    /// <summary>
    /// Class Program envoke all program
    /// </summary>
    class Program
    {
        /// <summary>
        /// Function "simply_func" check the number is correct.
        /// </summary>
        /// <param name="number">Natural number</param>
        /// <returns>True or false</returns>
        private static bool simply_func(int number)
        {
            int number1 = number;
            int sum = 0;
            while (number1 != 0)
            {
                int curr = number1 % 10;
                number1 /= 10;
                sum += curr;
                if ((curr != 0) && (number % curr != 0))
                {
                    return false;
                }
            }
            if ((sum != 0) && (number % sum == 0))
                return true;
            return false;
        }
        /// <summary>
        /// Main of program, return nothing.
        /// </summary>
        /// <param name="args">-</param>
        static void Main(string[] args)
        {
            for (int i = 0; i < 100000; i++)
            {
                if (simply_func(i))
                    Console.WriteLine(i);
            }
        }
    }
}
