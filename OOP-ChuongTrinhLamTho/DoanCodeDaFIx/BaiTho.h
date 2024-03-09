#pragma once
#include <iostream>
#include <Windows.h> // Ham do hoa
#include <iomanip>
#include <string>
#include <conio.h> 
#define SetColorText  15// mac dinh (mau trang)
#define SetColorText2 11 // mau xanh duong
#define SetColorText3 10 // xanh la
#define SetColorTable 7 // mau dac biet
#define SetColorText4 4 // mau do
#define SetColorText5 14 // mau vang
#define Width  110
#define Heigth  20
#define IndexLight  40
using namespace std;

const int MAX{ 10 };

const string kiTuDacBiet = "@#$%^&*_+-=[]{}|'<>"; //Để khai báo 1 mảng các kí tự đặc biệt để kiểm tra điều kiện trong hàm phương thức Nhap() của class BaiTho
void TextColor(int color); // Ham do hoa
void GoToXY(int x, int y);
string GetVan(string a);
bool HiepVan(string a, string b);
class BaiTho {

protected:
	string TenBaiTho;
	string CauTho[MAX][MAX]; 
	//khai bao mot mang hai chieu cauTho[m][n] de luu tru cac chu tho thu n - 1 cua cau tho m - 1 trong doan tho
	int SoCau = 0; //so cau ban dau se bang 0

public:
	string Ten();
	int SoCauTho();
	virtual void Nhap();
	virtual bool KiemTra() = 0;
	void Xuat();
};