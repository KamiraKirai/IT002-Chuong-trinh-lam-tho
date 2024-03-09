#include "ThatNgonBatCu.h"
void ThatNgonBatCu::Nhap()
{
	GoToXY(85 - strlen("THE LOAI: That ngon bat cu"), 2);
	TextColor(SetColorText2);
	cout << "THE LOAI: That ngon bat cu";
	BaiTho::Nhap();
}
bool ThatNgonBatCu::KiemTra()
{
	if (SoCau != 8) return 0;
	for (int i = 1; i <= 8; i++) {
		if (CauTho[i][8] != "") return 0;
	}
	if (!HiepVan(CauTho[1][7], CauTho[2][7])) return 0;
	if (!HiepVan(CauTho[2][7], CauTho[4][7])) return 0;
	if (!HiepVan(CauTho[4][7], CauTho[6][7])) return 0;
	if (!HiepVan(CauTho[6][7], CauTho[8][7])) return 0;
	return 1;
}