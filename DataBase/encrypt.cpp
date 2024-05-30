#include "Header.h"


void encrypt(string& path, int key) {
    ifstream fin(path, ios::in | ios::binary);
    ofstream fout("temp.txt", ios::out | ios::binary);
    if (!fin.is_open() || !fout.is_open()) {
        return;
    }
    char c;
    while (fin.get(c)) {
        fout.put(c ^ key);
    }
    fin.close();
    fout.close();

    remove(path.c_str());
    rename("temp.txt", path.c_str());
}

void decrypt(string& path, int key) {
    encrypt(path, key);
}