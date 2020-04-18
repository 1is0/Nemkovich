using System;

/* 
    Информация для Рынкевича Сергея Викторовича!!!
    За основу взят 5 вариант 3 лабораторной работы.
    ( Выполненная работа немного изменена, то бишь выполнен свой вариант с основой 5 варианта )
    При наличии вопросов могу объяснить каждую строку своего кода онлайн по Дискорду или при 
    помощи другой программы, которую Вы выберете.

    Условия выполнения:
    Стат. элемент   +   ( см. строку 29 )
    Свойства класса +   ( см. строку 30 )
    Конструкторы    +   ( см. строку 58 )
    Индексаторы     +   ( см. строку 64 )
    Методы          +   ( см. строку 75 )
    Перегрузка      +   ( см. строку 90 )
*/

namespace Lab_3___Csh__
{
    class AutoPark
    {
        private int trucks;
        private int cars;
        public int ServiceStations { get; set; }
        public int Manholes { get; set; }
        public int PlacesToRelax { get; set; }
        protected string[] equipments;
        public static int ObjEquip = 0;
        public int Trucks
        {
            set
            {
                if (value < 0)
                    trucks = -1 * value;
                else
                    trucks = value;
            }
            get
            {
                return trucks;
            }
        }
        public int Cars
        {
            set
            {
                if (value < 0)
                    cars = -1 * value;
                else
                    cars = value;
            }
            get
            {
                return cars;
            }
        }
        public AutoPark() { ServiceStations = 0; Manholes = 0; PlacesToRelax = 0; }
        public AutoPark(int n)
        {
            equipments = new string[n];
            ObjEquip += n;
        }
        public string this[int n]
        {
            set
            {
                equipments[n] = value;
            }
            get
            {
                return equipments[n];
            }
        }
        public void Information(int n)
        {
            Console.WriteLine("\n\n***Information about Car park***\n");
            Console.WriteLine($"Quantity of mechanical vehicles: trucks {trucks}; cars {cars}.");
            Console.WriteLine($"Places to relax on area - {PlacesToRelax}, manholes - {Manholes}, service stations - {ServiceStations}.");
            Console.WriteLine("Equipments on vehicles: ");
            for(int i=0; i < n; i++)
            {
                Console.Write(equipments[i]);
                if (i == n - 1)
                    Console.Write(".");
                else
                    Console.Write(", ");
            }
        }
        public void Addition(int plTR)
        {
            PlacesToRelax += plTR;
        }
        public void Addition(int plTR, int manh)
        {
            PlacesToRelax += plTR;
            Manholes += manh;
        }
        public void Addition(int plTR, int manh, int serv)
        {
            PlacesToRelax += plTR;
            Manholes += manh;
            ServiceStations += serv;
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Enter quantity of object equipment on mechanical vehicles: ");
            int m;
            while (!int.TryParse(Console.ReadLine(), out m))
            {
                Console.WriteLine("Error input. Repeat, please: ");
            }
            AutoPark park = new AutoPark(m)
            {
                Trucks = 4,
                Cars = 7
            };
            Console.WriteLine("Enter items through 'Enter' in turn:"); // работа с индексатором
            for (int i = 0; i < m; i++)
            {
                park[i] = Console.ReadLine();
            }
            park.Information(m);  // демонстрация работы перегрузки
            park.Addition(2, 4, 1);
            Console.WriteLine();
            park.Information(m);
            park.Addition(2);
            park.Information(m);
            park.Addition(0, 1);
            park.Information(m);
            Console.ReadKey();
        }
    }
}