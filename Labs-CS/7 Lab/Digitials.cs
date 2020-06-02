using System;

namespace Lab_7___Csh__
{
    class Digitals : IEquatable<Digitals>, IComparable
    {
        public int Integer { get; set; }
        public int Natural { get; set; }
        double number;

        public Digitals()
        {
            Integer = 1;
            Natural = 1;
        }

        public Digitals(int i, int n)
        {
            Integer = i;
            Natural = n;
            number = (double)Integer / Natural;
        }

        public Digitals(double num)
        {
            number = num;
            int count = -1;
            if (num % 10 == 0)
            {
                Integer = (int)num;
                Natural = 1;
                number = num;
            }
            else
            {
                for (int i = 0; (float)num % 10 != 0 || Math.Abs(num) < 1; i++)
                {
                    num *= 10;
                    count++;
                }
                num /= 10;
                Integer = (int)num;
                Natural = (int)Math.Pow(10, count);
            }
        }

        public static Digitals operator +(Digitals n1, Digitals n2)
        {
            Digitals num = new Digitals();
            num.Integer = n1.Integer * n2.Natural + n2.Integer * n1.Natural;
            num.Natural = n1.Natural * n2.Natural;
            num.number = n1.number + n2.number;
            return num;
        }

        public static Digitals operator -(Digitals n1, Digitals n2)
        {
            Digitals num = new Digitals();
            num.Integer = n1.Integer * n2.Natural - n2.Integer * n1.Natural;
            num.Natural = n1.Natural * n2.Natural;
            num.number = n1.number - n2.number;
            return num;
        }

        public static Digitals operator *(Digitals n1, Digitals n2)
        {
            Digitals num = new Digitals();
            num.Integer = n1.Integer * n2.Integer;
            num.Natural = n1.Natural * n2.Natural;
            num.number = n1.number * n2.number;
            return num;
        }

        public static Digitals operator /(Digitals n1, Digitals n2)
        {
            Digitals num = new Digitals();
            num.Integer = n1.Integer * n2.Natural;
            num.Natural = n1.Natural * n2.Integer;
            if (n1 < 0 || n2 < 0)
            {
                num.Integer = -num.Integer;
                num.Natural = Math.Abs(num.Natural);
            }
            num.number = n1.number / n2.number;
            return num;
        }

        public static bool operator >(Digitals n1, Digitals n2) => n1.number > n2.number;

        public static bool operator <(Digitals n1, Digitals n2) => n1.number < n2.number;

        public static bool operator ==(Digitals n1, Digitals n2) => n1.Equals(n2);

        public static bool operator !=(Digitals n1, Digitals n2) => !n1.Equals(n2);

        public override bool Equals(object obj) => ((Digitals)obj).number == this.number;

        public override int GetHashCode() => this.ToString().GetHashCode();

        public static implicit operator int(Digitals num) => (int)num.number;

        public static implicit operator double(Digitals num) => num.number;

        bool IEquatable<Digitals>.Equals(Digitals num) => this.number == num.number;

        int IComparable.CompareTo(object obj)
        {
            if (this.number > ((Digitals)obj).number) return 1;
            if (this.number < ((Digitals)obj).number) return -1;
            else return 0;
        }

        public string PrintNum => $"{number}";

        public string PrintFrac => $"{Integer}/{Natural}";

        public override string ToString() => "Number: " + PrintNum + "\nFraction: " + PrintFrac + "\n";
    }
}
