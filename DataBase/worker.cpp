#include "Header.h"


void Worker::enterdata(const string& name, int age, int salary) {
    this->name = name;
    this->age = age;
    this->salary = salary;
}

void Worker::printdata() const {
    cout << "��� \t\t" << this->name << endl;
    cout << "������� \t" << this->age << endl;
    cout << "�������� \t" << this->salary << endl;
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
        cout << "\n\n� ��������� ������ ��� �����������." << endl;
        return false;
    }
    return true;
}

void addWorker() {
    std::string name;
    int age;
    int salary;
    Worker newWorker;

    cout << "\n\n�������� ���������� � " << workers.size() + 1 << endl;
    cout << "������� ���: ";
    cin >> name;

    do {
        cout << "������� �������: ";
        cin >> age;
        if (cin.fail() || age < 18) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "������������ ���� ������. ������� �� ����� ���� ������ 18. ���������� �����." << endl;
        }
    } while (age < 18);

    do {
        cout << "������� ��������: ";
        cin >> salary;
        if (cin.fail() || salary < 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "������������ ���� ������. �������� �� ����� ���� �������������. ���������� �����." << endl;
        }
    } while (salary < 0);
    if (cin.fail()) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "������������ ���� ������. ���������� �����." << endl;
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
        cout << "\n���������� � ����� ���������� �������? ";
        int i;
        cin >> i;
        if (cin.fail() || i <= 0 || i > workers.size()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\n������������ ����� ����������" << endl;
        }
        else {
            cout << "\n��������� �����: " << i << endl;
            workers[i - 1].printdata();
        }
    }
}

void deleteWorker() {
    if (checkWorkersList()) {
        getWorkerList();
        cout << "������� ����� ����������, �������� ����� �������: ";
        int i;
        std::cin >> i;
        if (cin.fail() || i <= 0 || i > workers.size()) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "\n\n������������ ����� ����������" << endl;
        }
        else {
            workers.erase(workers.begin() + (i - 1));
        }
    }
}

void getWorkerList() {
    if (checkWorkersList()) {
        cout << "\n\n����� �����������: " << workers.size() << endl;
        for (size_t i = 0; i < workers.size(); i++) {
            cout << "��������� �����: " << i + 1 << "\t" << workers[i].getName() << endl;
        }
    }
}

void workerSearch() {
    if (checkWorkersList()) {
        vector<int> index;
        string search;
        cout << "\n������� ��� ����������: ";
        cin >> search;
        cout << endl;
        for (size_t j = 0; j < workers.size(); j++) {
            if (workers[j].getName() == search) {
                index.push_back(j);
            }
        }
        if (index.empty()) {
            cout << "\n��������� �� ������" << endl;
        }
        else {
            cout << "\n������� �����������: " << index.size() << endl;
            for (size_t i = 0; i < index.size(); i++) {
                workers[index[i]].printdata();
                cout << endl;
            }
        }
    }
}