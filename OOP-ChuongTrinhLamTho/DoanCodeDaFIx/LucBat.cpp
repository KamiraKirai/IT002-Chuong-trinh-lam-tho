#include "LucBat.h"
void LucBat::Nhap()
{
	GoToXY(85 - strlen("THE LOAI: Luc bat"), 2);
	TextColor(SetColorText2);
	cout << "THE LOAI: Luc bat";
	BaiTho::Nhap();
}
bool LucBat::KiemTra()
{
	if (SoCau % 2 != 0) //Nếu số câu là số lẻ thì không thoả điều kiện, trả về 0
		return 0;
	for (int i = 1; i <= SoCau; i++) {
		if (i % 2 == 1 && (CauTho[i][7] != "")) return 0; //Nếu chỉ số lẻ (tức câu lục) có quá 6 chữ thì trà về 0
		if (i % 2 == 0 && (CauTho[i][9] != "")) return 0; //Nếu chỉ số chẵn (câu bát) có quá 8 chữ thì trả về 0
		if (i % 2 == 1 && !HiepVan(CauTho[i][6], CauTho[i + 1][6])) return 0; //Nếu chữ thứ 6 của cây lục ko hợp vần chữ thứ 6 câu bát => trả về 0
		if (i % 2 == 0 && i != SoCau && !HiepVan(CauTho[i][8], CauTho[i + 1][6])) return 0; //Nếu câu bát đang xét ko phải là câu bát cuối cùng trong đoạn thơ, chữ thứ 8 ko hợp vần vs chữ thứ 6 của câu lục tiếp theo => trả về 0
	}
	return 1;
}


