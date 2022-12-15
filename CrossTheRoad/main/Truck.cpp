#include "Truck.h"


Truck::Truck() {
    shape.push_back(" TruckTruckTru ");
    shape.push_back(" TruckTruckTru ");
    shape.push_back(" TruckTruckTru ");

}

Truck::Truck(int x) : Obstacle(x, 1) {
    shape.push_back(" TruckTruckTru ");
    shape.push_back(" TruckTruckTru ");
    shape.push_back(" TruckTruckTru ");
}




int Truck::isForm() {
    return 5;
}