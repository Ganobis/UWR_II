using System;

namespace zad2
{
    public class Program
    {
        static void Main(string[] args)
        {
            Grid grid = new Grid(4, 4);
            int rowdata = grid.tab[1,2];

            Console.WriteLine("Hello World!");
        }
    }

    public class Grid
    {
        public int[,] tab { get; set; }
        public Grid(int x, int y) => tab = new int[x, y];
    }
}
