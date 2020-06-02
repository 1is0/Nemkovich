using System;

namespace Lab_8___Csh__
{
    abstract class CarPark
    {
        public delegate void Add_(string n);
        public delegate void Print(string n);
        public event Add_ Adding;
        private int trucks;
        private int cars;
        public static int Quantity_Car_Park = 0;
        public int ServiceStations { get; set; }
        public int Manholes { get; set; }
        public int PlacesToRelax { get; set; }
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
        public CarPark() { Cars = 1; Trucks = 1; ServiceStations = 3; Manholes = 1; PlacesToRelax = 6; Quantity_Car_Park++; }
        public CarPark(int n, int m)
        {
            Cars = n;
            Trucks = m;
            Quantity_Car_Park++;
        }
        public virtual void Information(Print _show)
        {
            Console.ForegroundColor = ConsoleColor.DarkYellow;
            _show?.Invoke($"***Information about Car park***");
            Console.ResetColor();
            _show?.Invoke($"\nQuantity of mechanical vehicles: trucks {Trucks}; cars {Cars}.\n" +
                $"Places to relax on area - {PlacesToRelax}, manholes - {Manholes}, service stations - {ServiceStations}.");
        }
        public void Add(int n)
        {
            Adding?.Invoke($"You build {n} places to telax.");
            PlacesToRelax += n;
        }
        public void Add(int n, int m)
        {
            Console.ForegroundColor = ConsoleColor.DarkRed;
            Adding?.Invoke($"You build {n} places to relax and {m} manholes.");
            Console.ResetColor();
            PlacesToRelax += n;
            Manholes += m;
        }
    }
}
