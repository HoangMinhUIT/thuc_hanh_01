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
    if (ucln == 0){
        p.TuSo /= 1;
        p.MauSo /= 1;
    }
    else{
    p.TuSo /= ucln;                     
    p.MauSo /= ucln;    
    }
}

PhanSo Cong(PhanSo a, PhanSo b){
    PhanSo res;
    res.TuSo = a.TuSo*b.MauSo + b.TuSo*a.MauSo;
    res.MauSo = a.MauSo * b.MauSo;
    rutgon(res);
    return res;
}


PhanSo Hieu(PhanSo a, PhanSo b){
    PhanSo res;
    res.TuSo = a.TuSo*b.MauSo - b.TuSo*a.MauSo;
    res.MauSo = a.MauSo * b.MauSo;
    rutgon(res);
    return res;
}



PhanSo Nhan(PhanSo a, PhanSo b){
    a.TuSo = a.TuSo * b.TuSo;
    a.MauSo = a.MauSo * b.MauSo;
    rutgon(a);
    return  a;
}



PhanSo Chia(PhanSo a, PhanSo b){
    a.TuSo = a.TuSo * b.MauSo;
    a.MauSo = a.MauSo * b.TuSo;
    rutgon(a);
    return  a;
}


void Xuat(PhanSo a){
    if (a.MauSo == 0) cout << "Phan so co mau bang 0 khong hop le";
    else if (a.TuSo == 0) cout<<"0";
    else if (a.TuSo == a.MauSo) cout<<"1";
    else if (a.MauSo == 1) cout << a.TuSo;
    else if (a.MauSo == -1) cout << -a.TuSo;
    else if (a.MauSo < 0) cout << -a.TuSo <<"/"<< tuyetdoi(a.MauSo);
    else cout<<a.TuSo<<"/"<<a.MauSo; 
}


int main() {
    PhanSo a, b;
    Nhap(a);
    b = Nhap();
    PhanSo c = Cong(a, b);
    cout << "Tong 2 phan so: ";
    Xuat(c); cout << endl;
    PhanSo h = Hieu(a, b);
    cout << "Hieu 2 phan so: ";
    Xuat(h); cout << endl;
    PhanSo n = Nhan(a, b);
    cout << "Tich 2 phan so: ";
    Xuat(n); cout << endl;
    PhanSo k = Chia(a, b);
    cout << "Thuong 2 phan so: ";
    Xuat(k); 
    return 0;
}
