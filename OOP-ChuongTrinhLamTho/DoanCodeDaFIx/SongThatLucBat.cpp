#include "SongThatLucBat.h"
void SongThatLucBat::Nhap()
{
	GoToXY(85 - strlen("THE LOAI: Song that luc bat"), 2);
	TextColor(SetColorText2);
	cout << "THE LOAI: Song that luc bat";
	BaiTho::Nhap();
}
bool SongThatLucBat::KiemTra()
{
	if (SoCau % 4 != 0) return 0;
	int i = 1;
	while (i + 3 <= SoCau) { //Kiểm tra 4 câu cùng 1 lúc
		if ((i % 4 == 1 || i % 4 == 2) && (CauTho[i][8] != "")) return 0;
		if (i % 4 == 3 && (CauTho[i][7] != "")) return 0;
		if (i % 4 == 0 && (CauTho[i][9] != "")) return 0;
		if (!HiepVan(CauTho[i][7], CauTho[i + 1][5])) return 0; //Nếu chữ thứ 7 của câu thứ i không hiệp vần với chữ thứ 5 của câu thứ i+1 => return 0
		if (!HiepVan(CauTho[i + 1][7], CauTho[i + 2][6])) return 0; //Tương tự theo quy tắc của câu STLB
		if (!HiepVan(CauTho[i + 2][6], CauTho[i + 3][6])) return 0; //Tương tự theo quy tắc của câu STLB
		if ((i + 4 < SoCau) && (!HiepVan(CauTho[i + 3][8], CauTho[i + 4][5]))) return 0; //Tương tự theo quy tắc của câu STLB
		i += 4; //4 câu kế tiếp
	}
	return 1;
}