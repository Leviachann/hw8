#include <iostream>
#include <vector>
#include <windows.h>
using namespace std;

class Worker {
public:
  static int idCounter;
  int id;
  int age;
  int pageCount;
  string name;
  string surname;

  Worker() {
    id = idCounter++;
    age = 34;
    name = "Azer";
    surname = "Atamoglanov";
    pageCount = 12;
  }
  Worker(int a, int pC, string nm, string snm, ) {
    id = idCounter++;
    this->age = a;
    this->pageCount = pC;
    this->name = nm;
    this->surname = snm;
  }
  void Print() {
    cout << "ID: " << id << endl
         << "Name: " << name << endl
         << "Surname: " << surname << endl
         << "Age" << age << endl
         << "Page count: " << pageCount << endl;
  }
};

int Worker::idCounter = 100;

class WorkerQuene {
public:
  vector<Worker> workers;
  bool IsEmpty() const { return workers.empty(); }
  void EnQuene(const Worker &worker) { workers.push_back(worker); }
  void DeQuene() {
    if (!workers.empty())
      workers.erase(workers.begin());
  }
  Worker &Front() { return workers.front(); }
};

class Printer {
public:
  WorkerQuene quene;

  void AddWorker(const Worker &worker) { quene.EnQuene(worker); }

  void Start() {
    while (!quene.IsEmpty()) {
      Worker worker = quene.Front();
      while (0 < worker.pageCount) {
        system("cls");
        worker.Print();
        Sleep(1000);
        worker.pageCount--;
      }
      quene.DeQuene();
    }
  }
}