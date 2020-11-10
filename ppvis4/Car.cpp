#include "Car.h"

Car::Car()
{
    Name = "tmp";
    cost = 0;
}
Car::Car(int cost, string Name)
{
    this->cost = cost; this->Name = Name;
}
int Car::get_cost()
{
    return cost;
}
string Car::get_Name()
{
    return Name;
}

bool operator < (Car car1, Car car2)
{
    return car1.cost < car2.cost;
}
bool operator > (Car car1, Car car2)
{
    return car1.cost > car2.cost;
}
bool operator <= (Car car1, Car car2)
{
    return car1.cost <= car2.cost;
}
bool operator >= (Car car1, Car car2)
{
    return car1.cost >= car2.cost;
}
bool operator == (Car car1, Car car2)
{
    return car1.cost == car2.cost;
}
bool operator != (Car car1, Car car2)
{
    return car1.cost != car2.cost;
}