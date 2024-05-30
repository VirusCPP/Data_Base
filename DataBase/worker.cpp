#include "Header.h"


void Worker::enterdata(const string& name, int age, int salary) {
    this->name = name;
    this->age = age;
    this->salary = salary;
}

void Worker::printdata() const {
    cout << "Имя \t\t" << this->name << endl;
    cout << "Возраст \t" << this->age << endl;
    cout << "Зарплата \t" << this->salary << endl;
}

string Worker::getName() const {
    return this->name;
}

int Worker::getAge() const {
    return this->age;
}

int Worker::getSalary() const {
    return this->salary;
}

bool checkWorkersList() {
    if (workers.empty()) {
        cout << "\n\nВ настоящий момент нет сотрудников." << endl;
        return false;
    }
    return true;
}

void addWorker() {
    std::string name;
    int age;
    int salary;
    Worker newWorker;

    cout << "\n\nДобавьте сотрудника № " << workers.size() + 1 << endl;
    cout << "Введите имя: ";
    cin >> name;

    do {
        cout << "Введите возраст: ";
        cin >> age;
        if (cin.fail() || age < 18) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Некорректный ввод данных. Возраст не может быть меньше 18. Попробуйте снова." << endl;
        }
    } while (age < 18);

    do {
        cout << "Введите зарплату: ";
        cin >> salary;
        if (cin.fail() || salary < 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Некорректный ввод данных. Зарплата не может быть отрицательной. Попробуйте снова." << endl;
        }
    } while (salary < 0);
    if (cin.fail()) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Некорректный ввод данных. Попробуйте снова." << endl;
        return;
    }

    newWorker.enterdata(name, age, salary);
    workers.push_back(newWorker);
    sort(workers.begin(), workers.end(), [](const Worker& w1, const Worker& w2) {
        return w1.getName() < w2.getName();
        });
}


void getInfo() {
    if (checkWorkersList()) {
        getWorkerList();
        cout << "\nИнформацию о каком сотруднике вывести? ";
        int i;
        cin >> i;
        if (cin.fail() || i <= 0 || i > workers.size()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nНеправильный номер сотрудника" << endl;
        }
        else {
            cout << "\nСотрудник номер: " << i << endl;
            workers[i - 1].printdata();
        }
    }
}

void deleteWorker() {
    if (checkWorkersList()) {
        getWorkerList();
        cout << "Введите номер сотрудника, которого нужно удалить: ";
        int i;
        std::cin >> i;
        if (cin.fail() || i <= 0 || i > workers.size()) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "\n\nНеправильный номер сотрудника" << endl;
        }
        else {
            workers.erase(workers.begin() + (i - 1));
        }
    }
}

void getWorkerList() {
    if (checkWorkersList()) {
        cout << "\n\nВсего сотрудников: " << workers.size() << endl;
        for (size_t i = 0; i < workers.size(); i++) {
            cout << "Сотрудник номер: " << i + 1 << "\t" << workers[i].getName() << endl;
        }
    }
}

void workerSearch() {
    if (checkWorkersList()) {
        vector<int> index;
        string search;
        cout << "\nВведите имя сотрудника: ";
        cin >> search;
        cout << endl;
        for (size_t j = 0; j < workers.size(); j++) {
            if (workers[j].getName() == search) {
                index.push_back(j);
            }
        }
        if (index.empty()) {
            cout << "\nСотрудник не найден" << endl;
        }
        else {
            cout << "\nНайдено сотрудников: " << index.size() << endl;
            for (size_t i = 0; i < index.size(); i++) {
                workers[index[i]].printdata();
                cout << endl;
            }
        }
    }
}