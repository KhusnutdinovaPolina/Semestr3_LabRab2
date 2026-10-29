#ifndef LFU_CACHE_H
#define LFU_CACHE_H

#include <string>

// Узел кэша
struct LFUNode {
    int key;
    int value;
    int frequency; // Частота использования
    int timestamp; // Время последнего использования (для разрешения ничьих)

    LFUNode() : key(-1), value(-1), frequency(0), timestamp(0) {}
    LFUNode(int k, int v, int f, int t) : key(k), value(v), frequency(f), timestamp(t) {}
};

struct LFUCache {
    int capacity;
    int size;
    int currentTime; // Счетчик времени, кто старее

    LFUNode* items; //массив, где лежат узлы и его макс размер
    int max_items;

    LFUCache(int cap);
    ~LFUCache();

    void set(int key, int value);
    int get(int key);
    void print();
};

#endif