#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
const int MAX = 45;
using namespace std;
void ham_DocSinhVienTuTapTin(ifstream &docFile, struct SinhVien DS[MAX + 1], int &sl, string AdressDoc);
void ham_XuatToanBoSinhVienVaoTapTin(ofstream &ghiFile, struct SinhVien DS[MAX + 1], int sl, string AdressGhi);
void ham_XuatToanBoCacThongTinCuaSinhVien(struct SinhVien DS[MAX + 1], int n);
void ham_XuatSinhVienTheoSoThuTu(struct SinhVien DS[MAX + 1], int &stt, int n);
double ham_TinhDiemTB(struct SinhVien DS[MAX + 1], int stt);
void ham_XepLoai(struct SinhVien DS[MAX + 1], int stt);
void ham_XepLoaiTrongTapTin(ofstream &ghiFile, struct SinhVien DS[MAX + 1], int stt);

struct NTN // NTN = Ngày Tháng Năm
{
    int ngay, thang, nam;
};

struct SinhVien
{
    string mssv;
    string hoten;
    string diachi;
    NTN ngaysinh;
    double diemToan;
    double diemVan;
    double diemNgoaiNgu;
};

int main()
{
    SinhVien DS[MAX + 1];
    ifstream docFile;
    ofstream ghiFile;
    int sl, stt, check;
    string AdressDoc, AdressGhi;    //	D:\TXT\QuanLySinhVien.txt	D:\TXT\FileDeGhi.txt

    /*************************ĐỌC VÀ GHI DỮ LIỆU VÀO TẬP TIN***********************/
    ham_DocSinhVienTuTapTin(docFile, DS, sl, AdressDoc);
    ham_XuatToanBoSinhVienVaoTapTin(ghiFile, DS, sl, AdressGhi);
    system("pause");

    /*************************XUẤT TOÀN BỘ THÔNG TIN SINH VIÊN RA MÀN HÌNH***********************/
    ham_XuatToanBoCacThongTinCuaSinhVien(DS, sl);
    system("pause");

    /*************************XUẤT THÔNG TIN TỪNG SINH VIÊN THEO SỐ THỨ TỰ***********************/
    do
    {
        system("cls");
        ham_XuatSinhVienTheoSoThuTu(DS, stt, sl);
        cout << "\nBan co muon lam tiep khong? \n1.Co\n0.Khong";
        cout << "\nNhap: ";
        cin >> check;
        if (check != 1)
        {
            break;
        }

    } while (check == 1);
    
    /*******************************************HẾT************************************************/
    cout << endl;
    system("pause");
    return 0;
}

void ham_DocSinhVienTuTapTin(ifstream &docFile, struct SinhVien DS[MAX + 1], int &sl, string AdressDoc)
{
    sl = 1;
    cout << "\nNhap dia chi tap tin ban muon doc: ";
    getline(cin, AdressDoc);
    docFile.open(AdressDoc, ios::in);
    if (docFile.is_open())
    {
        cout << "\nMo File thanh cong!!\n\n";
        while (docFile.eof() == false)
        {
            getline(docFile, DS[sl].mssv, ',');
            getline(docFile, DS[sl].hoten, ',');
            getline(docFile, DS[sl].diachi, ',');
            docFile >> DS[sl].ngaysinh.ngay;
            docFile.ignore(1);
            docFile >> DS[sl].ngaysinh.thang;
            docFile.ignore(1);
            docFile >> DS[sl].ngaysinh.nam;
            docFile.ignore(1);
            docFile >> DS[sl].diemToan;
            docFile.ignore(1);
            docFile >> DS[sl].diemVan;
            docFile.ignore(1);
            docFile >> DS[sl].diemNgoaiNgu;
            docFile.ignore(1);
            sl++;
        }
        docFile.close();
    }
    else
    {
        cout << "\nKhong mo duoc File";
        return;
    }
}

