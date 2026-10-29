#include "task6_hash.h"
#include "../structs/hashtable_chaining.h"
#include "../structs/hashtable_cuckoo.h"
#include "../structs/array.h"
#include <iostream>
#include <string>
using namespace std;

// Ищем индекс строки в нашем Array, для проверки на повтор добавления имени
int findIndex(Array& arr, const string& val) {
    for (int i = 0; i < arr.length(); i++) {
        if (arr.get(i) == val) return i;
    }
    return -1;
}

// Рекурсивный подсчет потомков
int countDesc(const string& name, string children[100][10], int childCounts[], Array& names, int memo[]) {
    int idx = findIndex(names, name);
    if (idx == -1) return 0;
    if (memo[idx] != -1) return memo[idx];

    int total = 0;
    for (int i = 0; i < childCounts[idx]; i++) {
        total += 1 + countDesc(children[idx][i], children, childCounts, names, memo);
    }
    memo[idx] = total;
    return total;
}

void printPrettyTree(const string& name, string children[100][10], int childCounts[], Array& names, string prefix, bool isLast) {
    cout << prefix;
    cout << (isLast ? "+-- " : "|-- ") << name << "\n";

    int idx = findIndex(names, name);
    if (idx == -1) return;

    string newPrefix = prefix + (isLast ? "    " : "|   ");

    for (int i = 0; i < childCounts[idx]; i++) {
        printPrettyTree(children[idx][i], children, childCounts, names, newPrefix, i == childCounts[idx] - 1);
    }
}

void runTask6() {
    while (true) {
        cout << "\n Задание 6 " << endl;
        cout << "1. Метод цепочек" << endl;
        cout << "2. Кукушка" << endl;
        cout << "3. Родословная (6.2)" << endl;
        cout << "0. Назад" << endl;
        cout << "Выбор: ";

        int choice;
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }
        if (choice == 0) break;
        cin.ignore();

        if (choice == 1) {
            HashTableChaining ht;
            cout << "Слова (exit - выход): ";
            string word;
            while (cin >> word && word != "exit") ht.insert(word);
            ht.print();
        }
        else if (choice == 2) {
            HashTableCuckoo ht;
            cout << "Слова (exit - выход): ";
            string word;
            while (cin >> word && word != "exit") {
                if (!ht.insert(word)) cout << "Переполнение!" << endl;
            }
            ht.print();
        }
        else if (choice == 3) {
            cout << "\n 6.2: Родословная " << endl;
            int N;
            cout << "Количество людей: ";
            cin >> N;
            cin.ignore();

            HashTableChaining parentTable;
            Array names;

            // Массивы для связей (100 людей, у каждого максимум 10 детей)
            string children[100][10];
            int childCounts[100] = {0};
            int memo[100];

            cout << "Введите N-1 строк (Потомок Родитель):" << endl;
            for (int i = 0; i < N - 1; i++) {
                string child, parent;
                cin >> child >> parent;

                parentTable.insert(child);

                if (findIndex(names, child) == -1) names.pushBack(child);
                if (findIndex(names, parent) == -1) names.pushBack(parent);

                int pIdx = findIndex(names, parent);
                children[pIdx][childCounts[pIdx]++] = child;// записываем ребёнка к родителю
            }

            // Сортировка имен и связей
            for (int i = 0; i < names.length() - 1; i++) {
                for (int j = 0; j < names.length() - i - 1; j++) {
                    if (names.get(j) > names.get(j+1)) {
                        string tempName = names.get(j);
                        names.set(j, names.get(j+1));
                        names.set(j+1, tempName);
                        //синхронно меняем их детей
                        for (int k = 0; k < 10; k++) swap(children[j][k], children[j+1][k]);
                        swap(childCounts[j], childCounts[j+1]);
                    }
                }
            }

            for (int i = 0; i < 100; i++) memo[i] = -1;

            cout << "\nРезультат:" << endl;
            for (int i = 0; i < names.length(); i++) {
                string name = names.get(i);
                int desc = countDesc(name, children, childCounts, names, memo);
                cout << name << " " << desc << endl;
            }

            // Поиск корня (прародитель, ничей ребёнок)
            string root = "";
            for (int i = 0; i < names.length(); i++) {
                string name = names.get(i);
                bool isChild = false;
                for (int r = 0; r < names.length(); r++) {
                    for (int c = 0; c < childCounts[r]; c++) {
                        if (children[r][c] == name) isChild = true;
                    }
                }
                if (!isChild) { root = name; break; }
            }

            if (root != "") {
                cout << "\nСамо древо:\n";
                printPrettyTree(root, children, childCounts, names, "", true);
            }
            cout << "\n";
        }
    }
}