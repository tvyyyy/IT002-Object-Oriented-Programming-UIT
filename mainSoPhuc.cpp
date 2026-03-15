#include <iostream>
#include "SoPhuc.h"
using namespace std;
int main() {
	SoPhuc x;
	SoPhuc y;
	x.NhapPhanThuc();
	x.NhapPhanAo();
	x.XuatSoPhuc();

	y.NhapPhanThuc();
	y.NhapPhanAo();
	y.XuatSoPhuc();
	
	SoPhuc z;
	z = x.Add(y);
	z.XuatSoPhuc();

	z = x.Sub(y);
	z.XuatSoPhuc();

	z = x.Multi(y);
	z.XuatSoPhuc();

	z = x.Div(y);
	z.XuatSoPhuc();

}