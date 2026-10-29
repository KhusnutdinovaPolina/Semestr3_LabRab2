#ifndef TASK4_HISTOGRAM_H
#define TASK4_HISTOGRAM_H
#include "../structs/array.h"
#include <string>

void runTask4();
// Считает частоты символов и возвращает максимальную высоту столбика
int countFrequencies(const std::string& text, Array& counts);
// Рисует саму гистограмму
void printHistogram(const Array& counts, int maxHeight);

#endif