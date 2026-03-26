#ifndef SOPHUC_H
#define SOPHUC_H
class SoPhuc {
private:
	int iPhanThuc;
	int iPhanAo;
public:
	void NhapPhanThuc();
	void NhapPhanAo();
	void XuatSoPhuc();
	SoPhuc Add(const SoPhuc b);
	SoPhuc Sub(const SoPhuc b);
	SoPhuc Multi(const SoPhuc b);
	SoPhuc Div(const SoPhuc b);
};
#endif
