#include <Windows.h>
#include "Header.h"

string password;
string login;
vector<Worker> workers;
string path = "DataBase.bin";
fstream file;
const int key = 121524;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    getLogIn();
    logIn();
    MainMenu();

    return 0;
}