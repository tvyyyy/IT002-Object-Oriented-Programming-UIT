#include <iostream>
#include "DMY.h"
#include <cmath>
using namespace std;
void DMY::NhapNgay() {
	cout << "Nhap ngay: " << endl;
	cin >> iDay;
}
void DMY::NhapThang() {
	cout << "Nhap thang: " << endl;
	cin >> iMonth;
}
void DMY::NhapNam() {
	cout << "Nhap nam: " << endl;
	cin >> iYear;
}

int DMY::getNgay() {
	return iDay;
}
int DMY::getThang() {
	return iMonth;
}
int DMY::getNam() {
	return iYear;
}
int DMY::daysInMonth(int m, int y) {
	if (m == 2) {
		if ((y % 400 == 0) || (y % 4 == 0 && y % 100 != 0))
			return 29;
		return 28;
	}
	if (m == 4 || m == 6 || m == 9 || m == 11)
		return 30;
	return 31;
}
int DMY::TangNgay() {
	int j;
	cout << "Nhap so ngay muon tang: " << endl;
	cin >> j;

	while (j > 0) {
		iDay++;

		if (iDay > daysInMonth(iMonth, iYear)) {
			iDay = 1;
			iMonth++;

			if (iMonth > 12) {
				iMonth = 1;
				iYear++;
			}
		}
		j--;
	}

	return iDay;
}
int DMY::TangThang() {
	int j;
	cout << "Nhap so thang muon tang: " << endl;
	cin >> j;

	iMonth += j;

	while (iMonth > 12) {
		iMonth -= 12;
		iYear++;
	}

	if (iDay > daysInMonth(iMonth, iYear))
		iDay = daysInMonth(iMonth, iYear);

	return iMonth;
}
int DMY::TangNam() {
	int j;
	cout << "Nhap so nam muon tang: " << endl;
	cin >> j;

	iYear += j;

	if (iMonth == 2 && iDay == 29 && !isLeap())
		iDay = 28;

	return iYear;
}

void DMY::getThu() {
	int d = iDay;
	int m = iMonth;
	int y = iYear;

	if (m == 1 || m == 2) {
		m += 12;
		y--;
	}

	int k = y % 100;
	int p = y / 100;

	int h = (d + (13 * (m + 1)) / 5 + k + k / 4 + p / 4 + 5 * p) % 7;

	switch (h) {
	case 0: cout << "Saturday"; 
		break;
	case 1: cout << "Sunday"; 
		break;
	case 2: cout << "Monday"; 
		break;
	case 3: cout << "Tuesday"; 
		break;
	case 4: cout << "Wednesday"; 
		break;
	case 5: cout << "Thursday"; 
		break;
	case 6: cout << "Friday"; 
		break;
	}
}bool DMY::isLeap() {
	if (iYear % 400 == 0) return true;
	if (iYear % 100 == 0) return false;
	if (iYear % 4 == 0) return true;
	return false;
}