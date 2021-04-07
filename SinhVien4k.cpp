#include <iostream>
#include <fstream>
#include <string>
using namespace std;
const int MAX = 4000;
void ham_DocThongTinSinhVienTu_TapTin(int &sl, string AdressDoc);
void ham_GhiToanBoThongTinSinhVienVao_TapTin(int sl, string AdressGhi);
void ham_XuatToanBoThongTinSinhVienLen_ManHinh(int sl);

void ham_XuatThongTinSinhVienTheoSoThuTu_ManHinh(int sl);
void ham_XuatThongTinSinhVienTheoSoThuTu_TapTin(int sl);

void ham_InRaTenTheoChuCaiNhapVao_ManHinh(int sl);
void ham_InRaTenTheoChuCaiNhapVao_TapTin(int sl);

void ham_InRaDanhSachSinhVienTheoThang_ManHinh(int sl);
void ham_InRaDanhSachSinhVienTheoThang_TapTin(int sl);

void ham_InRaDanhSachSinhVienTheoMSSV_ManHinh(int sl);
void ham_InRaDanhSachSinhVienTheoMSSV_TapTin(int sl);

void ham_MENU(int &luachon);
void ham_ManHinhHayTapTin(int &MNhayTT);

void ham_InRaDanhSachSinhVienTheoThang_ManHinh_TapTin_VIP(int sl, int MHhayTT);
void ham_InRaDanhSachSinhVienTheoMSSV_ManHinh_TapTin_VIP(int sl, int MHhayTT);
void ham_InRaDanhSachSinhVienTheoChuCaiNhapVao_ManHinh_TapTin_VIP(int sl, int MHhayTT);
void ham_InRaThongTinSinhVienTheoSoThuTu_ManHinh_TapTin_VIP(int sl, int MHhayTT);

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

/******* KHAI BÁO BIẾN TOÀN CỤC CHO MẢNG ĐỂ XÀI FULL BÀI*******/
SinhVien DS[MAX + 1];
string AdressDoc, AdressGhi; //  D:\TXT\SinhVien.txt		D:\TXT\VL.txt
int sl, stt, check, luachon, MHhayTT;

