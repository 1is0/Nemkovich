using System;
using System.Collections.Generic;
using System.Text;

namespace Lab_8___Csh__
{
    class Checks
    {
        public static int CheckInt()
        {
            int a;
            while (!int.TryParse(Console.ReadLine(), out a))
            {
                Console.WriteLine("Error input. Repeat, please: ");
            }
            return a;
        }
        public static bool CheckBool()
        {
            bool a = false;
            while (!bool.TryParse(Console.ReadLine(), out a))
            {
                Console.WriteLine("Error, input again: ");
            }
            return a;
        }
        public static string Check()
        {
            string a;
            a = Console.ReadLine();
            while (a.Length > 20)
            {
                Console.WriteLine("Error input. Repeat, please: ");
                a = Console.ReadLine();
            }
            return a;
        }
    }
}
