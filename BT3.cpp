#include <iostream>
using namespace std;
/*
Hàm: tuyetdoi
Chức năng: Tính giá trị tuyệt đối của một số 
Input:  n (int): số nguyên bất kỳ
Output: int: giá trị tuyệt đối của n
*/
int tuyetdoi(int n){
    if (n<0) return -n;
    return n;
}
/*
Hàm: gcd 
Chức năng: Tìm ước chung lớn nhất (UCLN) của 2 số nguyên a và b bằng thuật toán Euclid
Input: a, b (int): hai số nguyên
Output: UCLN của a và b (int)
Giải thích:
    - Đưa a, b về số dương
    - Nếu b = 0 thì UCLN là a
    - Ngược lại, gọi đệ quy gcd(b, a % b)
*/
int gcd(int a, int b){
    a = tuyetdoi(a);        
    b = tuyetdoi(b);        
    if (b == 0) return a;   
    return gcd(b, a%b);     
}
/*
Struct: PhanSo
Chức năng: Lưu trữ một phân số gồm tử số và mẫu số
*/
struct PhanSo{
    int TuSo;
    int MauSo;
};
/*
Hàm: check_digit
Chức năng: Nhập tử số và mẫu số hợp lệ (kiểm tra người dùng nhập đúng số). Nếu mẫu bằng 0 thì yêu cầu nhập lại
Input: a (PhanSo&): tham chiếu đến phân số cần nhập
Output: Không trả về giá trị (void), nhưng cập nhật TuSo và MauSo của a
Giải thích: Nếu nhập sai kiểu dữ liệu (không phải số), yêu cầu nhập lại
*/
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
/*
Hàm: Nhap (hàm nhập thứ 1)
Chức năng: Nhập phân số thứ nhất
Input: a (PhanSo&): phân số cần nhập
Output: Không trả về, nhưng gán giá trị cho a
*/
void Nhap(PhanSo &a){
    cout << "Nhap phan so thu 1: " << endl;
    check_digit(a);
}
/*
Hàm: Nhap (hàm nhập thứ 2)
Chức năng: Nhập phân số thứ hai
Input: phân số cần nhập
Output: Không trả về, nhưng gán giá trị cho a
*/
PhanSo Nhap(){
    PhanSo b;
    cout << "Nhap phan so thu 2: " << endl;
    check_digit(b);
    return b;
}
/*
Hàm: rutgon
Chức năng: Rút gọn phân số về dạng tối giản
Input: p (PhanSo&): phân số cần rút gọn
Output: Không trả về, nhưng thay đổi trực tiếp p
Giải thích:
    - Tìm UCLN của tử và mẫu
    - Chia cả tử và mẫu cho UCLN
*/
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
/*
Hàm: Cong
Chức năng: Tính tổng hai phân số
Input: a, b (PhanSo)
Output:  kết quả a + b (PhanSo) (đã rút gọn)
Giải thích:
    - Quy đồng: a/b + c/d = (ad + cb) / bd
*/
PhanSo Cong(PhanSo a, PhanSo b){
    PhanSo res;
    res.TuSo = a.TuSo*b.MauSo + b.TuSo*a.MauSo;
    res.MauSo = a.MauSo * b.MauSo;
    rutgon(res);
    return res;
}
/*
Hàm: Hieu
Chức năng: Tính hiệu hai phân số
Input: a, b (PhanSo)
Output:  kết quả a - b (PhanSo) (đã rút gọn)
Giải thích:
    - Quy đồng: a/b - c/d = (ad - cb) / bd
*/
PhanSo Hieu(PhanSo a, PhanSo b){
    PhanSo res;
    res.TuSo = a.TuSo*b.MauSo - b.TuSo*a.MauSo;
    res.MauSo = a.MauSo * b.MauSo;
    rutgon(res);
    return res;
}
/*
Hàm: Nhan
Chức năng: Tính tích hai phân số
Input: a, b (PhanSo)
Output:  kết quả a*b (PhanSo) (đã rút gọn)
Giải thích: a/b * c/d = (a*c)/(b*d)
*/
PhanSo Nhan(PhanSo a, PhanSo b){
    a.TuSo = a.TuSo * b.TuSo;
    a.MauSo = a.MauSo * b.MauSo;
    rutgon(a);
    return  a;
}
/*
Hàm: Chia
Chức năng: Tính thương hai phân số
Input: a, b (PhanSo)
Output: PhanSo: kết quả a / b (đã rút gọn)
Giải thích: a/b ÷ c/d = (a*d)/(b*c)
*/
PhanSo Chia(PhanSo a, PhanSo b){
    a.TuSo = a.TuSo * b.MauSo;
    a.MauSo = a.MauSo * b.TuSo;
    rutgon(a);
    return  a;
}
/*
Hàm: Xuat
Chức năng: Xuất phân số ra màn hình theo dạng hợp lệ
Input: a (PhanSo): phân số cần in
Output: In ra màn hình (không trả về giá trị)
Giải thích:
    - Xử lý các trường hợp đặc biệt:
        + Mẫu == 0 thì in Phan so co mau bang 0 khong hop le
        + Tử == 0 thì in 0
        + Tử == Mẫu thì in 1
        + Mẫu == 1 thì in số nguyên
        + Mẫu == -1 thì chuyển dấu lên tử
        + Mẫu âm thì chuyển dấu lên tử
*/
void Xuat(PhanSo a){
    if (a.MauSo == 0) cout << "Phan so co mau bang 0 khong hop le";
    else if (a.TuSo == 0) cout<<"0";
    else if (a.TuSo == a.MauSo) cout<<"1";
    else if (a.MauSo == 1) cout << a.TuSo;
    else if (a.MauSo == -1) cout << -a.TuSo;
    else if (a.MauSo < 0) cout << -a.TuSo <<"/"<< tuyetdoi(a.MauSo);
    else cout<<a.TuSo<<"/"<<a.MauSo; 
}
/*
Hàm: main
Chức năng: Chương trình chính
Input: Người dùng nhập 2 phân số
Output: In ra tổng, hiệu, tích, thương của 2 phân số
*/
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
