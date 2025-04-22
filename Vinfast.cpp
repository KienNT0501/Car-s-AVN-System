#include "Vinfast.h"
Vinfast::Vinfast() {//constructor default vinfast
    branch = "Vinfast";
    electric = false;
}
Vinfast::Vinfast(string brand = "Vinfast", bool elc = false) {//constructor tham số
    branch = brand;
    electric = elc;
}
Vinfast::~Vinfast() {}// destructor vinfast
void Vinfast:: input() {// input thông tin vinfast
    inputCarInfor();
    boolelectric();
}
//xuất thông tin xe và thông tin người mua
void Vinfast:: display() {
    cout << "---THONG TIN CHUNG CUA XE---" << endl;
    getOwner();
    cout << "- Thong tin xe - " << endl;
    cout<< setw(10) << "Hang xe"
        << setw(10) << "Xe dien"
        << setw(10) << "Nam SX"
        << setw(10) << "Mau son"
        << setw(15) << "So Series"
        << setw(15) << "Ngay ban"
        << setw(15) << "Bao hanh"
        << setw(10) << "Trang thai"
        << endl;
    cout << setw(10) << branch
        << setw(10);
    iselectric();
        cout<< setw(10) << year
        << setw(10) << color
        << setw(15) << series
        << setw(0) << sale_date.day << "/" << sale_date.month << "/" << setw(11) << sale_date.year
        << setw(0) << warranty_period.day << "/" << warranty_period.month << "/" << setw(11) << warranty_period.year
        << setw(10);
    getStatus();
    cout << endl;
}


//xe điện hay ko?
bool Vinfast:: boolelectric() {
    char sign;
    cout << "Xe nay co phai xe dien khong? (Y/N): ";
    cin >> sign;
    if (sign != 'y' && sign!='Y' && sign!='n' && sign!='N') {
        cout << "Nhap (y/n) hoac (Y/N), moi nhap lai!" << endl;
        boolelectric();
        
    }
    else {
        electric = (sign == 'Y' || sign == 'y');
        if (electric) {
            return true;
        }
        else {
            electric = false;
            return false;
        }
    }
}
//hàm xuất xe điện hoặc ko
void Vinfast:: iselectric() {
    if (electric == true) {
        cout << "YES ";
    }
    else if (electric == false) {
        cout << "NO ";
    }
}