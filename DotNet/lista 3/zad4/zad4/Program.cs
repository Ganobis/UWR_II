using System;
using System.Collections.Generic;
using System.Linq;

namespace zad4
{
    class Program
    {
        static void Main(string[] args)
        {
            try
            {
                string startFolder = @"c:\Users\Administrator\Desktop\UWR_II\DotNet\lista 2\zad4\zad4\";
                System.IO.DirectoryInfo dir = new System.IO.DirectoryInfo(startFolder);
                IEnumerable<System.IO.FileInfo> fileList = dir.GetFiles("*.*", System.IO.SearchOption.AllDirectories);
                var size = from file in fileList
                            let len = file.Length
                            select len;
                var sum_size = size.Aggregate((sum, size) => sum + size);
                Console.WriteLine(sum_size + "b");
            }
            catch (Exception e)
            {
                Console.WriteLine("The file could not be read:");
                Console.WriteLine(e.Message);
            }
        }
    }
}
