using System;

namespace zad2
{
    public class Grid
    {
        public int x, y; 
        public int[,] tab;
        public Grid(int x, int y) { tab = new int[x, y]; this.x = x; this.y = y; }


        public int[] this[int k]
        {
            get
            {
                int[] values = new int[x];
                for (int i = 0; i < x; i++)
                    values[i] = this.tab[k, i];

                return values;
            }
        }



    public int this[int i, int j]
        {
            get => tab[i, j];
            set => tab[i, j] = value;
        }
    }


    class Program
    {
        static void Main()
        {
            Grid grid1 = new Grid(3, 3);
            int a = 0;
            for(int i = 0; i < 3; i++)
            {
                for(int j = 0; j < 3; j++)
                {
                    grid1[i, j] = a;
                    a++;
                }
            }
            Console.WriteLine(grid1[1][1]);

            int[] rowdata = grid1[1];

            foreach (var item in rowdata)
                Console.Write(item.ToString() + " ");

            Console.WriteLine();
           
            foreach (var item in grid1.tab)
                Console.Write(item.ToString() + " ");

        }
    }
}