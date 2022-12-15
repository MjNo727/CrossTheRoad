#include "Truck.h"


Truck::Truck() {
    shape.push_back("TruckTruckTruckTruckTruck ");
    shape.push_back("TruckTruckTruckTruckTruck ");
    shape.push_back("TruckTruckTruckTruckTruck ");

}

Truck::Truck(int x) : Obstacle(x, 1) {
    shape.push_back("TruckTruckTruckTruckTruck ");
    shape.push_back("TruckTruckTruckTruckTruck ");
    shape.push_back("TruckTruckTruckTruckTruck ");
}




int Truck::isForm() {
    return 4;
}