#include "hashtable_cuckoo.h"
#include <iostream>
using namespace std;

HashTableCuckoo::HashTableCuckoo() {
    for(int i=0; i<CUCKOO_SIZE; i++) {
        keys1[i] = ""; vals1[i] = "";
        keys2[i] = ""; vals2[i] = "";
    }
}

int HashTableCuckoo::hash1(const string& key) {
    int sum = 0;
    for (char c : key) sum += c;
    return sum % CUCKOO_SIZE;
}

int HashTableCuckoo::hash2(const string& key) {
    int sum = 0;
    for (char c : key) sum += (c * 7);
    return sum % CUCKOO_SIZE;
}

bool HashTableCuckoo::insert(const string& key) {
    return insert(key, "");
}

bool HashTableCuckoo::insert(const string& key, const string& value) {
    if (search(key)) return true;

    string curKey = key;
    string curVal = value;

    for (int i = 0; i < MAX_KICKS; i++) {
        int pos1 = hash1(curKey);
        if (keys1[pos1] == "") {
            keys1[pos1] = curKey; vals1[pos1] = curVal;
            return true;
        }
        // Выбиваем элемент
        string tempKey = keys1[pos1];
        string tempVal = vals1[pos1];
        keys1[pos1] = curKey; vals1[pos1] = curVal;
        curKey = tempKey; curVal = tempVal;

        int pos2 = hash2(curKey);
        if (keys2[pos2] == "") {
            keys2[pos2] = curKey; vals2[pos2] = curVal;
            return true;
        }
        // Выбиваем элемент
        tempKey = keys2[pos2];
        tempVal = vals2[pos2];
        keys2[pos2] = curKey; vals2[pos2] = curVal;
        curKey = tempKey; curVal = tempVal;
    }
    return false;
}

bool HashTableCuckoo::search(const string& key) {
    return keys1[hash1(key)] == key || keys2[hash2(key)] == key;
}

string HashTableCuckoo::get(const string& key) {
    int p1 = hash1(key);
    if (keys1[p1] == key) return vals1[p1];
    int p2 = hash2(key);
    if (keys2[p2] == key) return vals2[p2];
    return "NOT_FOUND";
}

void HashTableCuckoo::remove(const string& key) {
    int p1 = hash1(key);
    if (keys1[p1] == key) { keys1[p1] = ""; vals1[p1] = ""; return; }
    int p2 = hash2(key);
    if (keys2[p2] == key) { keys2[p2] = ""; vals2[p2] = ""; return; }
}

void HashTableCuckoo::print() {
    cout << " Хеш-таблица (Кукушка) \nТаблица 1:\n";
    for (int i = 0; i < CUCKOO_SIZE; i++) {
        cout << "[" << i << "]: ";
        if (keys1[i] != "") cout << keys1[i] << (vals1[i] != "" ? "=" + vals1[i] : "");
        else cout << "пусто";
        cout << "\n";
    }
    cout << "Таблица 2:\n";
    for (int i = 0; i < CUCKOO_SIZE; i++) {
        cout << "[" << i << "]: ";
        if (keys2[i] != "") cout << keys2[i] << (vals2[i] != "" ? "=" + vals2[i] : "");
        else cout << "пусто";
        cout << "\n";
    }
}