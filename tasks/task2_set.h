#ifndef TASK2_SET_H
#define TASK2_SET_H
#include "../structs/set.h"
void runTask2();
void loadSetFromFile(MySet& s, const string& filename);
void saveSetToFile(MySet& s, const string& filename);
void runTask2Console(const string& filename, const string& query);

#endif