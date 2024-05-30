#include "Header.h"

void getLogIn() {
    decrypt(path, key);
    file.open(path);
    if (file.is_open()) {
        std::getline(file, login);
        std::getline(file, password);
        file.close();
    }
    encrypt(path, key);
}

void logIn() {
    getLogIn();
    bool status = false;
    if (login.empty() && password.empty()) {
        cout << "\n�������� ����� ���� ������.\n" << endl;
        cout << "������� ����� �����: ";
        cin >> login;
        cout << "������� ����� ������: ";
        cin >> password;
        saveData();
    }
    else {
        int errCount = 3;
        while (!status) {
            string enteredLogin;
            string enteredPassword;
            cout << "������� �����: ";
            cin >> enteredLogin;
            cout << "������� ������: ";
            cin >> enteredPassword;
            decrypt(path, key);
            if (login == enteredLogin && password == enteredPassword) {
                status = true;
            }
            else if (errCount == 0) {
                std::cout << "\n��������� ���������� �������\n";
                exit(0);
            }
            else {
                errCount--;
                cout << "\n�������� ����� ��� ������\n" << endl;
                cout << "�������� " << errCount << (errCount == 1 ? " �������\n" : " �������\n") << endl;
            }
            encrypt(path, key);
        }
    }
}