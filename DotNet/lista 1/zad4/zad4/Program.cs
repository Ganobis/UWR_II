using System;
using System.Reflection;

namespace zad4
{

    internal class MarkedAttribute : Attribute
    {

    }
    public class Foo
    {
        [Marked]
        public int Aaa()
        {
            return 1;
        }
        public int Bbb()
        {
            return 2;
        }
        [Marked]
        public char Ccc()
        {
            return 'a';
        }
        public bool Ddd()
        {
            return true;
        }
        [Marked]
        public int Eee()
        {
            return 5;
        }
        [Marked]
        public double Fff()
        {
            return 6;
        }
        [Marked]
        static public int Ggg()
        {
            return 7;
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            Type myType = (typeof(Foo));
            MethodInfo[] myArrayMethodInfo = myType.GetMethods(BindingFlags.Public | BindingFlags.Instance | BindingFlags.DeclaredOnly);

            for (int i = 0; i < myArrayMethodInfo.Length; i++)
                Console.WriteLine(myArrayMethodInfo[i]);

            //System.Attribute[] attributes = System.Attribute.GetCustomAttributes(myType);
            //foreach(System.Attribute attr in attributes)
            //{
            //    Console.WriteLine(attr);
            //}
        }
    }
}
