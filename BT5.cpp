#include <iostream>
#include <iomanip>
#include <string.h>
#include <sstream>
using namespace std;

// Cấu trúc lưu thông tin học sinh
struct HocSinh{
    string hoTen;      // Họ tên học sinh
    double DiemToan;   // Điểm Toán
    double DiemVan;    // Điểm Văn
    double dtb;        // Điểm trung bình
};

/*
    Hàm: ChuanHoaTen
    Input: 1 biến HocSinh (tham chiếu)
    Output: Không trả về giá trị (void), nhưng thay đổi trực tiếp hoTen

    Chức năng:
    - Chuẩn hóa tên học sinh:
        + Viết hoa chữ cái đầu mỗi từ
        + Các chữ còn lại viết thường
    - Ví dụ: "nGUYEn vaN a" -> "Nguyen Van A"
*/
void ChuanHoaTen(HocSinh &p){
    stringstream ss(p.hoTen);
    string res, w;

    while (ss >> w){
        res += toupper(w[0]); // viết hoa chữ đầu
        for (int i=1; i<w.size(); i++){
            res += tolower(w[i]); // các chữ còn lại viết thường
        }
        res += " ";
    }

    res.pop_back(); // xóa dấu cách cuối
    p.hoTen = res;
}

/*
    Hàm: check_digit
    Input: 1 biến HocSinh (tham chiếu)
    Output: Không trả về, nhưng gán giá trị hợp lệ cho DiemToan và DiemVan

    Chức năng:
    - Nhập điểm Toán và Văn từ bàn phím
    - Kiểm tra:
        + Phải là số
        + Nằm trong khoảng [0, 10]
    - Nếu sai:
        + Xóa lỗi nhập (cin.clear)
        + Bỏ dữ liệu sai (cin.ignore)
        + Yêu cầu nhập lại
*/
void check_digit(HocSinh &a){
    cout << "Nhap diem Toan: ";
    while((!(cin >> a.DiemToan)) || a.DiemToan < 0 || a.DiemToan > 10){
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Nhap sai! Vui long nhap lai diem Toan: ";
    }

    cout << "Nhap diem Van: ";
    while((!(cin >> a.DiemVan)) || a.DiemVan < 0 || a.DiemVan > 10){
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Nhap sai! Vui long nhap lai diem Van: ";
    }
}

/*
    Hàm: input
    Input: 1 biến HocSinh (tham chiếu)
    Output: Không trả về, nhưng cập nhật toàn bộ thông tin học sinh

    Chức năng:
    - Nhập họ tên (dùng getline)
    - Gọi hàm check_digit để nhập điểm hợp lệ
    - Tính điểm trung bình:
        dtb = (Toán + Văn) / 2
*/
void input(HocSinh &a){
    getline(cin, a.hoTen);
    check_digit(a);
    a.dtb = (a.DiemToan + a.DiemVan)/2;
}

/*
    Hàm: output
    Input: 1 biến HocSinh (truyền giá trị)
    Output: In thông tin ra màn hình

    Chức năng:
    - Chuẩn hóa tên trước khi in
    - In:
        + Họ tên
        + Điểm Toán, Văn
        + Điểm trung bình (3 chữ số có nghĩa)
*/
void output(HocSinh a){
    ChuanHoaTen(a);
    cout << a.hoTen<<" ";
    cout << "Toan: " << a.DiemToan << " " << "Van: " <<a.DiemVan << " ";
    cout << setprecision(3) << "DTB: " << a.dtb;
    cout << endl;
}

/*
    Hàm main
    Chức năng:
    - Tạo biến học sinh
    - Gọi hàm nhập
    - Gọi hàm xuất
*/
int main(){
    HocSinh a;
    input(a);
    output(a);
    return 0;
}