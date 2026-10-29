#include <iostream>
#include <string>
#include <cstring>
#include "tasks/tasks.h"
#include "tasks/task2_set.h"
using namespace std;

void runTask2Console(const string& filename, const string& query);

int main(int argc, char* argv[]) {
    setlocale(LC_ALL, "Russian");

    string filename = "";
    string query = "";

    // Ищем аргументы --file и --query
    for (int i = 1; i < argc; i++) {
        if (string(argv[i]) == "--file" && i + 1 < argc) {
            filename = argv[i + 1];
        }
        if (string(argv[i]) == "--query" && i + 1 < argc) {
            query = argv[i + 1];
        }
    }

    if (!filename.empty() && !query.empty()) {
        runTask2Console(filename, query);
        return 0;
    }

    int choice;
    while (true) {
        cout << "\n Лабораторная работа №2 \n";
        cout << "1. Астероиды (Стек)\n";
        cout << "2. АТД Множество \n";
        cout << "3. Черепахи (Множество)\n";
        cout << "4. Гистограмма (Массив)\n";
        cout << "5. Глубина элементов (Дерево)\n";
        cout << "6. Хеш-таблица\n";
        cout << "7. LFU Cache\n";
        cout << "0. Выход\n";
        cout << "Выберите задание: ";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }
        cin.ignore();

        switch (choice) {
            case 1: runTask1(); break;
            case 2: runTask2(); break;
            case 3: runTask3(); break;
            case 4: runTask4(); break;
            case 5: runTask5(); break;
            case 6: runTask6(); break;
            case 7: runTask7(); break;
            case 0: return 0;
            default: cout << "Неверный выбор.\n";
        }
    }
    return 0;
}
