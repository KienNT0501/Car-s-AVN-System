#pragma once
#include "Vehicle.h"
class CarShop  {
private:
    const int MAX_COUNT = 100;
    Vehicle** listVehicle;
    int countCar;
public:
    CarShop();
    ~CarShop();
    void addVehicle(Vehicle* veh);
    void outputCarInShowRoom();
    void outputSoldCar();
    void updateInfor();
    void saleCar();
    void MainMenu();
    void menuMH2();
    void menuMH3();
    void menuMH4();
    int menuMH7(string& seri);
    void outputCarbySeries();
    void clearConsole();
};