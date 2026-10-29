#ifndef HASHTABLE_CHAINING_H
#define HASHTABLE_CHAINING_H

#include <string>
using namespace std;

const int CHAIN_SIZE = 10;

struct HashTableChaining {
    struct Node {
        string key;
        string value;
        Node* next;
        Node(string k, string v) : key(k), value(v), next(nullptr) {}
    };

    Node* table[CHAIN_SIZE];

    HashTableChaining();
    ~HashTableChaining();

    int hash(const string& key);

    // Перегрузка: только ключ (для Множества)
    void insert(const string& key);
    // Перегрузка: ключ + значение (для полноценной таблицы)
    void insert(const string& key, const string& value);

    // Поиск (true/false)
    bool search(const string& key);
    // Получение значения по ключу
    string get(const string& key);

    void remove(const string& key);
    void print();
};

#endif