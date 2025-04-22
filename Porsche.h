#pragma once
#include "Vehicle.h"
class Porsche : public Vehicle
{
private:
    int topSpeed; // Tốc độ tối đa
public:
    Porsche();
    Porsche(string brand , int speed);
    void input() override;
    void display();
    void nhapmaxSpeed();
    void getmaxSpeed();
};
