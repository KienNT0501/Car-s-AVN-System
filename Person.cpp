#include "Person.h"
#include <iomanip>
Person::Person() {
    name = "N/A";
    dob.setDefaulDate();
    adress = "N/A";
    phoneNumber = "N/A";
}
Person::Person(string n, string a, string p) {
    name = n;
    adress = a;
    phoneNumber = p;
}
Person::~Person() {};
// hàm nhập tt person
void Person:: inputInforPerson() {
    cout << "Nhap ten khach hang: " << endl;
    cin.ignore();
    getline(cin, name);
    cout << "Nhap ngay sinh khach hang " << endl;
    dob.inputDate();
    cout << "Nhap dia chi khach hang: " << endl;
    cin.ignore();
    getline(cin, adress);
    setPhonenumber();
}
//các hàm setter
void Person::setPhonenumber() {
    int count = 0;
    cout << "Nhap so dien thoai khach hang (10 so): " << endl;
    getline(cin, phoneNumber);
    for (int i = 0;phoneNumber[i] != '\0';i++) {
        count++;
    }
    if (count != 10) {
        cout << "So dien thoai nhap ko hop le, moi nhap lai!!!" << endl;
        setPhonenumber();
    }
    for (int j = 0;j < phoneNumber.length();j++) {
        if (phoneNumber[j] < '0' || phoneNumber[j]> '9') {
            cout << "So dien thoai chi duoc la cac chu so, moi nhap lai!!" << endl;
            setPhonenumber();
        }
    }
}//set default cho person
void Person::setDefaultInforPerson() {
    name = "kien";
    dob.setDefaulDate();
    adress = "Binh Dinh";
    phoneNumber = "0967851275";
}
//output thông tin người dùng setw
void Person::outputInforPerson() {
    cout << "- Thong tin khach hang - " << endl;
    cout << left << "\t"
        << setw(25) << "Ho ten"
        << setw(19) << "Ngay sinh"
        << setw(25) << "Dia chi"
        << setw(14) << "Dien thoai"
        << endl;
    cout << "\t"
        << setw(25) << name;
    cout << dob.day<<"/"<<dob.month<<"/" << setw(15) <<dob.year
        << setw(25) << adress
        << setw(15) << phoneNumber
        << endl;
}


