#ifndef DMY_H
#define DMY_H
class DMY {
private:
	int iDay;
	int iMonth;
	int iYear;
public:
	void NhapNgay();
	void NhapThang();
	void NhapNam();
	void XuatDate();

	int getNgay();
	int getThang();
	int getNam();

	int daysInMonth(int x, int y);
	int TangNgay();
	int TangThang();
	int TangNam();

	void getThu();
	bool isLeap();
};
#endif
