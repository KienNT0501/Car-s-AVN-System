#include "DATE.h"
DATE::DATE() {
    day = 1;
    month = 1;
    year = 2023;
}
DATE::DATE(int d, int m, int y) {
    day = d;
    month = m;
    year = y;
}
void DATE::setDate(int d, int m, int y) {
    day = d;
    month = m;
    year = y;
}
void DATE::clearConsole() {
#ifdef _WIN32
    system("cls");    // Clear screen for Windows
#else
    system("clear");  // Clear screen for Linux/macOS
#endif
}
//hàm set ngày hiện tại
void DATE::setDateIsToday() {
    time_t t_time = time(0);   // get time now
    tm* today = localtime(&t_time);
    this->day = today->tm_mday;
    this->month = today->tm_mon + 1; //tm_mon get value from 0->11
    this->year = today->tm_year + 1900; //tm_year get value from 1900
}
//hàm set ngày mặc định
void DATE::setDefaulDate() {
    day = 1;
    month = 1;
    year = 2023;
}
//hàm nhập ngày tháng
void DATE::inputDate() {
    cout << " Nhap ngay: ";
    setday();
    cout << " Nhap thang: ";
    setmonth();
    cout << " Nhap nam: ";
    setyear();
    // Kiểm tra tháng nhỏ hơn 12 và lớn hơn 0
    if (month > 12 || month < 0) {
        clearConsole();
        cout << "Thang nhap khong hop le, moi nhap lai!" << endl;
        inputDate();
    }
    else { // trong các tháng 1, 3, 5, 7, 8, 10, 12 ko quá 31 ngày và lớn hơn 0
        if ((month == 1) || (month == 3) || (month == 5) || (month == 7) || (month == 8) || (month == 10) || (month == 12)) {
            if (day > 31 || day < 0) {
                clearConsole();
                cout << "Ngay cua thang nhap khong hop le, moi nhap lai!" << endl;
                inputDate();
            }
        }
        // riêng tháng 2 có 28 ngày vào năm ko nhuận và 29 ngày vào năm nhuận
        if ((month == 2) && (year % 4 != 0)) {
            if (day > 28 || day < 0) {
                clearConsole();
                cout << "Nam nhap khong la nam nhuan, thang 2 co 28 ngay" << endl;
                cout << "Ngay cua thang nhap khong hop le, moi nhap lai!" << endl;
                inputDate();
            }
        }
        if ((month == 2) && (year % 4 == 0)) {
            if (day > 29 || day < 0) {
                clearConsole();
                cout << "Nam nhap la nam nhuan, thang 2 co 29 ngay" << endl;
                cout << "Ngay cua thang nhap khong hop le, moi nhap lai!" << endl;
                inputDate();
            }
        }
        // trong các tháng còn lại ko quá 30 ngày và lớn hơn 0
        else if ((month == 4) || (month == 6) || (month == 9) || (month == 11)) {
            if (day > 30 || day < 0) {
                clearConsole();
                cout << "Ngay cua thang nhap khong hop le, moi nhap lai!" << endl;
                inputDate();
            }

        }
    }
    time_t t_time = time(0);   // get time now
    tm* today = localtime(&t_time);
   // kiểm tra tương quan năm nhập so với năm hôm nay
    if (year > today->tm_year + 1900 || year < 1900) {
        cout << "Nam nhap vao ko hop le, moi nhap lai!! (1900 - yearNow)" << endl;
        inputDate();
    }
    // kiểm tra tương quan tháng nhập so với tháng hôm nay
    else if (year == today->tm_year + 1900) {
        if (month > today->tm_mon + 1 || month > 12) {
            cout << "Thang nhap vao ko hop le, moi nhap lai " << endl;
            inputDate();
        }
        // kiểm tra tương quan ngày nhập so với ngày hôm nay
        else if (month == today->tm_mon + 1) {
            if (day > today->tm_mday) {
                cout << "Ngay nhap ko hop le, moi nhap lai" << endl;
                inputDate();
            }
         
        }
    }
}
// các hàm setter
void DATE:: setday() {
    cin >> day;
}
void DATE::setmonth() {

    cin >> month;
}
void DATE::setyear() {
    cin >> year;
}
//hàm display ngày
void DATE:: display() {
    cout << day << "/" << month << "/" << year;
}