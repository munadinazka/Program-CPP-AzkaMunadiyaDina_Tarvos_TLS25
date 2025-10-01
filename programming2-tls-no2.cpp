#include <iostream>
using namespace std;

bool adalahVokal (char v) {
    if (v >= 'A' && v <= 'Z')
    v = v - 'A' + 'a';
    return v == 'a' || v == 'i' || v == 'u' || v == 'e' || v == 'o';
}

void fungsiReverse (string &s) {
    int i = 0, j = s.size () - 1;
    while (i < j) {
        char sementara = s[i];
        s[i] = s[j];
        s[j] = sementara;
        i++; j--;
    }
}

string integerToString (int x) {
    if (x == 0) return "0";
    if (x < 0) x = -x;
    string r = "";
    while (x > 0) {
        r.push_back (char ('0' + x % 10));
        x /= 10;
    }
    fungsiReverse (r);
    return r;
}

string SandiEnkripsi (const string &word) {
    if(word.empty()) return "";
    string cons = "";
    for(size_t i = 0; i < word.size(); ++i){
        if(!adalahVokal (word[i])) {
            char v = word[i];
            if (v >= 'a' && v <= 'z') v = v - 'a' + 'A';
            cons.push_back(v);
        }
    }
    fungsiReverse(cons);
    int asciiFirst = (int)word[0];
    string a = integerToString(asciiFirst);
    int mid = cons.size () / 2;
    return cons.substr (0, mid) + a + cons.substr(mid);
}

int ambilAngka (const string &s, int posisiAwal, int panjangDigit) {
    int value = 0;
    for (int i = 0; i < panjangDigit; ++i) {
        char v = s[posisiAwal + i];
        if (v < '0' || v > '9') {
            return -1;
        }
        value = value * 10 + (v - '0');
    }
    return value;
}

void menentukanKandidat (const string &password) {
    int n = password.size ();
    bool found = false;

    for (int i = 0; i < n; ++i) {
        for (int panjangDigit = 1; panjangDigit <= 3 && i + panjangDigit <= n; ++panjangDigit) {
            int kode = ambilAngka(password, i, panjangDigit);
            if (kode < 32 || kode > 122) continue;

            string sisa = password.substr(0, i) + password.substr(i + panjangDigit);
            fungsiReverse (sisa);
            
            // versi kapital
            string kapital = sisa;
            for (size_t k = 0; k < kapital.size (); ++k) {
                if (kapital[k] >= 'a' && kapital[k] <= 'z')
                    kapital[k] = kapital[k] - 'a' + 'A';
            }
            
            // versi nonkapital
            string kecil = sisa;
            for (size_t k = 0; k < kecil.size (); ++k) {
                if (kecil[k] >= 'A' && kecil[k] <= 'Z')
                    kecil[k] = kecil[k] - 'A' + 'a';
            }

            cout << "Huruf pertama: " << char(kode) << endl;
            cout << "Konsonan kapital: " << kapital << endl;
            cout << "Konsonan kecil  : " << kecil << endl;
            cout << "--------------------------\n";
            found = true;
        }
    }

    if (!found) {
        cout << "Tidak ditemukan kandidat" << endl;
    }
}

int main () {
    string kata;
    cout << "Masukkan kata untuk password: ";
    cin >> kata;

    string sandi = SandiEnkripsi(kata);
    cout << "\nSandi yang dihasilkan: " << sandi << endl << endl;
    cout << "Mencoba membongkar sandi..." << endl <<endl;
    menentukanKandidat(sandi);

    return 0;
}