#include <bits/stdc++.h>
using namespace std;


class NhanVien {
protected:
    string Manhanvien;
    string Hoten;
    int Tuoi;
    string Sodienthoai;
    string Email;
    float Luongcoban;

public:
    NhanVien(string Manhanvien, string Hoten, int Tuoi, string Sodienthoai, string Email, float Luongcoban)
        : Manhanvien(Manhanvien), Hoten(Hoten), Tuoi(Tuoi), Sodienthoai(Sodienthoai), Email(Email), Luongcoban(Luongcoban) {}

    virtual ~NhanVien() = default; // Destructor 

    virtual float tinhLuong() const = 0;
    virtual void xuatThongTin() const = 0;
};


class LapTrinhVien : public NhanVien {
private:
    int Sogiolamthem;

public:
    LapTrinhVien(string Manhanvien, string Hoten, int Tuoi, string Sodienthoai, string Email, float Luongcoban, int Sogiolamthem)
        : NhanVien(Manhanvien, Hoten, Tuoi, Sodienthoai, Email, Luongcoban), Sogiolamthem(Sogiolamthem) {}

    float tinhLuong() const override {
        return Luongcoban + Sogiolamthem * 200000;
    }

    void xuatThongTin() const override {
        cout << setw(15) << "Lap Trinh Vien" << setw(15) << Manhanvien << setw(20) << Hoten << setw(10) << tinhLuong() << '\n';
    }
};


class KiemChungVien : public NhanVien {
private:
    int Soloiphathien;

public:
    KiemChungVien(string Manhanvien, string Hoten, int Tuoi, string Sodienthoai, string Email, float Luongcoban, int Soloiphathien)
        : NhanVien(Manhanvien, Hoten, Tuoi, Sodienthoai, Email, Luongcoban), Soloiphathien(Soloiphathien) {}

    float tinhLuong() const override {
        return Luongcoban + Soloiphathien * 50000;
    }

    void xuatThongTin() const override {
        cout << setw(15) << "Kiem Chung Vien" << setw(15) << Manhanvien << setw(20) << Hoten << setw(10) << tinhLuong() << '\n';
    }
};


NhanVien* nhapThongTinLapTrinhVien() {
    string Manhanvien, Hoten, Sodienthoai, Email;
    int Tuoi, Sogiolamthem;
    float Luongcoban;

    cout << "Nhap ma NV: "; cin >> Manhanvien;
    cout << "Nhap ho ten: "; cin.ignore(); getline(cin, Hoten);
    cout << "Nhap tuoi: "; cin >> Tuoi;
    cout << "Nhap so dien thoai: "; cin >> Sodienthoai;
    cout << "Nhap email: "; cin >> Email;
    cout << "Nhap luong co ban: "; cin >> Luongcoban;
    cout << "Nhap so gio lam them: "; cin >> Sogiolamthem;

    return new LapTrinhVien(Manhanvien, Hoten, Tuoi, Sodienthoai, Email, Luongcoban, Sogiolamthem);
}


NhanVien* nhapThongTinKiemChungVien() {
    string Manhanvien, Hoten, Sodienthoai, Email;
    int Tuoi, Soloiphathien;
    float Luongcoban;

    cout << "Nhap ma NV: "; cin >> Manhanvien;
    cout << "Nhap ho ten: "; cin.ignore(); getline(cin, Hoten);
    cout << "Nhap tuoi: "; cin >> Tuoi;
    cout << "Nhap so dien thoai: "; cin >> Sodienthoai;
    cout << "Nhap email: "; cin >> Email;
    cout << "Nhap luong co ban: "; cin >> Luongcoban;
    cout << "Nhap so loi phat hien: "; cin >> Soloiphathien;

    return new KiemChungVien(Manhanvien, Hoten, Tuoi, Sodienthoai, Email, Luongcoban, Soloiphathien);
}


int main() {
    vector<NhanVien*> ds;
    int luaChon;
    float tongLuong = 0;


    do {
        cout << "Nhap 1 de them Lap Trinh Vien, 2 de them Kiem Chung Vien, 0 de ket thuc: ";
        cin >> luaChon;

        if (luaChon == 1) {
            ds.push_back(nhapThongTinLapTrinhVien());
        } else if (luaChon == 2) {
            ds.push_back(nhapThongTinKiemChungVien());
        }
    } while (luaChon != 0);

\
    for (const auto& nv : ds) {
        tongLuong += nv->tinhLuong();
    }

    float luongTrungBinh = (ds.empty()) ? 0 : (tongLuong / ds.size());


    cout << "\nDanh sach nhan vien:\n";
    cout << setw(15) << "Loai" << setw(15) << "Ma NV" << setw(20) << "Ho Ten" << setw(10) << "Luong" << '\n';
    cout << string(60, '-') << '\n;

    for (const auto& nv : ds) {
        nv->xuatThongTin();
    }

    // Li?t kê nhân viên có luong th?p hon luong trung bình
    cout << "\nNhan vien co luong thap hon luong trung binh (" << luongTrungBinh << "):\n";
    cout << string(60, '-') << endl;

    for (const auto& nv : ds) {
        if (nv->tinhLuong() < luongTrungBinh) {
            nv->xuatThongTin();
        }
    }

    for (auto& nv : ds) {
        delete nv;
    }
    ds.clear();

    return 0;
}

