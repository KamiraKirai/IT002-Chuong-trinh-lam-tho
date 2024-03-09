#pragma once
#include "BaiTho.h"
class SongThatLucBat : public BaiTho {
	//Ý tưởng:
	//Cần ít nhất 2 câu 7 chữ, 1 cặp lục bát để tạo thành 1 bài thơ đúng nghĩa.
	//mod 4 == 1 sẽ là câu 7 chữ thứ nhất, mod 4 == 2 là câu 7 chữ thứ hai, mod 3 == 3 là câu lục và mod 4 == 0 là câu bát
public:
	void Nhap();
	bool KiemTra();
};