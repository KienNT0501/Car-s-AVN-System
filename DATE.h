#pragma once
#include<iostream>
#include<string>

using namespace std;
class DATE {
public:
	int day;
	int month;
	int year;
public:
	DATE();
	DATE(int d, int m, int y);
	void setDate(int d, int m, int y);
	void clearConsole();
	void setDateIsToday();
	void setDefaulDate();
	void inputDate();
	void setday();
	void setmonth();
	void setyear();
	void display() ;
};