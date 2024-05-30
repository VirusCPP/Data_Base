#include "Header.h"

void MainMenu() {
    addWorkerFromFile();

    while (true) {
        cout <<
            "===================================================\n" <<
            "|                Главное меню:                    |\n" <<
            "|       1.Добавить сотрудника                     |\n" <<
            "|       2.Показать информацию о сотруднике        |\n" <<
            "|       3.Показать список сотрудников             |\n" <<
            "|       4.Поиск сотрудника по имени               |\n" <<
            "|       5.Удалить сотрудника                      |\n" <<
            "|       6.Выход из программы                      |\n" <<
            "===================================================\n";
        cout << "Выберите пункт меню: ";
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
            cout << "Введено некорректное значение" << endl;
            break;
        }
        cout << endl;
    }
}