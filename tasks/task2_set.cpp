#include "task2_set.h"
#include "../structs/set.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

void loadSetFromFile(MySet& s, const string& filename) {
    ifstream file(filename);
    if (file.is_open()) {
        string word;
        while (file >> word) {
            s.add(word);
        }
        file.close();
    }
}

void saveSetToFile(MySet& s, const string& filename) {
    ofstream file(filename);
    if (file.is_open()) {
        // Так как внутри хеш-таблицы теперь узлы с ключами,
        // мы проходим по всем корзинам и выписываем ключи
        for (int i = 0; i < CHAIN_SIZE; i++) {
            HashTableChaining::Node* p = s.table.table[i];
            while (p) {
                file << p->key << "\n"; // Пишем только ключ, так как в множестве нет значений
                p = p->next;
            }
        }
        file.close();
    }
}

// Запуск в режиме консоли (--file и --query)
void runTask2Console(const string& filename, const string& query) {
    MySet mySet;
    loadSetFromFile(mySet, filename);

    stringstream ss(query);
    string cmd, val;
    ss >> cmd >> val;

    if (cmd == "SETADD") {
        mySet.add(val);
        cout << "Добавлено: " << val << "\n";
        saveSetToFile(mySet, filename);
    }
    else if (cmd == "SETDEL") {
        mySet.remove(val);
        cout << "Удалено: " << val << "\n";
        saveSetToFile(mySet, filename);
    }
    else if (cmd == "SET_AT") {
        if (mySet.contains(val)) cout << "TRUE\n";
        else cout << "FALSE\n";
    }
    else if (cmd == "PRINT") {
        mySet.print();
    }
    else {
        cout << "Неизвестная команда\n";
    }
}

void runTask2() {
    cout << "\n Задание 2: АТД Множество \n";
    cout << "Введите команды (SETADD val, SETDEL val, SET_AT val, PRINT, EXIT):\n";

    MySet mySet;
    string line;

    while (true) {
        cout << "> ";
        getline(cin, line);
        if (line == "EXIT") break;
        if (line.empty()) continue;

        // Ручной разбор строки
        size_t spacePos = line.find(' ');
        string cmd = line;
        string val = "";

        if (spacePos != string::npos) {
            cmd = line.substr(0, spacePos);
            val = line.substr(spacePos + 1);
        }

        if (cmd == "PRINT") {
            mySet.print();
        }
        else if (cmd == "SETADD") {
            mySet.add(val);
            cout << "OK\n";
        }
        else if (cmd == "SETDEL") {
            mySet.remove(val);
            cout << "OK\n";
        }
        else if (cmd == "SET_AT") {
            cout << (mySet.contains(val) ? "TRUE" : "FALSE") << "\n";
        }
        else {
            cout << "Неизвестная команда\n";
        }
    }
}