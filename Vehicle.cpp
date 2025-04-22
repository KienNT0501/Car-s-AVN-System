#include "Vehicle.h"
#include <sstream>
Vehicle::Vehicle() {
    branch = "N/A";
    color = "N/A";
    status = false;
    series = "111111111";
    year = 2000;
}
Vehicle::Vehicle(string bran, int yea, string colo, string serie) {
    branch = bran;
    year = yea;
    color = colo;
    series = serie;
}
//nhập thông tin chủ xe và xe
void Vehicle:: input() {
    inputPersonInfor();
    inputCarInfor();
}
//in ra thông tin
void Vehicle:: display() {
    cout << "---THONG TIN CHUNG CUA XE---" << endl;
    getOwner();
    cout << "- Thong tin xe - " << endl;
    cout << "Series cua xe (9 so): " << series << endl;
    cout << "Nam san xuat: " << year << endl;
    cout << "Mau xe: " << color << endl;
    cout << "- Ngay ban xe - " << endl;
    sale_date.display();
    cout << "- Thoi diem bao hanh - " << endl;
    warranty_period.display();
}
//các hàm getter và setter
void Vehicle:: getyear() {
    cout << year << "\t";
}
void Vehicle::getcolor() {
    cout << color;
}
void Vehicle::getngayban() {
    sale_date.display();
}
void Vehicle::getwarranty() {
    warranty_period.display();
}
void Vehicle::inputPersonInfor() {
    info.inputInforPerson();
}
//kiểm tra series có hợp lệ hay ko
void Vehicle::setSeries() {
    cout << "Series cua xe (9 so): " << endl;
    getline(cin, series);
    if (series.length() != 9) {
        cout << "Series nhap khong hop le, moi nhap lai " << endl;
        setSeries();
    }
}
// nhập ngày bán xe
void Vehicle::saleDay() {
    cout << "Ngay ban xe: " << endl;
    sale_date.inputDate();
    cout << "Thoi gian bao hanh: " << endl;
    warranty_period.inputDate();
}
//hàm xuất thông tin series
void Vehicle::getSeries() {
    cout << series << "\t";
}
//hàm getowner trong lớp vehicle để lấy thông tin người mua
Person Vehicle::getOwner() {
    info.outputInforPerson();
    return info;
}
// hàm xuất ra xe đã bán hay chưa, chưa ->false, rồi->true
bool Vehicle::getStatus() {
    bool trangthai = status;
    if (status == true)cout << "Da ban " << endl;
    else cout << "Chua ban" << endl;
    return trangthai;
}
// input thông tin cho xe
void Vehicle::inputCarInfor() {
    cin.ignore();
    setSeries();
    setYear();
    cout << "Mau xe: " << endl;
    getline(cin, color);
}
//nhập năm và kiểm tra có hợp lệ
void Vehicle::setYear() {
    string cvyear;
    cout << "Nam san xuat: " << endl;
    getline(cin, cvyear);
    time_t t_time = time(0);   // get time now
    tm* today = localtime(&t_time);
    bool isNumber = true;
    for (char digit : cvyear) {
        if (!isdigit(digit)) {
            cout << "Nam san xuat khong chua ki tu, moi nhap lai!!" << endl;
            setYear();
            isNumber = false;
            break;
        }
        if (isNumber==true) {
            year = stoi(cvyear);
            if (year > today->tm_year + 1900 || year < 1900) {
                cout << "Nam san xuat khong hop le, moi nhap lai!!" << endl;
                setYear();
                break;
            }
        }

    }
}