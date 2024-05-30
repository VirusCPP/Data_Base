#include "Header.h"

void MainMenu() {
    addWorkerFromFile();

    while (true) {
        cout <<
            "===================================================\n" <<
            "|                ������� ����:                    |\n" <<
            "|       1.�������� ����������                     |\n" <<
            "|       2.�������� ���������� � ����������        |\n" <<
            "|       3.�������� ������ �����������             |\n" <<
            "|       4.����� ���������� �� �����               |\n" <<
            "|       5.������� ����������                      |\n" <<
            "|       6.����� �� ���������                      |\n" <<
            "===================================================\n";
        cout << "�������� ����� ����: ";
        char answer = _getch();
        switch (answer) {
        case '1':
            addWorker();
            break;
        case '2':
            getInfo();
            break;
        case '3':
            getWorkerList();
            break;
        case '4':
            workerSearch();
            break;
        case '5':
            deleteWorker();
            break;
        case '6':
            saveData();
            exit(0);
        default:
            cout << "������� ������������ ��������" << endl;
            break;
        }
        cout << endl;
    }
}