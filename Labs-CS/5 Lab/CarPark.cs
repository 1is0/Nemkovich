using System;

namespace Lab_5___Csh__
{
    abstract class CarPark
    {
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
        public virtual void Information()
        {
            Console.WriteLine("\n\n***Information about Car park***\n");
            Console.WriteLine($"Quantity of mechanical vehicles: trucks {trucks}; cars {cars}.");
            Console.WriteLine($"Places to relax on area - {PlacesToRelax}, manholes - {Manholes}, service stations - {ServiceStations}.");
        }
    }
}