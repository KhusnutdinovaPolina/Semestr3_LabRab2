#ifndef TASK6_HASH_H
#define TASK6_HASH_H

#include <string>
#include "../structs/array.h"


void runTask6();
int findIndex(Array& arr, const std::string& val);
int countDesc(const string& name, string children[100][10], int childCounts[], Array& names, int memo[]);
void printPrettyTree(const string& name, string children[100][10], int childCounts[], Array& names, string prefix, bool isLast);
#endif