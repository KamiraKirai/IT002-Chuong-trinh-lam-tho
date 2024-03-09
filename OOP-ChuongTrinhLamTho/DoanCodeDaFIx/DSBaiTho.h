#pragma once
#include "BaiTho.h"
#include "LucBat.h"
#include "SongThatLucBat.h"
#include "ThatNgonBatCu.h"
#include <vector>
void Menu(int x, int y, int& chucNang);
int Menu2(int x, int y);
class DSBaiTho
{
private:
	int chuc_nang = 2;
	vector<BaiTho*> tapTho;
public:
	int BaiThoDaiNhat(vector<BaiTho*> a);
	int TimBaiTho(vector<BaiTho*> a, string ten);
	void Nhap();
	void KiemTra();
};