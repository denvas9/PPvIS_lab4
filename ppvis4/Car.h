#pragma once
#ifndef CAR_H
#define CAR_H
#include <iostream>

using namespace std;
class Car
{
private:
    int cost;
    string Name;

public:
    Car();
    Car(int cost, string Name);

    friend bool operator < (Car car1, Car car2);
    friend bool operator > (Car car1, Car car2);
    friend bool operator <= (Car car1, Car car2);
    friend bool operator >= (Car car1, Car car2);
    friend bool operator == (Car car1, Car car2);
    friend bool operator != (Car car1, Car car2);

    int get_cost();
    string get_Name();
};
#endif 

