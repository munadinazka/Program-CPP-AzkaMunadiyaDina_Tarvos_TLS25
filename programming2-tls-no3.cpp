#include <iostream>
using namespace std;

string warnaYangTampil(int durasiHijau, int durasiKuning, int durasiMerah, int detikMulaiHijau, int detikYangDitanya) {
    int siklus = durasiHijau + durasiKuning + durasiMerah;
    int selisih = detikYangDitanya - detikMulaiHijau;
    int t = ((selisih % siklus) + siklus) % siklus;

    if (t < durasiHijau) return "Hijau";
    else if (t < durasiHijau + durasiKuning) return "Kuning";
    else return "Merah";
}

int main() {
    int durasiHijau, durasiKuning, durasiMerah, detikMulaiHijau, detikYangDitanya;

    cout << "Masukkan durasi hijau: ";
    cin >> durasiHijau; // durasiHijau = 20

    cout << "Masukkan durasi kuning: ";
    cin >> durasiKuning; // durasiKuning = 3

    cout << "Masukkan durasi merah: ";
    cin >> durasiMerah; // durasiMerah = 80

    cout << "Masukkan detik mulai hijau: ";
    cin >> detikMulaiHijau; // menurut soal, detikMulaiHijau = 25

    cout << "Masukkan detik yang ingin ditanya: ";
    cin >> detikYangDitanya;

    cout << "Warna saat detik ke-" << detikYangDitanya << ": "
         << warnaYangTampil(durasiHijau, durasiKuning, durasiMerah, detikMulaiHijau, detikYangDitanya) << '\n';

    return 0;
}