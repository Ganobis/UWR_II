using System;

namespace zad1
{
    class Program
    {
        static void Main(string[] args)
        {
            string s1 = "abcba";
            string s2 = "abcccba";
            string s3 = "Kobyła ma mały bok";
            string s4 = "kobyła ma mały bok";
            if (s1.IsPalindrom())
                Console.WriteLine(s1);
            if (s2.IsPalindrom())
                Console.WriteLine(s2);
            if (s3.IsPalindrom())
                Console.WriteLine(s3);
            if (s4.IsPalindrom())
                Console.WriteLine(s4);
        }
    }

    static class MyExtension
    {
        public static bool IsPalindrom(this string str)
        {
            str = str.Replace(" ", String.Empty);
            str = str.ToLower();
            int l = str.Length;
            for(int i = 0; i < l/2; i++) 
            {
                if (str[i] != str[l - 1 - i])
                    return false;
            }
            return true;
        }
    }
}
