using System;
using System.Collections.Generic;
using System.Text;

namespace Lab_7___Csh__
{
    class Checks
    {
        public static int CheckNat()
        {
            int a;
            while (!int.TryParse(Console.ReadLine(), out a) || a <= 0)
                Console.Write("Error! Repeat: ");
            return a;
        }

        public static int CheckInt()
        {
            int a;
            while (!int.TryParse(Console.ReadLine(), out a))
                Console.Write("Error! Repeat: ");
            return a;
        }

        public static double CheckDouble()
        {
            double a;
            while (!double.TryParse(Console.ReadLine(), out a))
                Console.Write("Error! Repeat: ");
            return a;
        }

        public static bool CheckFraction(string frac)
        {
            for (int i = 0; i < frac.Length; i++)
            {
                if (i == 0 && frac[i] == '-') i++;
                if (frac[i] == '/' && i != frac.Length - 1) i++;
                if (!char.IsDigit(frac[i]) || (frac[i] == '0' && i == frac.Length - 1 && frac[i - 1] == '/')) return false;
            }
            return true;
        }
    }
}
