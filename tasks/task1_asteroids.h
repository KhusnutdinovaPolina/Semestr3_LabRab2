#ifndef TASK1_ASTEROIDS_H
#define TASK1_ASTEROIDS_H
#include "../structs/stack.h"
#include <string>

// Главная функция
void runTask1();
// Обрабатывает столкновения одного астероида
void processAsteroid(Stack& st, const std::string& token);
// Разбирает строку ввода
void parseAndProcess(Stack& st, const std::string& inputLine);

#endif