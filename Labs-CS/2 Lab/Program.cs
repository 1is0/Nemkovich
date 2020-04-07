using System;

namespace Lab_2___Csh__
{
    class Program
    {
        static void UpperCase()
        {
            Console.WriteLine("Enter a string to find capital letters ( except the English alphabet ): ");
            string str = Console.ReadLine();
            foreach (char ch in str)
            {
                if (Char.IsUpper(ch) && !(ch >= 'A' && ch <= 'Z'))
                {
                    Console.WriteLine("Uppercase letter - " + ch);
                }
            }
        }
        static void PunctMark()
        {
            Console.WriteLine("Enter a string to edit: ");
            string str = Console.ReadLine();
            char[] ch = str.ToCharArray();
            for (int i = 1; i < str.Length; i++)
            {
                if (ch[i] == ',' || ch[i] == '!' || ch[i] == '.' || ch[i] == ':' || ch[i] == ';' || ch[i] == '-' || ch[i] == '?')
                {
                    if (ch[i - 1] == ',' || ch[i - 1] == '!' || ch[i - 1] == '.' || ch[i - 1] == ':' || ch[i - 1] == ';' || ch[i - 1] == '-' || ch[i - 1] == '?' || ch[i-1] == ' ')
                    {
                        continue;
                    }
                    char b = ch[i];
                    for (int j = i; j >= 0; j--)
                    {
                        if (j == 0)
                        {
                            Console.WriteLine("=============\nWarning: ");
                            Console.WriteLine("It’s impossible to put a punctuation mark at the beginning of a sentence.\n=============");
                            break;
                        }
                        if (ch[j] == ' ')
                        {
                            ch[j] = b;
                            break;
                        }
                    }
                }
            }
            Console.WriteLine("Result: ");
            for (int i = 0; i < str.Length; i++)
            {
                Console.Write(ch[i]);
            }
        }
        static double Perimetr(double a, double b, double c) => a + b + c;
        static double Square(int a, int b, int c) 
        {
            double s;
            double p = Perimetr(a, b, c) / 2;
            s = Math.Sqrt(p * (p - a) * (p - b) * (p - c));
            return s;
        }
        static double RadInDegr(double angle)
        {
            angle = (angle * 180) / Math.PI;
            return angle;
        }
        static double Angle(double a, double b, double c) 
        {
            double angle;
            angle = Math.Acos((b*b+c*c-a*a)/(2*b*c));
            angle = RadInDegr(angle);
            return angle;
        }
        static double RadiusInscribed(double a, double b, double c)
        {
            double r;
            double p = Perimetr(a, b, c) / 2;
            r = Math.Sqrt(((p-a)*(p-b)*(p-c))/p);
            return r;
        }
        static double RadiusDescribed(int a, int b, int c)
        {
            double r;
            double p = Perimetr(a, b, c)/2;
            r = a * b * c / (4 * Math.Sqrt(p * (p - a) * (p - b) * (p - c)));
            return r;
        }
        static int Warn(double a, double b, double c)
        {
            int w;
            if (a + b < c || b + c < a || a + c < b)
                w = 0;
            else
                w = 1;
            return w; 
        }
        static void Triangle()
        {
            int a = 0;
            int b = 0;
            int c = 0;
            int w = 0;
            while (w == 0)
            {
                Console.Clear();
                Console.WriteLine("Input the length of the sides of the triangle: ");
                Console.Write("a: ");
                while (!int.TryParse(Console.ReadLine(), out a) || a <= 0)
                {
                    Console.WriteLine("Invalid input. Enter the correct number: ");
                }
                Console.Write("b: ");
                while (!int.TryParse(Console.ReadLine(), out b) || b <= 0)
                {
                    Console.WriteLine("Invalid input. Enter the correct number: ");
                }
                Console.Write("c: ");
                while (!int.TryParse(Console.ReadLine(), out c) || c <= 0)
                {
                    Console.WriteLine("Invalid input. Enter the correct number: ");
                }
                w = Warn(a, b, c);
                if (w == 0)
                {
                    Console.WriteLine("Triangle doesn't exist. Enter the correct numbers.");
                    Console.ReadKey();
                }
            }
            Console.WriteLine("\n========== Information ==========\n");
            Console.WriteLine("Perimetr = " + Perimetr(a, b, c));
            Console.WriteLine("Square = " + Math.Round(Square(a, b, c),2));
            Console.WriteLine("Angles:\n Alpha\t~ " + Math.Round(Angle(a, b, c),2) + "\n Beta\t~ " + Math.Round(Angle(b, a, c),2) + "\n Gamma\t~ " + Math.Round(Angle(c, b, a),2));
            Console.WriteLine("Circle radius 1st ~ " + Math.Round(RadiusInscribed(a, b, c),2));
            Console.WriteLine("Circle radius 2nd ~ " + Math.Round(RadiusDescribed(a, b, c),2));
        }
        static void Main(string[] args)
        {
            bool s = true;
            while (s)
            {
                Console.Clear();
                Console.WriteLine("Switch number of the task: \n1. Search uppercase letters.\n2. Add punctuation before the word.\n3. Find triangle options.\n4. Exit.");
                int sel = 0;
                while (!int.TryParse(Console.ReadLine(), out sel) || sel < 1 || sel > 4)
                {
                    Console.WriteLine("Invalid input. Enter the correct number: ");
                }
                switch (sel)
                {
                    case 1:
                        Console.Clear();
                        UpperCase();
                        Console.ReadKey();
                        break;
                    case 2:
                        Console.Clear();
                        PunctMark();
                        Console.ReadKey();
                        break;
                    case 3:
                        Console.Clear();
                        Triangle();
                        Console.ReadKey();
                        break;
                    case 4:
                        s = false;
                        break;
                    default:
                        Console.WriteLine("Invalid input. Enter the correct number: ");
                        break;
                }
            }
        }
    }
}