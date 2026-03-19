#include <iostream>
using namespace std;

/*
    struct date
    Chức năng: Lưu trữ thông tin một ngày
    Thuộc tính:
        - day: ngày
        - month: tháng
        - year: năm
*/
struct date{
    int day, month, year;
};
/*
    Hàm: check_nhuan
    Chức năng: Kiểm tra một năm có phải năm nhuận hay không
    Input: a: kiểu date (chỉ sử dụng a.year)
    Output:
        - Trả về 1 nếu là năm nhuận
        - Trả về 0 nếu không phải năm nhuận
    Quy tắc năm nhuận:
        - Năm chia hết cho 4 và không chia hết cho 100
        - Hoặc chia hết cho 400
*/
int check_nhuan(date a){
    if ((a.year % 4 == 0 && a.year % 100 != 0) || (a.year % 400 == 0)) return 1;
    return 0;
}
/*
    Hàm: nhap_lai
    Chức năng: Nhập lại ngày
    Input: a (tham chiếu): sẽ cập nhật lại a.day
    Output:
        - Không trả về giá trị
        - Thay đổi trực tiếp a.day
*/
void nhap_lai(date &a){
    cin >> a.day;
}
/*
    Hàm: nhap_lai_thang
    Chức năng: Nhập lại tháng
    Input: a (tham chiếu): sẽ cập nhật lại a.month
    Output: 
     - Không trả về giá trị
     - Thay đổi trực tiếp a.month
*/
void nhap_lai_thang(date &a){
    cin >> a.month;
}
/*
    Hàm: nhap_lai_nam
    Chức năng: Nhập lại năm
    Input: a (tham chiếu): sẽ cập nhật lại a.year
    Output:
        - Không trả về giá trị
        - Thay đổi trực tiếp a.year
*/
void nhap_lai_nam(date &a){
    cin >> a.year;
}
/*
    Hàm: input
    Chức năng: Nhập đầy đủ ngày, tháng, năm từ bàn phím
    Input: a (tham chiếu)
    Output:
        - Không trả về
        - Gán giá trị cho a.day, a.month, a.year
*/
void input(date &a){
    cout << "Nhap ngay: "; cin >> a.day;
    cout << "Nhap thang: "; cin >> a.month;
    cout << "Nhap nam: "; cin >> a.year;
}
/*
    Hàm: output
    Chức năng:
        - Kiểm tra tính hợp lệ của ngày/tháng/năm
        - Nếu sai thì yêu cầu nhập lại
        - Nếu đúng thì in ra NGÀY KẾ TIẾP
    Input: a (tham chiếu)
    Output:
        - Không trả về
        - In ra ngày tiếp theo
    Cách hoạt động:
        1. Kiểm tra năm
             nếu < 1 thì nhập lại
        2. Kiểm tra tháng
            nếu không trong [1,12] thì nhập lại
        3. Kiểm tra ngày
             nếu không hợp lệ thì nhập lại
        4. Xử lý theo từng trường hợp:
            - Tháng 2 (có xét năm nhuận)
            - Tháng 30 ngày (4,6,9,11)
            - Tháng 31 ngày
            - Cuối năm (31/12)
        5. In ra ngày kế tiếp
*/
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
    input(a); // Nhập ngày
    cout << "Ngay ke tiep la: ";
    output(a); // Xuất ngày kế tiếp
    return 0;
}
