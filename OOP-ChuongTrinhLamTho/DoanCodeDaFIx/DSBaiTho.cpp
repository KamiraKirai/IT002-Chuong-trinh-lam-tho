#include "DSBaiTho.h"
int DSBaiTho::BaiThoDaiNhat(vector<BaiTho*> a)
{
	int index = 0;
	for (int i = 1; i < a.size(); i++)
		if (a[i]->SoCauTho() > a[index]->SoCauTho())
			index = i;
	return index;
}
int DSBaiTho::TimBaiTho(vector<BaiTho*> a, string ten) 
{
	for (int i = 0; i < a.size(); i++)
		if (a[i]->Ten() == ten)
			return i;
	return -1;
}
void DSBaiTho::Nhap()
{
	int d = Menu2(5, 5);
	BaiTho* tho;
	switch (d)
	{
	case 2: 
	{
		tho = new LucBat;
		tho->Nhap();
		tapTho.push_back(tho);
		break;
	}
	case 3: 
	{
		tho = new SongThatLucBat;
		tho->Nhap();
		tapTho.push_back(tho);
		break;
	}
	case 4: 
	{
		tho = new ThatNgonBatCu;
		tho->Nhap();
		tapTho.push_back(tho);
		break;
	}
	}
}
void DSBaiTho::KiemTra()
{
	while (chuc_nang != 5) 
	{
		system("cls"); // Xoa man hinh console truoc khi hien menu
		Menu(5, 5, chuc_nang);
		switch (chuc_nang) 
		{
		case 2: 
		{
			Nhap();
			break;
		}
		case 3: {
			tapTho[BaiThoDaiNhat(tapTho)]->Xuat();
			_getch();
			break;
		}
		case 4: 
		{
			string ten;
			GoToXY(75 - strlen("-Nhap ten bai: "), 2);
			TextColor(SetColorText2);
			cout << "-Nhap ten bai: ";
			TextColor(SetColorText);
			getline(cin, ten);
			int index = TimBaiTho(tapTho, ten);
			if (index == -1) 
			{
				GoToXY(75 - strlen("Khong thay bai tho can kiem tra!"), 6);
				cout << "Khong thay bai tho can kiem tra!";
			}
			else 
			{
				tapTho[index]->Xuat();
				if (tapTho[index]->KiemTra()) 
				{
					GoToXY(65, tapTho[index]->SoCauTho() + 7);
					TextColor(SetColorText3);
					cout << "Da dung luat tho!";
				}
				else 
				{
					GoToXY(65, tapTho[index]->SoCauTho() + 7);
					TextColor(SetColorText4);
					cout << "Khong dung luat tho!";
				}
			}
			_getch();
			break;
		}

		}
	}
	for (int i = 0; i < tapTho.size(); i++) 
	{
		delete tapTho[i];
	}
	tapTho.clear();
	
}