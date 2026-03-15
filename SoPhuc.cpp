#include <iostream>
#include "SoPhuc.h"
#include <cmath>
using namespace std;
void SoPhuc::NhapPhanThuc() {
	cout << "Nhap phan thuc: " << endl;
	cin >> iPhanThuc;
}
void SoPhuc::NhapPhanAo() {
	cout << "Nhap phan ao: " << endl;
	cin >> iPhanAo;
}
void SoPhuc::XuatSoPhuc() {
	if (iPhanAo < 0) {
		cout << iPhanThuc << iPhanAo << "i" << endl;
	}
	else cout << iPhanThuc << "+" << iPhanAo << "i" << endl;
}
SoPhuc SoPhuc::Add(const SoPhuc b) {
	SoPhuc c;
	c.iPhanThuc = this->iPhanThuc + b.iPhanThuc;
	c.iPhanAo = this->iPhanAo + b.iPhanAo;
	return c;
}
SoPhuc SoPhuc::Sub(const SoPhuc b) {
	SoPhuc c;
	c.iPhanThuc = this->iPhanThuc - b.iPhanThuc;
	c.iPhanAo = this->iPhanAo - b.iPhanAo;
	return c;
}
SoPhuc SoPhuc::Multi(const SoPhuc b) {
	SoPhuc c;
	c.iPhanThuc = this->iPhanThuc * b.iPhanThuc - this->iPhanAo * b.iPhanAo;
	c.iPhanAo = this->iPhanThuc * b.iPhanAo + this->iPhanAo * b.iPhanThuc;
	return c;
}
SoPhuc SoPhuc::Div(const SoPhuc b) {
	SoPhuc c;
	int mau = pow(b.iPhanThuc, 2) + pow(b.iPhanAo, 2);
	c.iPhanThuc = (this->iPhanThuc * b.iPhanThuc + this->iPhanAo * b.iPhanAo) / mau;
	c.iPhanAo = (b.iPhanThuc * this->iPhanAo - this->iPhanThuc * b.iPhanAo) / mau;
	return c;
}