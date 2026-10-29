#include "hashtable_chaining.h"
#include <iostream>
using namespace std;

HashTableChaining::HashTableChaining() {
    for (int i = 0; i < CHAIN_SIZE; i++) table[i] = nullptr;
}

HashTableChaining::~HashTableChaining() {
    for (int i = 0; i < CHAIN_SIZE; i++) {
        Node* p = table[i];
        while (p) {
            Node* t = p;
            p = p->next;
            delete t;
        }
    }
}

int HashTableChaining::hash(const string& key) {
    int sum = 0;
    for (char c : key) sum += c;
    return sum % CHAIN_SIZE;
}

// Добавление только ключа (значение пустое)
void HashTableChaining::insert(const string& key) {
    insert(key, "");
}

// Добавление с ключом и значением
void HashTableChaining::insert(const string& key, const string& value) {
    int idx = hash(key);
    Node* p = table[idx];

    // Ищем, есть ли уже такой ключ
    while (p) {
        if (p->key == key) {
            p->value = value; // Обновляем значение
            return;
        }
        p = p->next;
    }
    // Если нет — создаем новый узел
    Node* n = new Node(key, value);
    n->next = table[idx];
    table[idx] = n;
}

bool HashTableChaining::search(const string& key) {
    int idx = hash(key);
    Node* p = table[idx];
    while (p) {
        if (p->key == key) return true;
        p = p->next;
    }
    return false;
}

string HashTableChaining::get(const string& key) {
    int idx = hash(key);
    Node* p = table[idx];
    while (p) {
        if (p->key == key) return p->value;
        p = p->next;
    }
    return "NOT_FOUND";
}

void HashTableChaining::remove(const string& key) {
    int idx = hash(key);
    Node* p = table[idx];
    Node* prev = nullptr;

    while (p) {
        if (p->key == key) {
            if (prev) prev->next = p->next;
            else table[idx] = p->next;
            delete p;
            return;
        }
        prev = p;
        p = p->next;
    }
}

void HashTableChaining::print() {
    cout << " Хеш-таблица (Метод цепочек) \n";
    for (int i = 0; i < CHAIN_SIZE; i++) {
        cout << "[" << i << "]: ";
        Node* p = table[i];
        while (p) {
            cout << p->key;
            if (!p->value.empty()) cout << "=" << p->value; // Печатаем значение, если оно есть
            cout << " -> ";
            p = p->next;
        }
        cout << "NULL\n";
    }
}