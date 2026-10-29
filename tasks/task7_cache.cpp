#include "task7_cache.h"
#include "../structs/lfu_cache.h"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

void runTask7() {
    cout << "\n Задание 7: LFU Cache \n";

    int capacity, Q;
    cout << "Введите емкость кэша (cap): ";
    cin >> capacity;

    cout << "Введите количество запросов (Q): ";
    cin >> Q;
    cin.ignore(); // Очищаем буфер после ввода числа, съедает невидимый энтер

    LFUCache cache(capacity);
    string line;

    cout << "\nВведите " << Q << " запросов: \n";

    // Выполняем ровно Q запросов
    for (int i = 0; i < Q; i++) {
        cout << "> ";
        getline(cin, line);

        // Если пользователь случайно нажал Enter, не считаем это за запрос
        if (line.empty()) { i--; continue; }

        stringstream ss(line);//считаывание как из консоли
        string cmd;
        int key, value;
        ss >> cmd;

        if (cmd == "SET") {
            ss >> key >> value;
            cache.set(key, value);
        }
        else if (cmd == "GET") {
            ss >> key;
            int res = cache.get(key);
            cout << res << " \n";
        }
        else if (cmd == "PRINT") {
            cache.print();
        }
    }
    cout << "\n";
}