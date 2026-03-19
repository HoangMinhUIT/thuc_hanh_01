#include <iostream>
using namespace std;


int tuyetdoi(int n){
    if (n<0) return -n;
    return n;
}

int gcd(int a, int b){
    a = tuyetdoi(a);        
    b = tuyetdoi(b);        
    if (b == 0) return a;   
    return gcd(b, a%b);     
}

struct PhanSo{
    int TuSo;
    int MauSo;
};
void check_digit(PhanSo &a){
    cout << "Nhap tu so: ";
    while(!(cin >> a.TuSo)){
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Nhap sai! Vui long nhap lai tu so: ";
    }
    cout << "Nhap mau so: ";
    while(!(cin >> a.MauSo)){
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Nhap sai! Vui long nhap lai mau so: ";
    }
   while(a.MauSo == 0){
        cout << "Nhap lai mau (khac 0): ";
        cin >> a.MauSo;
    }
}

void Nhap(PhanSo &a){
    cout << "Nhap phan so thu 1: " << endl;
    check_digit(a);
}

PhanSo Nhap(){
    PhanSo b;
    cout << "Nhap phan so thu 2: " << endl;
    check_digit(b);
    return b;
}

void rutgon(PhanSo &p){
    int ucln = gcd(p.TuSo, p.MauSo);    
    p.TuSo /= ucln;                     
    p.MauSo /= ucln;   
    if (p.MauSo < 0){
        p.TuSo = -p.TuSo;
        p.MauSo = -p.MauSo;
    }                 
}

int SoSanh (PhanSo a, PhanSo b){
    a.TuSo = a.TuSo*b.MauSo;
    b.TuSo = b.TuSo*a.MauSo;
    if (a.TuSo > b.TuSo) return 1;
    else if (a.TuSo == b.TuSo) return 0;
    else return -1;
}

void Xuat(PhanSo a) {
    if (a.TuSo == 0) cout << "0";
    else if (a.TuSo == a.MauSo) cout<<"1";
    else if (a.MauSo == 1) cout << a.TuSo;
    else if (a.MauSo == -1) cout << -a.TuSo;
    else if (a.MauSo < 0) cout<<-a.TuSo<<"/"<<tuyetdoi(a.MauSo);
    else cout << a.TuSo << "/" << a.MauSo;
}


int main() {
    PhanSo a, b;
    Nhap(a);
    b = Nhap();
    rutgon(a);
    rutgon(b);
    int kq = SoSanh(a, b);
    if (kq == 1){
        cout << "Phan so lon nhat la: ";
        Xuat(a);
    }
    else if (kq == 0) cout << "Hai phan so bang nhau, khong co phan so lon nhat";
    else {
        cout << "Phan so lon nhat la: ";
        Xuat(b);
    }
    return 0;
}
