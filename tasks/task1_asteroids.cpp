#include "task1_asteroids.h"
#include <iostream>
#include <sstream>
using namespace std;


void processAsteroid(Stack& st, const string& token) {
    char dir = token.back(); // Направление (право/лево)
    string sizeStr = token.substr(0, token.length() - 1); // Размер (число)
    int curSize = stoi(sizeStr);

    bool alive = true;

    while (alive && dir == 'L' && !st.isEmpty()) {
        string topToken = st.top();
        char topDir = topToken.back();

        if (topDir == 'R') { // Столкновение
            int topSize = stoi(topToken.substr(0, topToken.length() - 1));

            if (topSize < curSize) {
                curSize = curSize - topSize;
                st.pop();
            } else if (topSize == curSize) {
                st.pop();
                alive = false;
            } else {
                alive = false;
                int newTopSize = topSize - curSize;
                st.pop(); //достаем и кладём обратно сновым размером
                st.push(to_string(newTopSize) + "R");

            }
        } else {
            break; // Оба летят влево, столкновения нет
        }
    }

    // Если выжил после всего, кладем в стек
    if (alive) {
        st.push(to_string(curSize) + string(1, dir));
    }
}


void parseAndProcess(Stack& st, const string& inputLine) {
    stringstream ss(inputLine);
    string token;
    while (ss >> token) {
        processAsteroid(st, token);
    }
}

void runTask1() {
    cout << "\n Задание 1: Астероиды \n";
    cout << "Введите астероиды через пробел:\n";

    string inputLine;
    getline(cin, inputLine);

    Stack st;
    parseAndProcess(st, inputLine);

    cout << "Результат: ";
    st.print();
}


