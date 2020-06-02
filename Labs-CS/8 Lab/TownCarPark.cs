using System;

namespace Lab_8___Csh__
{
    class TownCarPark : VillageCarPark, IComparable, ICloneable
    {
        private readonly bool magnetic_parking;
        private string MagneticPark = "Car Park with new Magnetic Parking.";
        private string NoMagneticPark = "Car Park without new Magnetic Parking.";
        public delegate void AddQuant(string m);
        public event AddQuant Added;
        public TownCarPark() : base() { }
        public TownCarPark(int _equipments) : base(_equipments) { }
        public TownCarPark(int _cars, int _trucks, int _equipments) : base(_cars, _trucks, _equipments) { }
        public TownCarPark(int _cars, int _trucks, int _service_stations, int _manholes, int _places_to_relax, bool _magnetic_parking, int _equipments) : base(_cars, _trucks, _equipments)
        {
            ServiceStations = _service_stations;
            Manholes = _manholes;
            PlacesToRelax = _places_to_relax;
            magnetic_parking = _magnetic_parking;
        }
        public override void Information(Print _show)
        {
            base.Information(_show);
            if (magnetic_parking)
                _show.Invoke(MagneticPark);
            else
                _show.Invoke(NoMagneticPark);
            Console.WriteLine();
        }
        public int CompareTo(Object obj)
        {
            if (this.Cars < ((TownCarPark)obj).Cars)
                return -1;
            else
                if (this.Cars > ((TownCarPark)obj).Cars)
                return 1;
            else
                return 0;
        }
        public void UpdateInformation(int _new_quantity_cars, int _new_quantity_trucks)
        {
            Cars = _new_quantity_cars;
            Trucks = _new_quantity_trucks;
            Console.ForegroundColor = ConsoleColor.DarkRed;
            Added?.Invoke($"New quantity of cars - {Cars}, of trucks - {Trucks}.");
            Console.ResetColor();
        }
        public void AddEquip(string m)
        {
            if (ObjEquip == 0)
            {
                equipments = new string[1];

            }
            else
            {
                string[] tmpEquip = new string[ObjEquip];
                for (int i = 0; i < ObjEquip; i++)
                {
                    tmpEquip[i] = equipments[i];
                }
                equipments = new string[ObjEquip + 1];
                for (int i = 0; i < ObjEquip; i++)
                {
                    equipments[i] = tmpEquip[i];
                }
            }
            equipments[ObjEquip] = m;
            ObjEquip += 1;
            Console.ForegroundColor = ConsoleColor.DarkRed;
            Added?.Invoke($"You add new equipment: {m}.");
            Console.ResetColor();
        }
        public object Clone()
        {
            return (TownCarPark)this.MemberwiseClone();
        }
    }
}
