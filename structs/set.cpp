#include "set.h"
#include <iostream>
using namespace std;

void MySet::add(const string& key) {
    table.insert(key);
}

void MySet::remove(const string& key) {
    table.remove(key);
}

bool MySet::contains(const string& key) {
    return table.search(key);
}

void MySet::print() {
    table.print();
}