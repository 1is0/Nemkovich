using System;

namespace Lab_8___Csh__
{
    class Program
    {
        public static TownCarPark CreateCarPark()
        {
            Console.WriteLine("Enter basic information: ");
            Console.Write("Quantity of cars: ");
            int Cars = Checks.CheckInt();
            Console.Write("Quantity of trucks: ");
            int Trucks = Checks.CheckInt();
            Console.Write("Quantity of places to relax: ");
            int PlacesToRelax = Checks.CheckInt();
            Console.Write("Quantity of manholes: ");
            int Manholes = Checks.CheckInt();
            Console.Write("Quantity of service stations: ");
            int ServiceStations = Checks.CheckInt();
            bool magnetic_parking = false;
            Console.Write("Is there a magnetic parking lot? True ( yes ) or False ( no ): ");
            magnetic_parking = Checks.CheckBool();
            Console.Write("Enter quantity of equipments on special vehicles: ");
            int Amount = Checks.CheckInt();
            TownCarPark carPark = new TownCarPark(Cars, Trucks, ServiceStations, Manholes, PlacesToRelax, magnetic_parking, Amount);
            if (Amount > 0)
            {
                Console.WriteLine("Enter items through 'Enter' in turn: ");
                for (int i = 0; i < Amount; i++)
                {
                    carPark[i] = Checks.Check();
                }
            }
            Console.Clear();
            return carPark;
        }

        static void Main(string[] args)
        {
            var carPark = CreateCarPark();
            carPark.Information((q) => Console.WriteLine(q));
            carPark.Adding += (n) => Console.WriteLine(n);
            carPark.Added += delegate (string m)
            {
                Console.WriteLine(m);
            };
            carPark.Add(5, 6);
            carPark.UpdateInformation(2, 3);
            carPark.AddEquip("fire extinguisher");
            Console.WriteLine("\n");
            carPark.Information(delegate (string m) { Console.WriteLine(m); } );
            Console.ReadKey();
            return;
        }
    }
}
