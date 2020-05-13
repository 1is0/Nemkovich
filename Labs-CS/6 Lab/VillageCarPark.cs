using System;

namespace Lab_6___Csh__
{
        abstract class VillageCarPark : CarPark
        {
            protected string[] equipments;
            protected int ObjEquip = 0;
            public VillageCarPark() : base() { }
            public VillageCarPark(int _equipments)
            {
                equipments = new string[_equipments];
            }
            public string this[int _equipments]
            {
                set
                {
                    equipments[_equipments] = value;
                    ObjEquip++;
                }
                get
                {
                    return equipments[_equipments];
                }
            }
            public VillageCarPark(int _cars, int _trucks, int _equipments) : base(_cars, _trucks)
            {
                equipments = new string[_equipments];
            }
            public override void Information()
            {
                Console.WriteLine("\n\n***Information about Car park***\n");
                Console.WriteLine($"Quantity of mechanical vehicles: trucks {Trucks}; cars {Cars}.");
                Console.WriteLine($"Places to relax on area - {PlacesToRelax}, manholes - {Manholes}, service stations - {ServiceStations}.");
                int m = 0;
                if (ObjEquip != 0)
                {
                    Console.Write("Equipments on vehicles: ");
                    while (m < ObjEquip)
                    {
                        Console.Write($" {equipments[m]}");
                    if (m != ObjEquip - 1)
                        Console.Write(",");
                    else
                        Console.Write(".");
                        m++;
                    }
                Console.WriteLine();
                }
            }
        }
}
