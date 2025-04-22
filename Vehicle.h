#pragma once
#include<iostream>
#include "DATE.h"
#include "Person.h"
#include <iomanip>
using namespace std;
class Vehicle {
public:
    Person info;
    string branch;
    string series;
    int year;
    DATE sale_date;
    DATE warranty_period;
    string color;
    bool status = false;
public:
    Vehicle();
    Vehicle(string bran, int yea, string colo, string serie);
    virtual void input();
    virtual void display();
    void getyear();
    void getcolor();
    void getngayban();
    void getwarranty();
    void inputPersonInfor();
    void setSeries();
    void saleDay();
    void getSeries();
    Person getOwner();
    bool getStatus();
    void inputCarInfor();
    void setYear();
};