void ham_XuatToanBoSinhVienVaoTapTin(ofstream &ghiFile, struct SinhVien DS[MAX + 1], int sl, string AdressGhi)
{
    cout << "\nNhap dia chi tap tin ban muon ghi: ";
    getline(cin, AdressGhi);
    ghiFile.open(AdressGhi, ios::out);
    if (ghiFile.is_open())
    {
        for (int i = 1; i < sl; i++)
        {
            ghiFile << "\n\t SINH VIEN THU " << i;
            ghiFile << "\nMa so sinh vien: " << DS[i].mssv;
            ghiFile << "\nHo ten sinh vien: " << DS[i].hoten;
            ghiFile << "\nDia chi sinh vien: " << DS[i].diachi;
            ghiFile << "\nNgay Thang Nam sinh sinh vien: " << DS[i].ngaysinh.ngay << '/' << DS[i].ngaysinh.thang << '/' << DS[i].ngaysinh.nam;
            ghiFile << "\nDiem mon Toan: " << DS[i].diemToan;
            ghiFile << "\nDiem mon Van: " << DS[i].diemVan;
            ghiFile << "\nDiem mon Ngoai Ngu: " << DS[i].diemNgoaiNgu;
            ghiFile << "\nDiem trung binh: " << ham_TinhDiemTB(DS, i);
            ham_XepLoaiTrongTapTin(ghiFile, DS, i);
        }
        cout << "\nDa ghi thanh cong thong tin vao tap tin\n";
        ghiFile.close();
    }
    else
        cout << "\nKhong mo duoc File";
}

void ham_XuatToanBoCacThongTinCuaSinhVien(struct SinhVien DS[MAX + 1], int n)
{
    for (int i = 1; i < n; i++)
    {
        cout << "\n\t SINH VIEN THU " << i;
        cout << "\nMa so sinh vien: " << DS[i].mssv;
        cout << "\nHo ten sinh vien: " << DS[i].hoten;
        cout << "\nDia chi sinh vien: " << DS[i].diachi;
        cout << "\nNgay Thang Nam sinh sinh vien: " << DS[i].ngaysinh.ngay << '/' << DS[i].ngaysinh.thang << '/' << DS[i].ngaysinh.nam;
        cout << "\nDiem mon Toan: " << DS[i].diemToan;
        cout << "\nDiem mon Van: " << DS[i].diemVan;
        cout << "\nDiem mon Ngoai Ngu: " << DS[i].diemNgoaiNgu;
        cout << "\nDiem trung binh: " << ham_TinhDiemTB(DS, i);
        ham_XepLoai(DS, i);
        cout << endl;
    }
}

double ham_TinhDiemTB(struct SinhVien DS[MAX + 1], int stt)
{
    return ((DS[stt].diemToan + DS[stt].diemVan) * 2 + DS[stt].diemNgoaiNgu) / 5;
}

void ham_XuatSinhVienTheoSoThuTu(struct SinhVien DS[MAX + 1], int &stt, int n)
{
    do
    {
        cout << "\n\nNhap so thu tu sinh vien ban muon xem thong tin: ";
        cin >> stt;
        if (stt < 1 || stt >= n)
        {
            cout << "Khong tim thay sinh vien";
        }
    } while (stt < 1 || stt >= n);
    cout << "\n\t SINH VIEN THU " << stt;
    cout << "\nMa so sinh vien: " << DS[stt].mssv;
    cout << "\nHo ten sinh vien: " << DS[stt].hoten;
    cout << "\nDia chi sinh vien: " << DS[stt].diachi;
    cout << "\nNgay Thang Nam sinh sinh vien: " << DS[stt].ngaysinh.ngay << '/' << DS[stt].ngaysinh.thang << '/' << DS[stt].ngaysinh.nam;
    cout << "\nDiem mon Toan: " << DS[stt].diemToan;
    cout << "\nDiem mon Van: " << DS[stt].diemVan;
    cout << "\nDiem mon Ngoai Ngu: " << DS[stt].diemNgoaiNgu;
    cout << "\nDiem trung binh: " << ham_TinhDiemTB(DS, stt);
    ham_XepLoai(DS, stt);
    cout << endl;
}

void ham_XepLoai(struct SinhVien DS[MAX + 1], int stt)
{
    if (ham_TinhDiemTB(DS, stt) >= 8)
    {
        cout << "\nXep loai Gioi";
    }
    else if (ham_TinhDiemTB(DS, stt) >= 6.5)
    {
        cout << "\nXep loai Kha";
    }
    else if (ham_TinhDiemTB(DS, stt) >= 5)
    {
        cout << "\nXep loai Trung Binh";
    }
    else
    {
        cout << "\nXep loai Duoi Trung Binh";
    }
}

void ham_XepLoaiTrongTapTin(ofstream &ghiFile, struct SinhVien DS[MAX + 1], int stt)
{
    if (ham_TinhDiemTB(DS, stt) >= 8)
    {
        ghiFile << "\nXep loai Gioi";
    }
    else if (ham_TinhDiemTB(DS, stt) >= 6.5)
    {
        ghiFile << "\nXep loai Kha";
    }
    else if (ham_TinhDiemTB(DS, stt) >= 5)
    {
        ghiFile << "\nXep loai Trung Binh";
    }
    else
    {
        ghiFile << "\nXep loai Duoi Trung Binh";
    }
}
