using System;

namespace Lab_5___Csh__
{
    class Program
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
        public static CarPark CreateCarPark()
        {
            Console.WriteLine("Enter basic information: ");
            Console.WriteLine("Quantity of cars: ");
            int Cars = CheckInt();
            Console.WriteLine("Quantity of trucks: ");
            int Trucks = CheckInt();
            Console.WriteLine("Quantity of places to relax: ");
            int PlacesToRelax = CheckInt();
            Console.WriteLine("Quantity of manholes: ");
            int Manholes = CheckInt();
            Console.WriteLine("Quantity of service stations: ");
            int ServiceStations = CheckInt();
            bool magnetic_parking = false;
            Console.WriteLine("Is there a magnetic parking lot? True ( yes ) or False ( no )");
            magnetic_parking = CheckBool();
            Console.WriteLine("Enter quantity of equipments on special vehicles: ");
            int Amount = CheckInt();
            TownCarPark CarPark = new TownCarPark(Cars, Trucks, ServiceStations, Manholes, PlacesToRelax, magnetic_parking, Amount);
            if (Amount > 0)
            {
                Console.WriteLine("Enter items through 'Enter' in turn: ");
                for (int i = 0; i < Amount; i++)
                {
                    CarPark[i] = Check();
                }
            }
            Console.Clear();
            return CarPark;
        }
        public static void CarPark_List(CarPark[] List)
        {
            for (int i = 0; i < List.Length; i++)
            {
                List[i] = CreateCarPark();
            }
            for (int i = 0; i < List.Length; i++)
            {
                Console.WriteLine();
                Console.Write(i + 1 + ")"); List[i].Information();
            }
        }
        static void Main(string[] args)
        {
            int Amount_New = 0;
            TownCarPark first = new TownCarPark();
            TownCarPark second = new TownCarPark(5, 6, 3);
            TownCarPark third = new TownCarPark(2, 3, 1, 2, 5, true, 0);
            var fourth = CreateCarPark();
            first.Information();
            second.Information();
            third.Information();
            fourth.Information();
            Console.WriteLine("How many car parks do you want to add? ");
            Amount_New = CheckInt();
            TownCarPark[] List = new TownCarPark[Amount_New];
            CarPark_List(List);
            Console.WriteLine($"Number of car parks created: {TownCarPark.Quantity_Car_Park}");
            Console.ReadKey();
            return;
        }
    }
}