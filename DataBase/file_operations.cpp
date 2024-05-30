#include "Header.h"


bool isEmpty(std::fstream& pFile) {
    return pFile.peek() == fstream::traits_type::eof();
}

void addWorkerFromFile() {
    decrypt(path, key);

    file.open(path);
    if (file.is_open()) {
        string name;
        int age;
        int salary;
        if (isEmpty(file)) {
            cout << "\nБаза пуста" << endl;
        }
        else {
            string line;
            int currentLine = 0;
            while (currentLine < 2 && std::getline(file, line)) {
                ++currentLine;
            }
            while (file >> name >> age >> salary) {
                Worker newWorker;
                newWorker.enterdata(name, age, salary);
                workers.push_back(newWorker);
            }
            cout << "\nБаза загружена" << endl;
        }
        file.close();
    }
    else {
        cout << "\nОшибка при открытии файла базы данных." << endl;
    }

    encrypt(path, key);

    sort(workers.begin(), workers.end(), [](const Worker& w1, const Worker& w2) {
        return w1.getName() < w2.getName();
        });
}

void saveData() {
    file.open(path, std::fstream::out);
    if (file.is_open()) {
        file << login << endl;
        file << password << endl;
        for (const auto& worker : workers) {
            file << worker.getName() << " " << worker.getAge() << " " << worker.getSalary() << endl;
        }
        file.close();
    }
    else {
        cout << "Ошибка при открытии файла для записи данных." << endl;
    }
    encrypt(path, key);
}