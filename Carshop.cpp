#include"Carshop.h"
#include "BMW.h"
#include "Porsche.h"
#include "Vinfast.h"
#include "DATE.h"
CarShop::CarShop()
{
    countCar = 0;
    listVehicle = new Vehicle * [MAX_COUNT];
}
CarShop::~CarShop() {
    if (listVehicle != NULL) {
        for (int i = 0; i < countCar; i++) {
            delete listVehicle[i];
        }
        delete[] listVehicle;
        listVehicle = NULL;
    }
}
//xóa màn hình mỗi khi qua màn hình mới
void CarShop:: clearConsole() {
#ifdef _WIN32
    system("cls");    // Clear screen for Windows
#else
    system("clear");  // Clear screen for Linux/macOS
#endif
}
//thêm xe mới vào list
void CarShop:: addVehicle(Vehicle* veh) {
    if (countCar < MAX_COUNT - 1) {
        listVehicle[countCar] = veh;
        countCar++;
        cout << " Da cap nhat thong tin!" << endl;
    }
    else {
        cout << "Khong the them xe vao kho! Qua so luong xe cho phep" << endl;
        system("pause");
        MainMenu();
    }
}
//xuất thông tin xe trong cửa hàng
void CarShop::outputCarInShowRoom() {
    cout << " ======= Danh sach xe chua ban ======= " << endl;
    int j = 0;
    for (int i = 0; i < countCar; i++) {
        if (listVehicle[i]->status == false) { //câu lệnh kiểm tra xe này đã được bán chưa: chưa->false, đã bán -> true
            cout << " -------- Thong tin xe thu " << j + 1 << " --------" << endl;
            listVehicle[i]->display(); //xuất thông tin xe ứng với index i 
            j++;
        }
    }

    if (j == 0) {
        cout << " ==> CUA HANG DA BAN HET XE " << endl;
        system("pause");
        menuMH3();
    }
    system("pause");
    menuMH3();
}
// xuất thông tin xe đã bán
void CarShop::outputSoldCar() {
    cout << " ======= Danh sach xe da ban ======= " << endl;
    int j = 0;
    for (int i = 0; i < countCar; i++) {
        if (listVehicle[i]->status == true) {//câu lệnh kiểm tra xe này đã được bán chưa: chưa->false, đã bán -> true
            cout << " -------- Thong tin xe thu " << j + 1 << " --------" << endl;
            listVehicle[i]->display();
            j++;
        }
    }

    if (j == 0) {
        cout << " ==> CUA HANG CHUA BAN DUOC XE NAO! " << endl;
        system("pause");
        menuMH3();
        }
    system("pause");
    menuMH3();
   }

