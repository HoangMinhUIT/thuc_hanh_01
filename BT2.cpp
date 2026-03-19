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
Output: Không trả về, nhưng gán giá trị cho b
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
    p.TuSo /= ucln;                     
    p.MauSo /= ucln;   
    if (p.MauSo < 0){
        p.TuSo = -p.TuSo;
        p.MauSo = -p.MauSo;
    }                 
}
/*
Hàm: SoSanh
Chức năng: So sánh 2 phân số a và b
Input:
    - a (PhanSo): phân số thứ nhất
    - b (PhanSo): phân số thứ hai
Output:
    - int:
        1  : nếu a > b
        0  : nếu a == b
       -1  : nếu a < b
Giải thích:
    - So sánh 2 phân số bằng cách quy đồng mẫu số:
        a = a.TuSo * b.MauSo
        b = b.TuSo * a.MauSo
    - Sau khi quy đồng, ta so sánh tử số
*/
int SoSanh (PhanSo a, PhanSo b){
    a.TuSo = a.TuSo*b.MauSo;
    b.TuSo = b.TuSo*a.MauSo;
    if (a.TuSo > b.TuSo) return 1;
    else if (a.TuSo == b.TuSo) return 0;
    else return -1;
}
/*
Hàm: Xuat
Chức năng: Xuất phân số ra màn hình theo dạng hợp lệ
Input: a (PhanSo): phân số cần in
Output: In ra màn hình (không trả về giá trị)
Giải thích:
    - Xử lý các trường hợp đặc biệt:
        + Tử == 0 thì in 0
        + Tử == Mẫu thì in 1
        + Mẫu == 1 thì in số nguyên
        + Mẫu == -1 thì chuyển dấu lên tử
        + Mẫu âm thì chuyển dấu lên tử
*/
void Xuat(PhanSo a) {
    if (a.TuSo == 0) cout << "0";
    else if (a.TuSo == a.MauSo) cout<<"1";
    else if (a.MauSo == 1) cout << a.TuSo;
    else if (a.MauSo == -1) cout << -a.TuSo;
    else if (a.MauSo < 0) cout<<-a.TuSo<<"/"<<tuyetdoi(a.MauSo);
    else cout << a.TuSo << "/" << a.MauSo;
}
/*
Hàm: main
Chức năng: Chương trình chính để nhập 2 phân số và tìm phân số lớn nhất
Input: Người dùng nhập 2 phân số từ bàn phím
Output: In ra phân số lớn nhất hoặc thông báo nếu 2 phân số bằng nhau
Giải thích:
    - Gọi hàm nhap thu 1 [Nhap(PhanSo &a)] để nhập phân số a 
    - Gọi hàm nhap thu 2 [PhanSo Nhap()] để nhập phân số b 
    - Gọi hàm SoSanh(a, b) để so sánh
    - Từ kết quả trả về:
        Nếu 1 thì a lớn hơn
        Nếu 0 thì bằng nhau
        Nếu -1 thì b lớn hơn
*/
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
