#include <iostream>
#include <vector>
using namespace std;

#include <iostream>
#include <vector>
using namespace std;

class dokter;
class pasien { // asosiasi
public:
    string nama;
    vector<dokter*> daftar_dokter;
    pasien(string pNama) : nama(pNama) {
        cout << "Pasien \"" << nama << "\" ada\n";
    }
    ~pasien() {
        cout << "Pasien \"" << nama << "\" tidak ada\n";
    }
    void tambahDokter(dokter* pDokter);
    void cetakDokter();
};

class dokter {
public:
    string nama;
    vector<pasien*> daftar_pasien;
    dokter(string pNama) : nama(pNama) {
        cout << "Dokter \"" << nama << "\" ada\n";
    }
    ~dokter() {
        cout << "Dokter \"" << nama << "\" tidak ada\n";
    }
    void tambahPasien(pasien* pPasien);
    void cetakPasien();
};

void pasien::tambahDokter(dokter* pDokter) {
    daftar_dokter.push_back(pDokter);
    pDokter->tambahPasien(this);
}

void pasien::cetakDokter() {
    cout << "Daftar Dokter yang menangani pasien \"" << this->nama << "\":\n";
    for (auto& a : daftar_dokter) { // auto digunakan dalam perulangan for untuk secara otomatis menentukan tipe data dari elemen yang ditera
        cout << a->nama << "\n";
    }
    cout << endl;
}

void dokter::tambahPasien(pasien* pPasien) {
    daftar_pasien.push_back(pPasien);
    pPasien->tambahDokter(this);
}

void dokter::cetakPasien() {
    cout << "Daftar Pasien dari dokter \"" << this->nama << "\":\n";
    for (auto& a : daftar_pasien) {
        cout << a->nama << "\n";
    }
    cout << endl;
}