//cập nhật thông tin xe
void CarShop::updateInfor() {
    string ser;
    char choice1 = 'n';
    cout << "====== Cap Nhat Thong Tin xe  ======" << endl;
    do {
        cout << "Nhap so Series xe ung voi xe can cap nhat trong cua hang: ";
        cin >> ser;
        int indexCar = menuMH7(ser);
        if (indexCar != -1) {
            Person p1; // tạo đối tượng kiểu Person, nhập thông tin vào p1 và gán chúng ứng với index Car tương ứng 
            p1.inputInforPerson();
            listVehicle[indexCar]->info.name = p1.name;
            listVehicle[indexCar]->info.dob = p1.dob;
            listVehicle[indexCar]->info.adress = p1.adress;
            listVehicle[indexCar]->info.phoneNumber = p1.phoneNumber;
            cout << "Cap Nhat thong tin xe thanh cong!!" << endl;
        }
        else {
            cout << " ==> Xe nay khong ton tai trong cua hang!" << endl; //nếu ko có số series trùng khớp
        }

        do {
            cout << " Ban co muon tiep tuc cap nhat thong tin xe khong? (y/n): ";
            cin >> choice1;
        } while (choice1 != 'y' && choice1 != 'Y' && choice1 != 'n' && choice1 != 'N');

    } while (choice1 == 'y' || choice1 == 'Y');
    menuMH2();
}
//Nhập tt bán xe
void CarShop::saleCar() {
    string serie;
    char choice = 'n';
    cout << "====== Nhap Thong Tin Ban Xe ======" << endl;
    do {
        cout << "Nhap so Series xe ung voi xe can ban trong cua hang: ";
        cin >> serie;
        int indexCar = menuMH7(serie);
        if (indexCar != -1) {
            Person p;
            p.inputInforPerson(); //tạo đối tượng kiểu Person, nhập thông tin vào p1 và gán chúng ứng với index Car tương ứng
            listVehicle[indexCar]->info.name = p.name;
            listVehicle[indexCar]->info.dob = p.dob;
            listVehicle[indexCar]->info.adress = p.adress;
            listVehicle[indexCar]->info.phoneNumber = p.phoneNumber;
            cout << "Nhap thong tin xe: " << endl;
            Vehicle sale;
            sale.saleDay();
            listVehicle[indexCar]->sale_date = sale.sale_date;
            listVehicle[indexCar]->warranty_period = sale.warranty_period;
            listVehicle[indexCar]->status = true;
            cout << "Nhap thong tin ban xe THANH CONG!!" << endl;
        }
        else {
            cout << " ==> Xe nay khong ton tai trong cua hang!" << endl;
        }

        do {
            cout << " Ban co muon tiep tuc nhap xe ban khong? (y/n): ";
            cin >> choice;
        } while (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N');

    } while (choice == 'y' || choice == 'Y');

    //system("pause");
    menuMH2();
}
//màn hình chính
void CarShop::MainMenu() {
    clearConsole();
    char luachon;
    string ktra;
    do {
        cout << " ======== Man hinh chinh ======= " << endl;
        cout << "1 - Nhap thong tin" << endl;
        cout << "2 - Tra cuu thong tin" << endl;
        cout << "3 - Thoat" << endl;
        cout << "==> Lua chon: ";
        cin >> luachon;
        if (luachon < 49 || luachon > 51) {
            clearConsole();
            cout << "Nhap sai! Vui long nhap lua chon tu 1 -> 3 (khong chua ki tu, chu cai!)" << endl;
        }

    } while (luachon < 49 || luachon > 51);

    switch (luachon) {
    case 49:
        menuMH2();
        break;
    case 50:
        menuMH3();
        break;
    case 51:
        cout << "Chao tam biet!! " << endl;
        break;
    }

}
//màn hình 2
void CarShop::menuMH2() {
    clearConsole();
    char luachon1;
    do {
        cout << "======== Nhap Thong Tin ======== " << endl;
        cout << "1 - Nhap xe moi" << endl;
        cout << "2 - Ban xe" << endl;
        cout << "3 - Cap nhat thong tin xe" << endl;
        cout << "4 - Tro ve man hinh chinh" << endl;
        cout << "==> Lua chon: ";
        cin >> luachon1;
        if (luachon1 < 49 || luachon1 > 52) {
            clearConsole();
            cout << "Nhap sai! Vui long nhap lua chon tu 1 -> 4 (khong chua ki tu, chu cai!)" << endl;
        }
    } while (luachon1 < 49 || luachon1 > 52);
    switch (luachon1) {
    case 49:
        menuMH4();
        break;
    case 50:
        saleCar();

        break;
    case 51:
        updateInfor();
        break;
    case 52:
        MainMenu();
        break;
    }

}
//MH main chon 2:
void CarShop::menuMH3() {
    clearConsole();
    char luachon;
    do {

        cout << "======== Tra Cuu Thong Tin ========" << endl;
        cout << "1 - Tra cuu theo so series" << endl;
        cout << "2 - Xem cac xe da ban" << endl;
        cout << "3 - Xem cac xe con tai cua hang" << endl;
        cout << "4 - Tro ve man hinh truoc (MH1)" << endl;
        cout << "==> Lua chon: ";
        cin >> luachon;
        if (luachon < 49 || luachon > 52) {
            clearConsole();
            cout << "Nhap sai! Vui long nhap lua chon tu 1 -> 4 (khong chua ki tu, chu cai!)" << endl;
        }
    } while (luachon < 49 || luachon > 52);
    switch (luachon) {
    case 49:
        outputCarbySeries();
        break;
    case 50:
        outputSoldCar();
        break;
    case 51:
        outputCarInShowRoom();
        break;
    case 52:
        MainMenu();
        break;
    }
}
// MH2 chon 1:
void CarShop::menuMH4() {
    clearConsole();
    char luachon;
    do {

        cout << "======== Nhap Thong Tin Xe Moi ========" << endl;
        cout << "1 - Xe BMW" << endl;
        cout << "2 - Xe Porsche" << endl;
        cout << "3 - Xe Vinfast" << endl;
        cout << "4 - Tro ve man hinh truoc (MH2)" << endl;
        cout << "==> Lua chon: ";
        cin >> luachon;
        if (luachon < 49 || luachon > 52) {
            clearConsole();
            cout << "Nhap sai! Vui long nhap lua chon tu 1 -> 4 (khong chua ki tu, chu cai!)" << endl;
            
        }
    } while (luachon < 49 || luachon > 52);
    switch (luachon) {
    case 49:
    {
        cout << " ======= Nhap thong tin BMW ======= " << endl;
        BMW* bmw = new BMW();
        bmw->input();
        addVehicle(bmw);
        system("pause");
        menuMH2();
        break;
    }
    case 50:
    {
        cout << " ======= Nhap thong tin Porsche ======= " << endl;
        Porsche* pors = new Porsche();
        pors->input();
        addVehicle(pors);
        system("pause");
        menuMH2();
        break;
    }
    case 51:
    {
        cout << " ======= Nhap thong tin Vinfast ======= " << endl;
        Vinfast* vinf = new Vinfast();
        vinf->input();
        addVehicle(vinf);
        system("pause");
        menuMH2();
        break;
    }
    case 52:
        menuMH2();
    }

}
// function check series đưa vào có trong ds hay ko co return found, ko return -1
int CarShop::menuMH7(string& seri) {
    int found = -1;
    int index = 0;
    for (int i = 0; i < countCar;i++) {
        index = i;
        if (listVehicle[i]->series == seri) { // truy cập vào series của xe tại index i
            cout << "Found xe co Series trung khop tai Index " << index << endl;
            found = index;
            return found;
        }
        else found = -1;
    }
    return found;
}
void CarShop::outputCarbySeries() {
    char choice = 'n';
    string seri ;
    do {
        cin.ignore();
        cout << " ====== Tra Cuu Thong Tin Xe Theo Series ====== " << endl;
        cout << "Nhap so series: ";
        cin >> seri;
        int indexCar;
        indexCar = menuMH7(seri);
        if (indexCar != -1) {
            listVehicle[indexCar]->display();
        }
        else {
            cout << " ==> Xe nay khong ton tai!" << endl;
        }

        do {
            cout << " Ban co muon tiep tuc tim xe theo series khong? (y/n): ";
            cin >> choice;
        } while (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N');

    } while (choice == 'y' || choice == 'Y');
    menuMH3();
}


