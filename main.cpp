#include <iostream>
#include "cPhanSo.h"
using namespace std;

int main() {
    cPhanSo a;
    a.NhapTuSo();
    a.NhapMauSo();

    cPhanSo b;
    b.NhapTuSo();
    b.NhapMauSo();

    cPhanSo c;

     c = a.Add(b);
     c.XuatPhanSo();

     c = a.Sub(b);
     c.XuatPhanSo();

     c = a.Divide(b);
     c.XuatPhanSo();

     c = a.Multi(b);
     c.XuatPhanSo();
}