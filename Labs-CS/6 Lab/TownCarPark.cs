using System;

namespace Lab_6___Csh__
{
    class TownCarPark : VillageCarPark, IComparable, IUpDateInformation, ICloneable
    {
        private readonly bool magnetic_parking;
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
        public override void Information()
        {
            base.Information();
            if (magnetic_parking)
                Console.WriteLine("Car Park with new Magnetic Parking.");
            else
                Console.WriteLine("Car Park without new Magnetic Parking.");
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
        public void updateInformation(int _new_quantity_cars, int _new_quantity_trucks)
        {
            Cars = _new_quantity_cars;
            Trucks = _new_quantity_trucks;
        }
        public object Clone()
        {
            return (TownCarPark)this.MemberwiseClone();
        }
    }
}
