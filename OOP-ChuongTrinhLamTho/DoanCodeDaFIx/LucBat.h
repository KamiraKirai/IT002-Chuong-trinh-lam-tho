#pragma once
#include "BaiTho.h"

class LucBat : public BaiTho 
{

	//Ý tưởng: Cần ít nhất 1 cặp lục bát đi chung với nhau để tạo thành bài thơ đúng nghĩa.
	//Ta cho chỉ số của các câu lục là số lẻ, chỉ số của các câu bát là số chẵn.

public:
	void Nhap();
	bool KiemTra();
};