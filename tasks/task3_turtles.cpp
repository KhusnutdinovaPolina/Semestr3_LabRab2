#include "task3_turtles.h"
#include "../structs/set.h"
#include <iostream>
#include <string>
#include <sstream> // для stringstream
using namespace std;

// функция перевода числа в строку
string intToString(int num) {
    stringstream ss;
    ss << num;
    return ss.str();
}

void runTask3() {
    cout << "\n Задание 3: Черепахи \n";

    int N;
    cout << "Введите количество черепах: ";
    cin >> N;

    MySet occupiedPositions;
    int trueCount = 0;

    cout << "Введите пары (впереди позади) для каждой черепахи:\n";
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;

        if (a + b + 1 == N) {
            int pos = a + 1;
            string posStr = intToString(pos);

            if (!occupiedPositions.contains(posStr)) {
                occupiedPositions.add(posStr);
                trueCount++;
            }
        }
    }

    cout << "Максимальное количество правдивых черепах: " << trueCount << "\n";
}