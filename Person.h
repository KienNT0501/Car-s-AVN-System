#pragma once
#include "DATE.h"
#include <ctime>
class Person {
public:
	string name;
	DATE dob;
	string adress;
	string phoneNumber;
public:
	Person();
	Person(string n, string a, string p);
	~Person();
	void inputInforPerson();
	void setPhonenumber();
	void setDefaultInforPerson();
	virtual void outputInforPerson();
	void setnamesoldcar();
	void setadresssphonesoldcar();
};