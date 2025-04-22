#include "Porsche.h"
Porsche::Porsche(){//default constructor Porsche
    topSpeed = 0;
}
Porsche::Porsche(string brand = "Porsche", int speed = 0) {//constructor tham số
    branch = brand;
    topSpeed = speed;
}
void Porsche:: input() {
    inputCarInfor();
    nhapmaxSpeed();
}
//hàm ghi tốc độ max của xe
void Porsche:: nhapmaxSpeed() {
    cout << "Nhap toc do toi da (km/h): ";
    cin >> topSpeed;
}
//hàm xuất tốc độ max của xe
void Porsche:: getmaxSpeed() {
    cout << topSpeed;
}
// hàm xuất thông tin xe dùng setw
void Porsche::display() {
    cout << "---THONG TIN CHUNG CUA XE---" << endl;
    getOwner();
    cout << "- Thong tin xe - " << endl;
    cout<< setw(10) << "Hang xe"
        << setw(25) << "Toc do cuc dai (km/h)"
        << setw(10) << "Nam SX"
        << setw(10) << "Mau son"
        << setw(15) << "So Series"
        << setw(15) << "Ngay ban"
        << setw(15) << "Bao hanh"
        << setw(10) << "Trang thai"
        << endl;
    cout << setw(10) << branch
        << setw(25) << topSpeed
        << setw(10) << year
        << setw(10) << color
        << setw(15) << series
        << setw(0) << sale_date.day << "/" << sale_date.month << "/" << setw(11) << sale_date.year
        << setw(0) << warranty_period.day << "/" << warranty_period.month << "/" << setw(11) << warranty_period.year
        << setw(10);
    getStatus();
    cout << endl;

}