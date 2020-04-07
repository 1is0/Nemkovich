using System;

namespace Lab_1___Csh__
{
    class Program
    {
        static void Input(Matrix array)
        {
            for (int i = 0; i < array.row; i++)
            {
                for (int j = 0; j < array.colm; j++)
                {
                    Console.WriteLine("Mas[ " + (i + 1) + " , " + (j + 1) + " ]: ");
                    if (!int.TryParse(Console.ReadLine(), out array.matrix[i, j]))
                    {
                        Console.WriteLine("Неверный ввод. Повторите: ");
                        j--;
                        continue;
                    }
                }
            }
        }
        static int Fuse(int n)
        {
            bool s;
            s = int.TryParse(Console.ReadLine(), out n);
            while (n <= 0 || !s)
            {
                Console.WriteLine("Введите корректное число: ");
                s = int.TryParse(Console.ReadLine(), out n);
            }
            return n;
        }
        static void Output(Matrix array)
        {
            for (int i = 0; i < array.row; i++) 
            {
                for (int j = 0; j < array.colm; j++)
                {
                    Console.Write(array.matrix[i, j] + "\t");
                }
                Console.WriteLine();
            }
        }
        static void Main()
        {
            int n = 0;
            int r = 0, c = 0, s = 0, s1 = 0, s2 = 0;
            Console.WriteLine("Введите количество матриц для выполнения действий с ними: ");
            n = Fuse(n);
            Matrix[] a = new Matrix[n];
            for(int i=0; i < n; i++)
            {
                Console.WriteLine("Введите количество строк для " + (i + 1) + " матрицы:");
                r = Fuse(r);
                Console.WriteLine("Введите количество столбцов для " + (i + 1) + " матрицы:");
                c = Fuse(c);
                a[i] = new Matrix(r, c);
            }
            char select;
            bool work = true;
            while (work)
            {
                Console.Clear();
                Console.WriteLine("Выберите нужное Вам действие: ");
                Console.WriteLine("1. Заполнение матриц.");
                Console.WriteLine("2. Вывести матрицы в консоль.");
                Console.WriteLine("3. Сумма матрицы ( если это возможно ).");
                Console.WriteLine("4. Разность матриц ( если это возможно ).");
                Console.WriteLine("5. Произведение матриц.");
                Console.WriteLine("6. Произведение матрицы на число.");
                Console.WriteLine("7. Транспонировать матрицу.");
                Console.WriteLine("8. Найти определитель матрицы ( если это возможно ).");
                Console.WriteLine("9. Выйти из программы.");
                select = Convert.ToChar(Console.ReadLine());
                switch (select)
                {
                    case '1':
                        {
                            Console.Clear();
                            Console.WriteLine("Введите номер матрицы для заполнения: ");
                            s = Fuse(s);
                            while (s > n)
                            {
                                Console.WriteLine("Введите корректное число: ");
                                s = Fuse(s);
                            }
                            Input(a[s - 1]);
                        }
                        break;
                    case '2':
                        {
                            Console.Clear();
                            Console.WriteLine("===== Информация о значениях в матрицах =====");
                            for(int i=0; i < n; i++)
                            {
                                Console.WriteLine("\nМатрица №" + (i + 1)+"\n");
                                Output(a[i]);
                            }
                            Console.ReadKey();
                        }
                        break;
                    case '3':
                        {
                            Console.Clear();
                            Console.WriteLine("Выберите матрицы для сложения:\nМатрица №1: ");
                            s1 = Fuse(s1);
                            while (s1 > n)
                            {
                                Console.WriteLine("Введите корректное число: ");
                                s1 = Fuse(s1);
                            }
                            Console.WriteLine("Матрица №2: ");
                            s2 = Fuse(s2);
                            while (s2 > n)
                            {
                                Console.WriteLine("Введите корректное число: ");
                                s2 = Fuse(s2);
                            }
                            if (a[s1-1].row == a[s2-1].row && a[s1-1].colm == a[s2-1].colm)
                            {
                                Console.WriteLine("Результат суммы введенных Вами матриц: \n");
                                Matrix mass = new Matrix(a[s1 - 1].row, a[s1 - 1].colm);
                                mass.matrix = mass.Sum(a[s1 - 1], a[s2 - 1]);
                                Output(mass);
                            }
                            else
                            {
                                Console.WriteLine("Сложение невозможно.");
                            }
                            Console.ReadKey();
                        }
                        break;
                    case '4':
                        {
                            Console.Clear();
                            Console.WriteLine("Выберите матрицы для разности:\nМатрица №1: ");
                            s1 = Fuse(s1);
                            while (s1 > n)
                            {
                                Console.WriteLine("Введите корректное число: ");
                                s1 = Fuse(s1);
                            }
                            Console.WriteLine("Матрица №2: ");
                            s2 = Fuse(s2);
                            while (s2 > n)
                            {
                                Console.WriteLine("Введите корректное число: ");
                                s2 = Fuse(s2);
                            }
                            if (a[s1 - 1].row == a[s2 - 1].row && a[s1 - 1].colm == a[s2 - 1].colm)
                            {
                                Console.WriteLine("Результат разности введенных Вами матриц: \n");
                                Matrix masd = new Matrix(a[s1 - 1].row, a[s1 - 1].colm);
                                masd.matrix = masd.Differ(a[s1 - 1], a[s2 - 1]);
                                Output(masd);
                            }
                            else
                            {
                                Console.WriteLine("Разность невозможна.");
                            }
                            Console.ReadKey();
                        }
                        break;
                    case '5':
                        {
                            Console.Clear();
                            Console.WriteLine("Выберите матрицы для перемножения:\nМатрица №1: ");
                            s1 = Fuse(s1);
                            while (s1 > n)
                            {
                                Console.WriteLine("Введите корректное число: ");
                                s1 = Fuse(s1);
                            }
                            Console.WriteLine("Матрица №2: ");
                            s2 = Fuse(s2);
                            while (s2 > n)
                            {
                                Console.WriteLine("Введите корректное число: ");
                                s2 = Fuse(s2);
                            }
                            if (a[s2 - 1].row == a[s1 - 1].colm)
                            {
                                Console.WriteLine("Результат произведения введенных Вами матриц: \n");
                                Matrix masm = new Matrix(a[s1 - 1].row, a[s2 - 1].colm);
                                masm.matrix = masm.Multipl(a[s1 - 1], a[s2 - 1]);
                                Output(masm);
                            }
                            else
                            {
                                Console.WriteLine("Произведение невозможно.");
                            }
                            Console.ReadKey();
                        }
                        break;
                    case '6':
                        {
                            Console.Clear();
                            Console.WriteLine("Введите число, на которое хотите умножить матрицу: ");
                            int number;
                            while (!int.TryParse(Console.ReadLine(), out number))
                                Console.WriteLine("Неверный ввод. Повторите: ");
                            Console.WriteLine("Выберите матрицу для умножения её на число: ");
                            s = Fuse(s);
                            while (s > n)
                            {
                                Console.WriteLine("Введите корректное число: ");
                                s = Fuse(s);
                            }
                            int[,] masmn = new int[a[s-1].row, a[s-1].colm];
                            Console.Clear();
                            Console.WriteLine("Результат перемножения выбранной Вами матрицы на число: ");
                            for (int i = 0; i < a[s-1].row; i++)
                            {
                                for (int j = 0; j < a[s-1].colm; j++)
                                {
                                    masmn[i, j] = number * a[s-1].matrix[i, j];
                                    Console.Write(masmn[i, j] + "\t");
                                }
                                Console.WriteLine();
                            }
                            Console.ReadKey();
                        }
                        break;
                    case '7':
                        {
                            Console.Clear();
                            Console.WriteLine("Выберите матрицу для транспонирования: ");
                            s = Fuse(s);
                            while (s > n)
                            {
                                Console.WriteLine("Введите корректное число: ");
                                s = Fuse(s);
                            }
                            Matrix mastr = new Matrix(a[s - 1].colm, a[s - 1].row);
                            mastr.matrix = mastr.Transp(a[s - 1]);
                            Console.WriteLine("Транспонированная матрица: ");
                            for(int i=0; i < mastr.row; i++)
                            {
                                for(int j=0; j < mastr.colm; j++)
                                {
                                    Console.Write(mastr.matrix[i, j] + "\t");
                                }
                                Console.WriteLine();
                            }
                            Console.ReadKey();
                        }
                        break;
                    case '8':
                        {
                            Console.Clear();
                            Console.WriteLine("Выберите матрицу для нахождения определителя: ");
                            s = Fuse(s);
                            while (s > n)
                            {
                                Console.WriteLine("Введите корректное число: ");
                                s = Fuse(s);
                            }
                            if (a[s-1].row == a[s-1].colm)
                            {
                                double d;
                                d = a[s - 1].Determinant(a[s - 1]);
                                Console.WriteLine("Определитель равен " + d);
                            }
                            else
                            {
                                if (a[s-1].row < 1)
                                {
                                    Console.Write("Вычислить определитель невозможно!");
                                }
                                else
                                    Console.WriteLine("Вычислить определитель невозможно.");
                            }
                            Console.ReadKey();
                        }
                        break;
                    case '9':
                        {
                            work = false;
                            Console.Clear();
                        }
                        break;
                    default:
                        {
                            Console.WriteLine("Неверный ввод.");
                            Console.ReadLine();
                        }
                        break;
                }
            }
            Console.ReadLine();
        }
    }
}