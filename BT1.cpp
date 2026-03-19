#include <iostream>
using namespace std;

int tuyetdoi(int n){
    if (n < 0) return -n;
    return n;
}

int gcd(int a, int b){
    a = tuyetdoi(a);
    b = tuyetdoi(b);
    if (b == 0) return a;
    return gcd(b, a % b);
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
    cout << "Nhap phan so: " << endl;
    check_digit(a);
}

void rutgon(PhanSo &p){
    int ucln = gcd(p.TuSo, p.MauSo);
    p.TuSo /= ucln;
    p.MauSo /= ucln;
}

void ouput(PhanSo a){
    if (a.TuSo == 0) cout<<"0";
    else if (a.TuSo == a.MauSo) cout<<"1";
    else if (a.MauSo == 1) cout << a.TuSo;
    else if (a.MauSo == -1) cout << -a.TuSo;
    else if (a.MauSo < 0) cout << -a.TuSo <<"/"<< tuyetdoi(a.MauSo);
    else cout<<a.TuSo<<"/"<<a.MauSo; 
}

int main() {
    PhanSo a;
    Nhap(a);     
    rutgon(a);    
    cout << "Phan so la: ";
    ouput(a);     
    return 0;
}