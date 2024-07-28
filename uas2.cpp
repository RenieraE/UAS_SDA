// Mata Kuliah	: Struktur Data dan Algoritma
// Kelas	: IT201
// Prodi	: PJJ Informatika
// Nama Mahasiswa	: Muhammad Irsyad Izzatulhaq
// NIM	: 230401010207
// Dosen	: Alun Sujjada, S.Kom., M.T

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Data {
    int value;
    int originalIndex;
};

bool compareByValue(const Data& a, const Data& b) {
    return a.value < b.value;
}

vector<int> binarySearchAllIndices(const vector<Data>& arr, int x) {
    vector<int> indices;
    auto lower = lower_bound(arr.begin(), arr.end(), x, [](const Data& a, int b) { return a.value < b; });
    auto upper = upper_bound(arr.begin(), arr.end(), x, [](int a, const Data& b) { return a < b.value; });

    if (lower != arr.end() && lower->value == x) {
        for (auto it = lower; it != upper; ++it) {
            indices.push_back(it->originalIndex);
        }
    }
    return indices;
}

int main() {
    vector<int> arr = {19, 40, 10, 90, 2, 50, 60, 50, 1};
    vector<Data> data;

    for (int i = 0; i < arr.size(); ++i) {
        data.push_back({arr[i], i});
    }

    sort(data.begin(), data.end(), compareByValue);

    int x;
    cout << "Masukkan angka yang ingin dicari: ";
    cin >> x;

    vector<int> result = binarySearchAllIndices(data, x);

    if (result.empty()) {
        cout << "Angka " << x << " tidak ada dalam array" << endl;
    } else {
        cout << "Angka " << x << " ada di indeks ke ";
        for (size_t i = 0; i < result.size(); ++i) {
            if (i > 0) cout << " dan ";
            cout << result[i] + 1;
        }
        cout << endl;
    }

    return 0;
}