int main()
{
    system("cls"); // Xóa mấy cái linh tinh trong terminal của visual studio code

    /*************************ĐỌC VÀ GHI DỮ LIỆU VÀO TẬP TIN***********************/
    ham_DocThongTinSinhVienTu_TapTin(sl, AdressDoc);
    //ham_GhiToanBoThongTinSinhVienVao_TapTin(sl, AdressGhi);

    /*************************MỘT VÀI CHỨC NĂNG KHÁC***********************/
    do
    {
        ham_MENU(luachon);
        if (luachon == 1)
        {
            ham_ManHinhHayTapTin(MHhayTT);
            ham_InRaDanhSachSinhVienTheoThang_ManHinh_TapTin_VIP(sl, MHhayTT);
        }

        if (luachon == 2)
        {
            ham_ManHinhHayTapTin(MHhayTT);
            ham_InRaDanhSachSinhVienTheoChuCaiNhapVao_ManHinh_TapTin_VIP(sl, MHhayTT);
        }

        if (luachon == 3)
        {
            ham_ManHinhHayTapTin(MHhayTT);
            ham_InRaDanhSachSinhVienTheoMSSV_ManHinh_TapTin_VIP(sl, MHhayTT);
        }

        if (luachon == 4)
        {
            ham_ManHinhHayTapTin(MHhayTT);
            ham_InRaThongTinSinhVienTheoSoThuTu_ManHinh_TapTin_VIP(sl, MHhayTT);
        }

        if (luachon == 5)
        {
            cout << "\n=================* KET THUC *=================";
            break;
        }

        cout << "\nBan co muon lam tiep khong ?\n1.Co\n0.Khong";
        cout << "\nHay nhap: ";
        cin >> check;
        fflush(stdin);
        system("cls");

    } while (check != 0);

    /*************************HẾT CHƯƠNG TRÌNH***********************/
    cout << endl;
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

void ham_GhiToanBoThongTinSinhVienVao_TapTin(int sl, string AdressGhi)
{
    cout << "Nhap dia chi tap tin ban muon ghi: ";
    getline(cin, AdressGhi);

    ofstream ghiFile;
    ghiFile.open(AdressGhi, ios::out);
    if (ghiFile.is_open())
    {
        for (int i = 1; i < sl; i++)
        {
            ghiFile << "\nSinh vien thu: " << i;
            ghiFile << "\nMa so sinh vien: " << DS[i].mssv;
            ghiFile << "\nHo va ten: " << DS[i].hotlot << " " << DS[i].ten;
            ghiFile << "\nNgay sinh: " << DS[i].namsinh.ngay << '/' << DS[i].namsinh.thang << '/' << DS[i].namsinh.nam;
            ghiFile << "\nNganh hoc: " << DS[i].nganh;
            ghiFile << "\nQue quan: " << DS[i].que;
            ghiFile << endl;
        }
        ghiFile.close();
        cout << "\nGhi thanh cong vao tap tin!!";
    }
    else
    {
        cout << "\nKhong doc duoc tap tin\n";
    }
}

void ham_InRaTenTheoChuCaiNhapVao_ManHinh(int sl)
{
    string TimKiem;
    int dem = 0;
    cout << "\n\nNhap chu cai hoac ten sinh vien ban muon tim: ";
    getline(cin, TimKiem);

    for (int i = 1; i < sl; i++)
    {
        int KQ = DS[i].ten.find(TimKiem, 0);
        if (KQ >= 0)
        {
            cout << DS[i].hotlot << " " << DS[i].ten << endl;
            dem++;
        }
    }
    cout << "\nSo sinh vien trong ten co chu (" << TimKiem << ") la: " << dem << endl;
}

void ham_InRaTenTheoChuCaiNhapVao_TapTin(int sl)
{
    cout << "Nhap dia chi tap tin ban muon ghi: ";
    getline(cin, AdressGhi);
    fflush(stdin);

    string TimKiem;
    int dem = 0;
    ofstream ghiFile;
    ghiFile.open(AdressGhi, ios::out);
    if (ghiFile.is_open())
    {
        cout << "\n\nNhap chu cai hoac ten sinh vien ban muon tim: ";
        getline(cin, TimKiem);
        fflush(stdin);

        for (int i = 1; i < sl; i++)
        {
            int KQ = DS[i].ten.find(TimKiem, 0);
            if (KQ >= 0)
            {
                ghiFile << DS[i].hotlot << " " << DS[i].ten << endl;
                dem++;
            }
        }
        ghiFile.close();
        cout << "\nGhi thanh cong vao tap tin!!";
    }
    else
    {
        cout << "\nKhong doc duoc tap tin\n";
    }

    cout << "\nSo sinh vien trong ten co chu (" << TimKiem << ") la: " << dem << endl;
}

void ham_XuatToanBoThongTinSinhVienLen_ManHinh(int sl)
{
    for (int i = 1; i < sl; i++)
    {
        cout << "\nSinh vien thu: " << i;
        cout << "\nMa so sinh vien: " << DS[i].mssv;
        cout << "\nHo va ten: " << DS[i].hotlot << " " << DS[i].ten;
        cout << "\nNgay sinh: " << DS[i].namsinh.ngay << '/' << DS[i].namsinh.thang << '/' << DS[i].namsinh.nam;
        cout << "\nNganh hoc: " << DS[i].nganh;
        cout << "\nQue quan: " << DS[i].que;
        cout << endl;
    }
}

void ham_XuatThongTinSinhVienTheoSoThuTu_ManHinh(int sl)
{
    do
    {
        cout << "\nNhap so thu tu cua sinh vien ban muon xem thong tin: ";
        cin >> stt;
        if (stt <= 0 || stt >= sl)
        {
            cout << "\nKhong co sinh vien o so thu tu nay";
            system("pause");
        }
    } while (stt <= 0 || stt >= sl);

    cout << "\nSinh vien co so thu tu: " << stt;
    cout << "\nMa so sinh vien: " << DS[stt].mssv;
    cout << "\nHo va ten: " << DS[stt].hotlot << " " << DS[stt].ten;
    cout << "\nNgay sinh: " << DS[stt].namsinh.ngay << '/' << DS[stt].namsinh.thang << '/' << DS[stt].namsinh.nam;
    cout << "\nNganh hoc: " << DS[stt].nganh;
    cout << "\nQue quan: " << DS[stt].que;
    cout << endl;
}

void ham_XuatThongTinSinhVienTheoSoThuTu_TapTin(int sl)
{
    cout << "\nNhap dia chi tap tin ban muon ghi: ";
    getline(cin, AdressGhi);
    fflush(stdin);

    ofstream ghiFile;
    ghiFile.open(AdressGhi, ios::out);
    if (ghiFile.is_open())
    {
        do
        {
            cout << "\nNhap so thu tu cua sinh vien ban muon xem thong tin: ";
            cin >> stt;
            if (stt <= 0 || stt >= sl)
            {
                cout << "\nKhong co sinh vien o so thu tu nay";
                system("pause");
            }
        } while (stt <= 0 || stt >= sl);

        for (int i = 1; i < sl; i++)
        {
            ghiFile << "\nSinh vien co so thu tu: " << stt;
            ghiFile << "\nMa so sinh vien: " << DS[stt].mssv;
            ghiFile << "\nHo va ten: " << DS[stt].hotlot << " " << DS[stt].ten;
            ghiFile << "\nNgay sinh: " << DS[stt].namsinh.ngay << '/' << DS[stt].namsinh.thang << '/' << DS[stt].namsinh.nam;
            ghiFile << "\nNganh hoc: " << DS[stt].nganh;
            ghiFile << "\nQue quan: " << DS[stt].que;
            ghiFile << endl;
        }
        ghiFile.close();
        cout << "\nGhi thanh cong vao tap tin!!";
    }
    else
    {
        cout << "\nKhong doc duoc tap tin\n";
    }
}

void ham_InRaDanhSachSinhVienTheoThang_ManHinh(int sl)
{
    int T;
    do
    {
        cout << "\nNhap thang: ";
        cin >> T;
    } while (T < 1 || T > 12);

    for (int i = 0; i < sl; i++)
    {
        if (DS[i].namsinh.thang == T)
        {
            cout << "\nMa so sinh vien: " << DS[i].mssv;
            cout << "\nHo va ten: " << DS[i].hotlot << " " << DS[stt].ten;
            cout << "\nNgay sinh: " << DS[i].namsinh.ngay << '/' << DS[i].namsinh.thang << '/' << DS[i].namsinh.nam;
            cout << "\nNganh hoc: " << DS[i].nganh;
            cout << "\nQue quan: " << DS[i].que;
            cout << endl;
        }
    }
}

void ham_InRaDanhSachSinhVienTheoThang_TapTin(int sl)
{

    cout << "Nhap dia chi tap tin ban muon ghi: ";
    getline(cin, AdressGhi);
    fflush(stdin);

    ofstream ghiFile;
    ghiFile.open(AdressGhi, ios::out);
    if (ghiFile.is_open())
    {
        int T;
        do
        {
            cout << "\nNhap thang: ";
            cin >> T;
        } while (T < 1 || T > 12);

        for (int i = 1; i < sl; i++)
        {
            if (DS[i].namsinh.thang == T)
            {
                ghiFile << "\nMa so sinh vien: " << DS[i].mssv;
                ghiFile << "\nHo va ten: " << DS[i].hotlot << " " << DS[stt].ten;
                ghiFile << "\nNgay sinh: " << DS[i].namsinh.ngay << '/' << DS[i].namsinh.thang << '/' << DS[i].namsinh.nam;
                ghiFile << "\nNganh hoc: " << DS[i].nganh;
                ghiFile << "\nQue quan: " << DS[i].que;
                ghiFile << endl;
            }
        }
        ghiFile.close();
        cout << "\nGhi thanh cong vao tap tin!!";
    }
    else
    {
        cout << "\nKhong doc duoc tap tin\n";
    }
}

void ham_InRaDanhSachSinhVienTheoMSSV_ManHinh(int sl)
{
    string MSSV;
    do
    {
        cout << "\nNhap MSSV: ";
        cin >> MSSV;
    } while (MSSV.length() < 1 || MSSV.length() > 8);

    for (int i = 0; i < sl; i++)
    {
        if (DS[i].mssv == MSSV)
        {
            cout << "\nMa so sinh vien: " << DS[i].mssv;
            cout << "\nHo va ten: " << DS[i].hotlot << " " << DS[stt].ten;
            cout << "\nNgay sinh: " << DS[i].namsinh.ngay << '/' << DS[i].namsinh.thang << '/' << DS[i].namsinh.nam;
            cout << "\nNganh hoc: " << DS[i].nganh;
            cout << "\nQue quan: " << DS[i].que;
            cout << endl;
        }
    }
}

void ham_InRaDanhSachSinhVienTheoMSSV_TapTin(int sl)
{
    cout << "Nhap dia chi tap tin ban muon ghi: ";
    getline(cin, AdressGhi);
    fflush(stdin);

    ofstream ghiFile;
    ghiFile.open(AdressGhi, ios::out);
    if (ghiFile.is_open())
    {
        string MSSV;
        do
        {
            cout << "\nNhap MSSV: ";
            cin >> MSSV;
        } while (MSSV.length() < 1 || MSSV.length() > 8);

        for (int i = 1; i < sl; i++)
        {
            if (DS[i].mssv == MSSV)
            {
                ghiFile << "\nMa so sinh vien: " << DS[i].mssv;
                ghiFile << "\nHo va ten: " << DS[i].hotlot << " " << DS[stt].ten;
                ghiFile << "\nNgay sinh: " << DS[i].namsinh.ngay << '/' << DS[i].namsinh.thang << '/' << DS[i].namsinh.nam;
                ghiFile << "\nNganh hoc: " << DS[i].nganh;
                ghiFile << "\nQue quan: " << DS[i].que;
                ghiFile << endl;
            }
        }
        ghiFile.close();
        cout << "\nGhi thanh cong vao tap tin!!";
    }
    else
    {
        cout << "\nKhong doc duoc tap tin\n";
    }
}

void ham_MENU(int &luachon)
{
    cout << "\n=======================MENU CHON LUA=====================\n";
    cout << "\n1.Nhap thang T, in ra DSSV thang T";
    cout << "\n2.Nhap chuoi S, in ra DSSV bat dau bang S";
    cout << "\n3.Nhap MSSV, in ra SYLL cua sinh vien";
    cout << "\n4.Nhap so thu tu, in ra thong tin sinh vien co so thu tu do";
    cout << "\n5.Ket Thuc\n";

    cout << "\nBan muon lam cau may: ";
    cin >> luachon;
}

void ham_ManHinhHayTapTin(int &MNhayTT)
{
    cout << "\nBan muon in ra man hinh hay tap tin?\n1.Man Hinh\n2.Tap Tin\n";
    cout << "\nNhap: ";
    cin >> MHhayTT;
    fflush(stdin);
}

void ham_InRaDanhSachSinhVienTheoChuCaiNhapVao_ManHinh_TapTin_VIP(int sl, int MHhayTT)
{
    if (MHhayTT == 1)
    {
        string TimKiem;
        int dem = 0;
        cout << "\n\nNhap chu cai hoac ten sinh vien ban muon tim: ";
        getline(cin, TimKiem);

        for (int i = 1; i < sl; i++)
        {
            int KQ = DS[i].ten.find(TimKiem, 0);
            if (KQ >= 0)
            {
                cout << DS[i].hotlot << " " << DS[i].ten << endl;
                dem++;
            }
        }
        cout << "\nSo sinh vien trong ten co chu (" << TimKiem << ") la: " << dem << endl;
    }
    else if (MHhayTT == 2)
    {
        cout << "Nhap dia chi tap tin ban muon ghi: ";
        getline(cin, AdressGhi);
        fflush(stdin);

        string TimKiem;
        int dem = 0;

        ofstream ghiFile;
        ghiFile.open(AdressGhi, ios::out);
        if (ghiFile.is_open())
        {
            cout << "\n\nNhap chu cai hoac ten sinh vien ban muon tim: ";
            getline(cin, TimKiem);
            fflush(stdin);

            for (int i = 1; i < sl; i++)
            {
                int KQ = DS[i].ten.find(TimKiem, 0);
                if (KQ >= 0)
                {
                    ghiFile << DS[i].hotlot << " " << DS[i].ten << endl;
                    dem++;
                }
            }
            ghiFile.close();
            cout << "\nGhi thanh cong vao tap tin!!";
        }
        else
        {
            cout << "\nKhong doc duoc tap tin\n";
        }

        cout << "\nSo sinh vien trong ten co chu (" << TimKiem << ") la: " << dem << endl;
    }
}

void ham_InRaDanhSachSinhVienTheoThang_ManHinh_TapTin_VIP(int sl, int MHhayTT)
{
    if (MHhayTT == 1)
    {
        int T;
        do
        {
            cout << "\nNhap thang: ";
            cin >> T;
        } while (T < 1 || T > 12);

        for (int i = 0; i < sl; i++)
        {
            if (DS[i].namsinh.thang == T)
            {
                cout << "\nMa so sinh vien: " << DS[i].mssv;
                cout << "\nHo va ten: " << DS[i].hotlot << " " << DS[stt].ten;
                cout << "\nNgay sinh: " << DS[i].namsinh.ngay << '/' << DS[i].namsinh.thang << '/' << DS[i].namsinh.nam;
                cout << "\nNganh hoc: " << DS[i].nganh;
                cout << "\nQue quan: " << DS[i].que;
                cout << endl;
            }
        }
    }

    else if (MHhayTT == 2)
    {
        cout << "Nhap dia chi tap tin ban muon ghi: ";
        getline(cin, AdressGhi);
        fflush(stdin);

        ofstream ghiFile;
        ghiFile.open(AdressGhi, ios::out);
        if (ghiFile.is_open())
        {
            int T;
            do
            {
                cout << "\nNhap thang: ";
                cin >> T;
            } while (T < 1 || T > 12);

            for (int i = 1; i < sl; i++)
            {
                if (DS[i].namsinh.thang == T)
                {
                    ghiFile << "\nMa so sinh vien: " << DS[i].mssv;
                    ghiFile << "\nHo va ten: " << DS[i].hotlot << " " << DS[stt].ten;
                    ghiFile << "\nNgay sinh: " << DS[i].namsinh.ngay << '/' << DS[i].namsinh.thang << '/' << DS[i].namsinh.nam;
                    ghiFile << "\nNganh hoc: " << DS[i].nganh;
                    ghiFile << "\nQue quan: " << DS[i].que;
                    ghiFile << endl;
                }
            }
            ghiFile.close();
            cout << "\nGhi thanh cong vao tap tin!!";
        }
        else
        {
            cout << "\nKhong doc duoc tap tin\n";
        }
    }
}

void ham_InRaDanhSachSinhVienTheoMSSV_ManHinh_TapTin_VIP(int sl, int MHhayTT)
{
    if (MHhayTT == 1)
    {
        string MSSV;
        do
        {
            cout << "\nNhap MSSV: ";
            cin >> MSSV;
        } while (MSSV.length() < 1 || MSSV.length() > 8);

        for (int i = 0; i < sl; i++)
        {
            if (DS[i].mssv == MSSV)
            {
                cout << "\nMa so sinh vien: " << DS[i].mssv;
                cout << "\nHo va ten: " << DS[i].hotlot << " " << DS[stt].ten;
                cout << "\nNgay sinh: " << DS[i].namsinh.ngay << '/' << DS[i].namsinh.thang << '/' << DS[i].namsinh.nam;
                cout << "\nNganh hoc: " << DS[i].nganh;
                cout << "\nQue quan: " << DS[i].que;
                cout << endl;
            }
        }
    }
    else if (MHhayTT == 2)
    {
        cout << "Nhap dia chi tap tin ban muon ghi: ";
        getline(cin, AdressGhi);
        fflush(stdin);

        ofstream ghiFile;
        ghiFile.open(AdressGhi, ios::out);
        if (ghiFile.is_open())
        {
            string MSSV;
            do
            {
                cout << "\nNhap MSSV: ";
                cin >> MSSV;
            } while (MSSV.length() < 1 || MSSV.length() > 8);

            for (int i = 1; i < sl; i++)
            {
                if (DS[i].mssv == MSSV)
                {
                    ghiFile << "\nMa so sinh vien: " << DS[i].mssv;
                    ghiFile << "\nHo va ten: " << DS[i].hotlot << " " << DS[stt].ten;
                    ghiFile << "\nNgay sinh: " << DS[i].namsinh.ngay << '/' << DS[i].namsinh.thang << '/' << DS[i].namsinh.nam;
                    ghiFile << "\nNganh hoc: " << DS[i].nganh;
                    ghiFile << "\nQue quan: " << DS[i].que;
                    ghiFile << endl;
                }
            }
            ghiFile.close();
            cout << "\nGhi thanh cong vao tap tin!!";
        }
        else
        {
            cout << "\nKhong doc duoc tap tin\n";
        }
    }
}

void ham_InRaThongTinSinhVienTheoSoThuTu_ManHinh_TapTin_VIP(int sl, int MHhayTT)
{
    if (MHhayTT == 1)
    {
        do
        {
            cout << "\nNhap so thu tu cua sinh vien ban muon xem thong tin: ";
            cin >> stt;
            if (stt <= 0 || stt >= sl)
            {
                cout << "\nKhong co sinh vien o so thu tu nay";
                system("pause");
            }
        } while (stt <= 0 || stt >= sl);

        cout << "\nSinh vien co so thu tu: " << stt;
        cout << "\nMa so sinh vien: " << DS[stt].mssv;
        cout << "\nHo va ten: " << DS[stt].hotlot << " " << DS[stt].ten;
        cout << "\nNgay sinh: " << DS[stt].namsinh.ngay << '/' << DS[stt].namsinh.thang << '/' << DS[stt].namsinh.nam;
        cout << "\nNganh hoc: " << DS[stt].nganh;
        cout << "\nQue quan: " << DS[stt].que;
        cout << endl;
    }
    else if (MHhayTT == 2)
    {
        cout << "\nNhap dia chi tap tin ban muon ghi: ";
        getline(cin, AdressGhi);
        fflush(stdin);

        ofstream ghiFile;
        ghiFile.open(AdressGhi, ios::out);
        if (ghiFile.is_open())
        {
            do
            {
                cout << "\nNhap so thu tu cua sinh vien ban muon xem thong tin: ";
                cin >> stt;
                if (stt <= 0 || stt >= sl)
                {
                    cout << "\nKhong co sinh vien o so thu tu nay";
                    system("pause");
                }
            } while (stt <= 0 || stt >= sl);

            ghiFile << "\nSinh vien co so thu tu: " << stt;
            ghiFile << "\nMa so sinh vien: " << DS[stt].mssv;
            ghiFile << "\nHo va ten: " << DS[stt].hotlot << " " << DS[stt].ten;
            ghiFile << "\nNgay sinh: " << DS[stt].namsinh.ngay << '/' << DS[stt].namsinh.thang << '/' << DS[stt].namsinh.nam;
            ghiFile << "\nNganh hoc: " << DS[stt].nganh;
            ghiFile << "\nQue quan: " << DS[stt].que;
            ghiFile << endl;

            ghiFile.close();
            cout << "\nGhi thanh cong vao tap tin!!";
        }
        else
        {
            cout << "\nKhong doc duoc tap tin\n";
        }
    }
}
