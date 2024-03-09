#include "BaiTho.h"
using namespace std;

// Ham ben ngoai
string GetVan(string a) 
{ //Truyền vào 1 chữ thơ
	int i = 0; //i ở đây sẽ là chỉ số cho từng kí tự trong chữ thơ đó
	if (a[0] == 'q' || a[0] == 'g') i = 2; //Nếu kí tự đó là q, g thì chúng ta sẽ xét thẳng tới kí tự thứ 3 của nó (ví dụ chữ "quân" thì ta chỉ cần xét vần từ kí tự 'â' trở đi)
	//Xét chữ thơ đó, nếu gặp một nguyên âm thì ta sẽ lấy vần từ đó trở đi. (Ví dụ chữ "nguyên" thì ta sẽ lấy vần "uyên" từ kí tự u trở đi), Hai vòng lặp for sẽ có nhiệm vụ như vậy.

	for (i; i < a.length(); i++)
	{
		if (a[i] == 'a' || a[i] == 'u' || a[i] == 'i' || a[i] == 'e' || a[i] == 'o' || a[i] == 'y')
			break;
	}
	string Van = "";
	for (int j = i; j < a.length(); j++)
	{
		if (a[j] == '.' || a[j] == '?' || a[j] == ',' || a[j] == ':' || a[j] == ';'|| a[j] == '!'||a[j] =='"')
		{
			a.erase(a.begin() + j);
		}
		else 
			Van.push_back(a[j]);
	}
	return Van;
}

// Ham ben ngoai
bool HiepVan(string a, string b) { //Truyền vào 2 chữ thơ để xét vần
	string VanA = GetVan(a); //Lấy vần
	string VanB = GetVan(b); //Lấy vần
	int thdb = 0; //thdb dùng để xét các trường hợp đặc biệt (ví dụ "buồn" vẫn vần với "khôn", "hoa" vẫn vần với "tà")
	if (VanA == "uon" && VanB == "on")
		thdb++;
	if (VanA == "on" && VanB == "uon")
		thdb++;
	if (VanA == "oa" && VanB == "a")
		thdb++;
	if (VanA == "a" && VanB == "oa")
		thdb++;
	if (VanA == "uoi" && VanB == "oi")
		thdb++;
	if (VanA == "oi" && VanB == "uoi")
		thdb++;
	if ((VanA == VanB) || (thdb == 1)) 
		return 1; //Xét điều kiện nếu 2 chữ vần với nhau hoặc gặp thdb thì sẽ trả về 1 (true)
	return 0;
}
string BaiTho::Ten()
{
	return TenBaiTho;
}
int BaiTho::SoCauTho()
{
	return SoCau;
}
void BaiTho::Nhap()
{
	TextColor(SetColorText2);
	GoToXY(75 - strlen("-Ten bai tho: "), 4);
	cout << "- Ten bai tho: ";
	TextColor(SetColorText);
	getline(cin, TenBaiTho);
	TextColor(SetColorText2);
	GoToXY(60 - strlen("-Nhap bai tho: "), 6);
	cout << "- Nhap bai tho: ";
	TextColor(SetColorText);
	/*string temp;*/
	string s = "";
	//Khởi tạo một vòng lặp do while để nhập thơ, sẽ kết thúc khi gặp "/" và break khỏi vòng lặp
	do {

		GoToXY(45 + s.size(), SoCau + 7);
		//cin >> temp;
		char c = _getch(); // Khong hien thi ky tu nhap vao, nhap "/" se khong thay ki tu do.
		switch (c) {
		case '/': {
			return;
		}
		case 13: {
			SoCau++;
			int j = 1;
			s += " ";
			for (int i = 0; i < s.size(); i++) {
				if (s[i] == 32) {
					CauTho[SoCau][j++] = s.substr(0, i);
					s = s.substr(i + 1);
					i = -1;
				}
			}
			s = "";
			break;
		}
		case 8: {
			if (s.length() > 0)
				s.erase(s.length() - 1);
			GoToXY(45 + s.size(), SoCau + 7);
			cout << " "; // In khoang trang de ghi de len cac ki tu da bi xoa
			break;
		}
		default: {
			if (kiTuDacBiet.find(c) == -1) {
				s += c;
			}
			GoToXY(45 + s.size() - 1, SoCau + 7);
			cout << c;
		}
		}
	} while (true);
}
void BaiTho::Xuat()
{

	/*if (KiemTra()) {*/
	TextColor(SetColorText2);
	GoToXY(75 - strlen("-Tieu de: "), 3);
	cout << "-Tieu de: ";
	TextColor(SetColorText);
	cout << TenBaiTho << endl;
	for (int i = 1; i <= SoCau; i++) {
		int chu = 1;
		string s = "";
		while (CauTho[i][chu] != "") {
			s += CauTho[i][chu++] + " ";
		}
		GoToXY(55, 4 + i);
		cout << s;
	}
	//}
}
