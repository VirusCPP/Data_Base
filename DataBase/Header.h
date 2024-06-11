#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <conio.h>
#include <algorithm>

using namespace std;

class Worker {
public:
    Worker() = default;
    Worker(const Worker& other) = default;
    void enterdata(const string& name, int age, int salary);
    void printdata() const;
    string getName() const;
    int getAge() const;
    int getSalary() const;
    ~Worker() = default;

private:
    string name;
    int age;
    int salary;
};

void logIn();
void getInfo();
void MainMenu();
void getLogIn();
void saveData();
void addWorker();
void workerSearch();
void deleteWorker();
void getWorkerList();
bool checkWorkersList();
void addWorkerFromFile();
void encrypt(string& path, int key);
void decrypt(string& path, int key);
int BinarySearch(int arr[], int left, int right, int key);

extern string password;
extern string login;
extern vector<Worker> workers;
extern string path;
extern fstream file;
extern const int key;

#endif