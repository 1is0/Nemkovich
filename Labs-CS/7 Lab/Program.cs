using System;

namespace Lab_7___Csh__
{
    class Program
    {
        public static Digitals GetNumber()
        {
            Console.Write("Number: ");
            double num = Checks.CheckDouble();
            return new Digitals(num);
        }

        public static Digitals GetFraction()
        {
            Console.Write("Fraction: ");
            string str = Console.ReadLine();
            while (!Checks.CheckFraction(str))
            {
                Console.Write("Error! Repeat: ");
                str = Console.ReadLine();
            }
            try
            {
                string[] arr = str.Split('/');
                return new Digitals(int.Parse(arr[0]), int.Parse(arr[1]));
            }
            catch
            {
                return new Digitals(int.Parse(str), 1);
            }
        }

        public static Digitals Enter()
        {
            int a;
            Console.Write(" (0 - Fraction, 1 - Number): ");
            while (!int.TryParse(Console.ReadLine(), out a) || a < 0 || a > 1)
                Console.Write("Error! Repeat: ");
            if (a == 0) return GetFraction();
            else return GetNumber();
        }

        static void Main()
        {
            Console.Write("Choose number or fraction you want input");
            var n1 = Enter();
            Console.Write("Choose number or fraction you wanr input");
            var n2 = Enter();
            Console.Clear();
            Console.WriteLine("The first number:\n" + n1);
            Console.WriteLine("The second number:\n" + n2);
            Console.WriteLine($"1. {n1.PrintFrac} > {n2.PrintFrac} = " + (n1 > n2));
            Console.WriteLine($" {n1.PrintNum} > {n2.PrintNum} = " + (n1 > n2) + "\n");
            Console.WriteLine($"2. {n1.PrintFrac} < {n2.PrintFrac} = " + (n1 < n2));
            Console.WriteLine($" {n1.PrintNum} < {n2.PrintNum} = " + (n1 < n2) + "\n");
            Console.WriteLine($"3. {n1.PrintFrac} == {n2.PrintFrac} = " + (n1 == n2));
            Console.WriteLine($" {n1.PrintNum} == {n2.PrintNum} = " + (n1 == n2) + "\n");
            Console.WriteLine($"4. {n1.PrintFrac} != {n2.PrintFrac} = " + (n1 != n2));
            Console.WriteLine($" {n1.PrintNum} != {n2.PrintNum} = " + (n1 != n2) + "\n");
            Console.WriteLine($"5. {n1.PrintFrac} + {n2.PrintFrac} = " + (n1 + n2).PrintFrac);
            Console.WriteLine($" {n1.PrintNum} + {n2.PrintNum} = " + (n1 + n2).PrintNum + "\n");
            Console.WriteLine($"6. {n1.PrintFrac} - {n2.PrintFrac} = " + (n1 - n2).PrintFrac);
            Console.WriteLine($" {n1.PrintNum} - {n2.PrintNum} = " + (n1 - n2).PrintNum + "\n");
            Console.WriteLine($"7. {n1.PrintFrac} * {n2.PrintFrac} = " + (n1 * n2).PrintFrac);
            Console.WriteLine($" {n1.PrintNum} * {n2.PrintNum} = " + (n1 * n2).PrintNum + "\n");
            if (n2 != 0)
            {
                Console.WriteLine($"8. {n1.PrintFrac} / {n2.PrintFrac} = " + (n1 / n2).PrintFrac);
                Console.WriteLine($" {n1.PrintNum} / {n2.PrintNum} = " + (n1 / n2).PrintNum + "\n");
            }
        }
    }
}
