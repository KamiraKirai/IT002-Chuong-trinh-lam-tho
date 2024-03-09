
//Menu.cpp dung de tao giao dien menu cho chuong trinh
#include <Windows.h> // Ham do hoa
#include <iomanip> // Ham setw()
#include <conio.h> 
#include <string>
#include <iostream>
#define SetColorText 15 // mac dinh (mau trang)
#define SetColorText2 11 // mau xanh duong
#define SetColorText3 10 // xanh la
#define SetColorTable 7 // mau dac biet
#define SetColorText4 4 // mau do
#define SetColorText5 14 // mau vang
#define Width  110
#define Heigth  20
#define IndexLight  40
using namespace std;
void TextColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}// Ham do hoa
void GoToXY(int x, int y)
{ // x la ngang, y la doc
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}// Ham di chuyen con tro
void Menu(int x, int y, int& ChucNang) 
{
	TextColor(SetColorTable);
	for (int i = 0; i < Heigth; i++) { // Ve khung doc
		GoToXY(0, i);
		cout << char(178) << char(176);
		GoToXY(Width, i);
		cout << char(176) << char(178);
		GoToXY(IndexLight, i);
		cout << char(177);
	}
	for (int i = 0; i <= Width + 1; i++) { // Ve khung ngang
		GoToXY(i, 0);
		cout << char(178);
		GoToXY(i, Heigth);
		cout << char(178);
	}
	string hd1 = "Huong dan: Nhan phim / de ket";
	string hd2 = " thuc nhap tho";
	string s[] = { "CHUC NANG", "", "Soan tho", "Tim bai tho dai nhat", "Kiem tra luat tho", "Thoat" };
	TextColor(SetColorText5);
	GoToXY(x, y - 3);
	cout << setw(15 - hd1.size() / 2) << " " << hd1;
	GoToXY(x, y - 2);
	cout << setw(15 - hd2.size() / 2) << " " << hd2;
	TextColor(SetColorText);
	for (int i = 0; i < 6; i++) {
		GoToXY(x, y + i * 2); // Dich chuyen toa do cua cac dong chu
		cout << setw(15 - s[i].size() / 2) << " " << s[i];// Can giua cac chuoi, tao khoang trong ben trai chuoi
	}

	// Danh dau lua chon
	TextColor(SetColorText2);
	GoToXY(x, y + ChucNang * 2);
	cout << setw(15 - s[ChucNang].size() / 2) << " " << s[ChucNang];
	TextColor(SetColorText);

	while (true) {
		if (_kbhit()) { // Ham kiem tra lieu nguoi dung co nhap tu ban phim khong
			char c = _getch(); // Neu co thi ham getch() se doc ky tu nhap vao tu ban phim
			switch (c) {
			case 72: { // Nut di len
				if (ChucNang == 2)
					ChucNang = 5;
				else
					ChucNang--;
				break;
			}
			case 80: { // Nut di xuong
				if (ChucNang == 5)
					ChucNang = 2;
				else
					ChucNang++;
				break;
			}
			case 13: { // Dau Enter
				return;
			}
			}
			for (int i = 0; i < 6; i++) {
				GoToXY(x, y + i * 2);
				cout << setw(15 - s[i].size() / 2) << " " << s[i];
			}
			// Moi lan ta di chuyen den lua chon se to mau lua chon do
			TextColor(SetColorText2);
			GoToXY(x, y + ChucNang * 2);
			cout << setw(15 - s[ChucNang].size() / 2) << " " << s[ChucNang];
			TextColor(SetColorText);
		}
	}
}
int Menu2(int x, int y) {
	int ChucNang = 2;
	TextColor(SetColorTable);

	// Ve duong doc
	for (int i = 0; i < Heigth; i++) {
		GoToXY(0, i);
		cout << char(178) << char(176);
		GoToXY(Width, i);
		cout << char(176) << char(178);
		GoToXY(IndexLight, i);
		cout << char(177);
	}

	// Ve duong doc
	for (int i = 0; i <= Width + 1; i++) {
		GoToXY(i, 0);
		cout << char(178);
		GoToXY(i, Heigth);
		cout << char(178);
	}

	//Can giua dua tren do dai cua cac chuoi va in ra man hinh
	string s[] = { "THE LOAI THO", "", "Luc bat", "  Song that luc bat  ", "That ngon bat cu Duong luat", "Thoat" };
	TextColor(SetColorText);
	for (int i = 0; i < 6; i++) {
		GoToXY(x, y + i * 2);
		cout << setw(15 - s[i].size() / 2) << " " << s[i];
	}

	// Danh dau lua chon
	TextColor(SetColorText2);
	GoToXY(x, y + ChucNang * 2);
	cout << setw(15 - s[ChucNang].size() / 2) << " " << s[ChucNang];
	TextColor(SetColorText);

	while (true) {
		if (_kbhit()) {
			char c = _getch();
			for (int i = 0; i < 6; i++) {
				GoToXY(x, y + i * 2);
				cout << setw(15 - s[i].size() / 2) << " " << s[i];
			}
			switch (c) {
			case 72: {
				if (ChucNang == 2)
					ChucNang = 5;
				else
					ChucNang--;
				break;
			}
			case 80: {
				if (ChucNang == 5)
					ChucNang = 2;
				else
					ChucNang++;
				break;
			}
			case 13: {
				return ChucNang;
			}
			}
			for (int i = 0; i < 6; i++) {
				GoToXY(x, y + i * 2);
				cout << setw(15 - s[i].size() / 2) << " " << s[i];
			}
			TextColor(SetColorText2);
			GoToXY(x, y + ChucNang * 2);
			cout << setw(15 - s[ChucNang].size() / 2) << " " << s[ChucNang];
			TextColor(SetColorText);
		}
	}
}