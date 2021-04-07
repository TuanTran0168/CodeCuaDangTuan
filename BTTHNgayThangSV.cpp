#include <iostream>
#include <fstream>
#include <string>
using namespace std;
const int MAX = 4000;
void ham_DocThongTinSinhVienTu_TapTin(int &sl, string AdressDoc);
void ham_InRaThongTInSinhVienCoNgayThangNhapVao(int sl, int &ngay, int &thang);

struct NTN
{
	int ngay, thang, nam;
};

struct SinhVien
{
	string mssv;
	string hotlot;
	string ten;
	NTN namsinh;
	string nganh;
	string que;
};
SinhVien DS[MAX + 1];
string AdressDoc, AdressGhi; //   D:\TXT\SinhVien.txt
int sl, stt, check;
int main()
{
	ham_DocThongTinSinhVienTu_TapTin(sl, AdressDoc);
	do
	{
		int ngay = 0, thang = 0; // RESET LẠI NGÀY VỚI THÁNG ĐỂ NHẬP TIẾP, NẾU KHÔNG CÓ THÌ NÓ SẼ DÙNG LẠI NGÀY THÁNG CŨ

		ham_InRaThongTInSinhVienCoNgayThangNhapVao(sl, ngay, thang);

		cout << "\nBan co muon lam tiep khong?\n1.Co\n0.Khong";
		cout << "\nNhap: ";
		cin >> check;
		system("cls");

	} while (check == 1);

	system("pause");
	return 0;
}
void ham_DocThongTinSinhVienTu_TapTin(int &sl, string AdressDoc)
{
	sl = 1;
	cout << "Nhap dia chi tap tin ban muon doc: ";
	getline(cin, AdressDoc);
	ifstream docFile;
	docFile.open(AdressDoc, ios::in);
	if (docFile.is_open())
	{
		cout << "\nDoc thanh cong tap tin!!!\n\n";
		while (docFile.eof() == false)
		{
			getline(docFile, DS[sl].mssv, ',');
			getline(docFile, DS[sl].hotlot, ',');
			getline(docFile, DS[sl].ten, ',');
			docFile >> DS[sl].namsinh.ngay;
			docFile.ignore(1);
			docFile >> DS[sl].namsinh.thang;
			docFile.ignore(1);
			docFile >> DS[sl].namsinh.nam;
			docFile.ignore(1);
			getline(docFile, DS[sl].nganh, ',');
			getline(docFile, DS[sl].que);
			sl++;
		}
		docFile.close();
	}
	else
	{
		cout << "\nKhong doc duoc tap tin!!\n";
		system("pause");
		exit(0);
	}
}

void ham_InRaThongTInSinhVienCoNgayThangNhapVao(int sl, int &ngay, int &thang)
{
	//cout << "\nNhap dia chi tap tin ban muon ghi: ";
	//cin >> AdressGhi;
	ofstream ghiFile;
	ghiFile.open("D:\\TXT\\NgayDThangM.txt", ios::app);		//Ghi tiếp tục vào tập tin không xóa dữ liệu
	if (ghiFile.is_open())
	{
		while (ngay < 1 || ngay > 31)
		{
			cout << "\nNhap vao ngay: ";
			cin >> ngay;
		}
		while (thang < 1 || thang > 12)
		{
			cout << "Nhap vao thang: ";
			cin >> thang;
		}

		for (int i = 1; i < sl; i++)
		{
			if (DS[i].namsinh.ngay == ngay && DS[i].namsinh.thang == thang)
			{
				ghiFile << "\nMa so sinh vien: " << DS[i].mssv;
				ghiFile << "\nHo va ten: " << DS[i].hotlot << " " << DS[stt].ten;
				ghiFile << "\nNgay sinh: " << DS[i].namsinh.ngay << '/' << DS[i].namsinh.thang << '/' << DS[i].namsinh.nam;
				ghiFile << "\nNganh hoc: " << DS[i].nganh;
				ghiFile << "\nQue quan: " << DS[i].que;
				ghiFile << endl;
			}
		}
		ghiFile << "\n====================***************====================\n"
				<< endl;
		cout << "\nGhi thanh cong !!";
		ghiFile.close();
	}
	else
		cout << "\nKhong mo duoc tap tin!!!";
}
