#include "task4_histogram.h"
#include <iostream>
using namespace std;

// Принимаем текст и массив
int countFrequencies(const string& text, Array& counts) {
    int maxHeight = 0;

    // Идем по каждому символу текста
    for (char c : text) {

        if (c == ' ' || c == '\n' || c == '\r') continue; //пропуск пробелов и переводов
        int index = (int)c; //номер символов по таблице ascii

        // Достаем текущее значение из массива и увеличиваем счётчик
        int currentCount = stoi(counts.get(index));
        currentCount++;

        counts.set(index, to_string(currentCount));

        // Если текущий символ встречается чаще всех предыдущих — запоминаем его высоту
        if (currentCount > maxHeight) {
            maxHeight = currentCount;
        }
    }
    return maxHeight;
}

void printHistogram(const Array& counts, int maxHeight) {
    for (int level = maxHeight; level > 0; level--) { // Рисуем сверху вниз, от самой высокой строки до 1

        // Идем по всем 128 символам ASCII слева направо (сортировка автоматическая)
        for (int i = 0; i < 128; i++) {
            int cnt = stoi(counts.get(i)); // Сколько раз встречается символ с кодом i

            if (cnt >= level) {
                // Если этот символ встречается больше или столько же раз, сколько текущий уровень — рисуем решетку
                cout << "#";
            } else if (cnt > 0) {
                // Если символ в тексте есть, но его столбик ниже текущего уровня, рисуем пробел, чтобы столбики не "съезжали"
                cout << " ";
            }
        }
        cout << "\n";
    }

//основание гистограммы
    for (int i = 0; i < 128; i++) {
        if (stoi(counts.get(i)) > 0) { // Печатаем только те, что есть в тексте
            cout << (char)i; // Превращаем число (индекс) обратно в символ
        }
    }
    cout << "\n";
}

void runTask4() {
    cout << "\n Задание 4: Гистограмма \n";
    cout << "Введите текст: \n";

    string text;
    getline(cin, text);

    // создаём массив, хранит строки, заполняем его 128 нулями (по количеству ASCII-символов)
    Array counts;
    for (int i = 0; i < 128; i++) {
        counts.pushBack("0");
    }

    // Считаем частоты (и получаем максимальную высоту)
    int maxHeight = countFrequencies(text, counts);

    // Рисуем гистограмму
    printHistogram(counts, maxHeight);
}