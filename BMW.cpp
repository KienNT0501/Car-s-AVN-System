#include "BMW.h"
BMW::BMW() {
    branch = "BMW"; //constructor BMW
}
BMW::BMW(string brand = "BMW") {
    branch = brand;
}
BMW::~BMW() {}// destructor BMW
void BMW:: input() {
    inputCarInfor();
    nhapmodelxe();
}
void BMW:: display() { //xuat thong tin xe BMW
    cout << "---THONG TIN CHUNG CUA XE---" << endl;
    getOwner();
    cout << "- Thong tin xe - " << endl;
    cout // dùng lệnh setw để căn chỉnh khoảng cách
        << setw(10) << "Hang xe"
        << setw(10) << "Model"
        << setw(10) << "Nam SX"
        << setw(10) << "Mau son"
        << setw(15) << "So Series"
        << setw(15) << "Ngay ban"
        << setw(15) << "Bao hanh"
        << setw(10) << "Trang thai"
        << endl; //xuất thông tin xe
    cout << setw(10) << branch
        << setw(10) << model
        << setw(10) << year
        << setw(10) << color
        << setw(15) << series
        << setw(0) << sale_date.day << "/" << sale_date.month << "/" << setw(11) << sale_date.year
        << setw(0) << warranty_period.day << "/" << warranty_period.month << "/" << setw(11) << warranty_period.year
        << setw(10);
        getStatus();
        cout<< endl;
}
//hàm nhập model xe
void BMW:: nhapmodelxe() {
    cout << "Nhap model xe: ";
    getline(cin, model);
}
// hàm get model xe
void BMW::getmodelxe() {
    cout << model << "\t";
}
