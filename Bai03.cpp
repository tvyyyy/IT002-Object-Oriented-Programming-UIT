#include <iostream>
#include <cmath>
#include <algorithm>
#include "cDSPhanSo.h"
using namespace std;
// cPhanSo:
cPhanSo::cPhanSo() {
	iTuSo = 0;
	iMauSo = 1;
};
cPhanSo::cPhanSo(int x, int y) {
	iTuSo = x;
	if (y == 0) {
		iMauSo = 1;
	}
	else iMauSo = y;
}
int cPhanSo::UCLN(int x, int y) {
	x = abs(x); y = abs(y);
	while (y != 0) {
		int result = x % y;
		x = y;
		y = result;
	}
	return x;
}
void cPhanSo::RutGon() {
	if (iTuSo == 0) {
		iMauSo = 1;
		return;
	}
	int u = UCLN(iTuSo, iMauSo);
	iTuSo /= u;
	iMauSo /= u;

	if (iMauSo < 0) {
		iMauSo /= -1;
		iTuSo /= -1;
	}
}
istream& operator>>(istream &in, cPhanSo &obj) {
	cout << "Nhap tu so: " << endl;
	in >> obj.iTuSo;
	cout << "Nhap mau so: " << endl;
	do {
		in >> obj.iMauSo;
	} while (obj.iMauSo == 0);
	return in;
}
ostream& operator<<(ostream& out, const cPhanSo& obj) {
	out << obj.getTuSo() << "/" << obj.getMauSo();
	return out;
}
int cPhanSo::getTuSo() const {
	return iTuSo;
}
int cPhanSo::getMauSo() const {
	return iMauSo;
}
void cPhanSo::setMauSo(int b) {
	if (b == 0) {
		cout << "Mau so ko dc bang 0!!";
		iMauSo = 1;
	}
	else iMauSo = b;
}
void cPhanSo::setTuSo(int b) {
	iTuSo = b;
}
bool checkPositive(const cPhanSo b) {
	if ((b.getTuSo() > 0 && b.getMauSo() > 0) || (b.getTuSo() < 0 && b.getMauSo() < 0)) return true;
	else return false;
}
bool checkNegative(const cPhanSo b) {
	if ((b.getTuSo() < 0 && b.getMauSo() > 0) || (b.getTuSo() > 0 && b.getMauSo() < 0)) return true;
	else return false;
}
// cDSPhanSo:
void cDSPhanSo::push_back(const cPhanSo& obj) {
	array.push_back(obj);
}
cDSPhanSo::cDSPhanSo(const cPhanSo& obj) {
	array.push_back(obj);
}
cDSPhanSo::cDSPhanSo() {}
istream& operator>>(istream& in, cDSPhanSo& obj) {
	int n;
	cout << "Nhap so luong phan tu cua array: ";
	in >> n;

	obj.array.clear();

	for (int i = 0; i < n; i++) {
		cPhanSo temp;
		in >> temp;
		obj.array.push_back(temp);
	}
	return in;
}
ostream& operator<< (ostream& out, const cDSPhanSo& obj) {
	for (int i = 0; i < obj.array.size(); i++) {
		out << obj.array[i] << " ";
	}
	return out;
}
cPhanSo cDSPhanSo::Sum() {
	cPhanSo result(0, 1);
	for (int i = 0; i < array.size(); i++) {
		int tu = array[i].getTuSo() * result.getMauSo() + array[i].getMauSo() * result.getTuSo();
		int mau = array[i].getMauSo() * result.getMauSo();
		result = cPhanSo(tu, mau);
		result.RutGon();
	}
	return result;
}
cPhanSo cDSPhanSo::Max() {
	if (array.empty()) {
		return cPhanSo(0, 1);
	}
	cPhanSo max = array[0];

	for (int i = 1; i < array.size(); i++) {
		if (max.getTuSo() * array[i].getMauSo() <
			array[i].getTuSo() * max.getMauSo()) {
			max = array[i];
		}
	}
	max.RutGon();
	return max;
}
cPhanSo cDSPhanSo::Min() {
	if (array.empty()) {
		return cPhanSo(0, 1);
	}
	cPhanSo min = array[0];

	for (int i = 1; i < array.size(); i++) {
		if (min.getTuSo() * array[i].getMauSo() >
			array[i].getTuSo() * min.getMauSo()) {
			min = array[i];
		}
	}
	min.RutGon();
	return min;
}
cDSPhanSo cDSPhanSo::TangDan() {
	cDSPhanSo result;
	result.array = array;
	int n = result.array.size();
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (result.array[j].getTuSo() * result.array[j + 1].getMauSo() >
				result.array[j + 1].getTuSo() * result.array[j].getMauSo()) {

				swap(result.array[j], result.array[j + 1]);
			}
		}
	}
	return result;
}
cDSPhanSo cDSPhanSo::GiamDan() {
	cDSPhanSo result;
	result.array = array;
	int n = result.array.size();
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (result.array[j].getTuSo() * result.array[j + 1].getMauSo() <
				result.array[j + 1].getTuSo() * result.array[j].getMauSo()) {
				swap(result.array[j], result.array[j + 1]);
			}
		}
	}
	return result;
}