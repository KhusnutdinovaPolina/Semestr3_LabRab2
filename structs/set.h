#ifndef SET_H
#define SET_H

#include <string>
#include "hashtable_chaining.h"

struct MySet {
    HashTableChaining table; // Внутри используем нашу хеш-таблицу

    void add(const std::string& key);
    void remove(const std::string& key);
    bool contains(const std::string& key); // SET_AT
    void print();
};

#endif