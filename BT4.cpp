#include <iostream>
using namespace std;
struct date{
    int day, month, year;
};
int check_nhuan(date a){
    if ((a.year % 4 == 0 && a.year % 100 != 0) || (a.year % 400 == 0)) return 1;
    return 0;
}

void nhap_lai(date &a){
    cin >> a.day;
}
void nhap_lai_thang(date &a){
    cin >> a.month;
}
void nhap_lai_nam(date &a){
    cin >> a.year;
}

void input(date &a){
    cout << "Nhap ngay: "; cin >> a.day;
    cout << "Nhap thang: "; cin >> a.month;
    cout << "Nhap nam: "; cin >> a.year;
}
void output(date &a){
    if (a.year < 1){
        cout << "Nam " << a.year<<" khong hop le. Moi nhap lai nam: ";
        nhap_lai_nam(a);
        output(a);
    }
    else if (a.month < 1 || a.month > 12){
        cout << "Thang " << a.month<< " khong hop le. Moi nhap lai thang: ";
        nhap_lai_thang(a);
        output(a);
    }
    else if (a.day > 31 || a.day < 1){
        cout << "Ngay " << a.day<< " khong hop le. Moi nhap lai ngay: ";
        nhap_lai(a);
        output(a);
    }
    else{
        if (a.month == 2){
            if (a.day == 28){
                if (check_nhuan(a) == 1) cout << "29/02/" << a.year;
                else cout << "01/03/" << a.year;
            }
            else if (a.day == 29 && check_nhuan(a)) cout << "01/03/" << a.year;
            else if (check_nhuan(a) == 0){
                if (a.day > 28 || a.day < 1) {
                    cout << "Ngay khong hop le trong thang " << a.month << " . Moi nhap lai ngay: ";
                    nhap_lai(a);
                    output(a);}
                else cout << a.day + 1 << "/02/" << a.year;
            }
            else if (check_nhuan(a) == 1){ 
                if (a.day > 29 || a.day < 1) {
                    cout << "Ngay khong hop le trong thang " << a.month << " . Moi nhap lai ngay: ";
                    nhap_lai(a);
                    output(a);
                }
                else cout << a.day + 1 << "/02/" << a.year;
            }
           
        }
        else if (a.month == 4 || a.month == 6 || a.month == 9 || a.month == 11){
            if (a.day > 30 || a.day < 1) {
                cout << "Ngay khong hop le trong thang " << a.month << " . Moi nhap lai ngay: ";
                nhap_lai(a);
                output(a);
            }
            else if (a.day == 30 || a.day < 1) cout << "01/" << a.month+1 <<"/" << a.year;
            else cout << a.day+1 << "/" << a.month << "/" << a.year;
        }
        else{
            if (a.month == 12 && a.day == 31){
                cout << "01/01/" << a.year+1;
            }
            else{
                if (a.day > 31 || a.day < 1) {
                    cout << "Ngay khong hop le trong thang " << a.month << " . Moi nhap lai ngay: ";
                    nhap_lai(a);
                    output(a);
                }
            else if (a.day == 31) cout << "01/" << a.month+1 <<"/" << a.year;
            else cout << a.day+1 << "/" << a.month << "/" << a.year;
            }
    }
    }

        
        
}

int main(){
    date a;
    input(a);
    output(a);
    return 0;
}
