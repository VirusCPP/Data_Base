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
        cout << "\nСоздание новой базы данных.\n" << endl;
        cout << "Введите новый логин: ";
        cin >> login;
        cout << "Введите новый пароль: ";
        cin >> password;
        saveData();
    }
    else {
        int errCount = 3;
        while (!status) {
            string enteredLogin;
            string enteredPassword;
            cout << "Введите логин: ";
            cin >> enteredLogin;
            cout << "Введите пароль: ";
            cin >> enteredPassword;
            decrypt(path, key);
            if (login == enteredLogin && password == enteredPassword) {
                status = true;
            }
            else if (errCount == 0) {
                std::cout << "\nПревышено количество попыток\n";
                exit(0);
            }
            else {
                errCount--;
                cout << "\nНеверный логин или пароль\n" << endl;
                cout << "Осталось " << errCount << (errCount == 1 ? " попытка\n" : " попытки\n") << endl;
            }
            encrypt(path, key);
        }
    }
}