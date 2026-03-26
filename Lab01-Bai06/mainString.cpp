#include <iostream>
#include "String.h"
using namespace std;

int main() {
    String s1, s2;

    s1.Nhap();
    s2.Nhap();

    cout << "Chuoi 1: ";
    s1.Xuat();

    cout << "Chuoi 2: ";
    s2.Xuat();

    cout << "Do dai chuoi 1: " << s1.ChieuDai() << endl;

    s1.NoiChuoi(s2);
    cout << "Sau khi noi chuoi: ";
    s1.Xuat();

    s1.DaoChuoi();
    cout << "Sau khi dao chuoi: ";
    s1.Xuat();

    s1.ChuoiHoa();
    cout << "Chuoi hoa: ";
    s1.Xuat();

    s1.ChuoiThuong();
    cout << "Chuoi thuong: ";
    s1.Xuat();

    return 0;
}
