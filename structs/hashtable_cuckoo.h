#ifndef HASHTABLE_CUCKOO_H
#define HASHTABLE_CUCKOO_H
#include <string>
using namespace std;

const int CUCKOO_SIZE = 10;
const int MAX_KICKS = 20;

struct HashTableCuckoo {
    string keys1[CUCKOO_SIZE];
    string vals1[CUCKOO_SIZE];
    string keys2[CUCKOO_SIZE];
    string vals2[CUCKOO_SIZE];

    HashTableCuckoo();
    int hash1(const string& key);
    int hash2(const string& key);

    bool insert(const string& key);
    bool insert(const string& key, const string& value);

    bool search(const string& key);
    string get(const string& key);
    void remove(const string& key);
    void print();
};

#endif