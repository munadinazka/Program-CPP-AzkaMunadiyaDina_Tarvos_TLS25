#include <iostream>
using namespace std;

int revNumber (int x) {
    int result = 0;
    while (x > 0) {
        int revDigit = x % 10; // Untuk mendapatkan digit terakhir yang bisa disimpan
        result = result * 10 + revDigit; // Untuk mendapatkan result=digit terakhir tadi dan ketika diulang terus maka hasil yang didapatkan adalah reverse dari angka awal
        x = x / 10; // Untuk mengulang sisanya 
    }

    return result;
}

int main () {
    int n;
    cout << "Masukkan jumlah elemen array: ";
    cin >> n;

    int arr[n];
    cout << "Masukkan elemen array: " << endl;
    for (int i = 0; i < n; i++) {
        cout << "Index " << i << ": ";
        cin >> arr[i];
    }
    cout << endl;

    cout << "Balikkan angka jika angka itu merupakan indeks genap dan biarkan saja jika indeksnya ganjil: " << endl;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) { 
            cout << revNumber(arr[i]) << " "; // Ini ngga perlu di ketik arr lagi karena fungsi if tidak bisa menghandle array
        } else {
            cout << arr[i] << " ";
        }
    }
    cout << endl;

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum = sum + arr[i];
    }
    cout << " \n Jumlahkan seluruh elemen array: " << sum << endl;

    return 0; 
}