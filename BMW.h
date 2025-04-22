#pragma once
#include "Vehicle.h"
class BMW : public Vehicle {
private:
    string model;
public:
    BMW();
    BMW(string brand);
    ~BMW();
    void input();
    void display();
    void nhapmodelxe();
    void getmodelxe();
};