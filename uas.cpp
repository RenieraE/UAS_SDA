// Mata Kuliah	: Struktur Data dan Algoritma
// Kelas	: IT201
// Prodi	: PJJ Informatika
// Nama Mahasiswa	: Muhammad Irsyad Izzatulhaq
// NIM	: 230401010207
// Dosen	: Alun Sujjada, S.Kom., M.T

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Data {
    string nama;
    string alamat;
};

void printData(const vector<Data>& data) {
    for (const auto& d : data) {
        cout << d.nama << " " << d.alamat << endl;
    }
    cout << endl;
}

void bubbleSort(vector<Data>& data) {
    int n = data.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (data[j].nama > data[j + 1].nama) {
                swap(data[j], data[j + 1]);
            }
        }
    }
}

void selectionSort(vector<Data>& data) {
    int n = data.size();
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (data[j].nama < data[min_idx].nama) {
                min_idx = j;
            }
        }
        swap(data[min_idx], data[i]);
    }
}

int main() {
    vector<Data> data1 = {
        {"Fahmi", "Jakarta"},
        {"Romi", "Solo"},
        {"Andri", "Jakarta"},
        {"Fadillah", "Banyuwangi"},
        {"Ruli", "Bandung"},
        {"Rudi", "Bali"},
        {"Dendi", "Purwokerto"},
        {"Zaki", "Madiun"}
    };

    vector<Data> data2 = data1; 

    cout << "Data sebelum diurutkan:" << endl;
    printData(data1);

    // Bubble Sort
    bubbleSort(data1);
    cout << "Diurutkan dengan Bubble Sort:" << endl;
    printData(data1);

    // Selection Sort
    selectionSort(data2);
    cout << "Diurutkan dengan Selection Sort:" << endl;
    printData(data2);

    return 0;
}
