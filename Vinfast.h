#pragma once
#include "Vehicle.h"
class Vinfast : public Vehicle {
private:
    bool electric; // Xe điện hay không
public:
    Vinfast();
    Vinfast(string brand, bool elc);
    ~Vinfast();

    void input() override;
    void display() override;
    bool boolelectric();
    void iselectric();
};