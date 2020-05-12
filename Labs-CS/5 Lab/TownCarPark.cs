using System;

namespace Lab_5___Csh__
{
    class TownCarPark : VillageCarPark
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

    }
}
