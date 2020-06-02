using System;

namespace Lab_8___Csh__
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
        public override void Information(Print _show)
        {
            base.Information(_show);
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
