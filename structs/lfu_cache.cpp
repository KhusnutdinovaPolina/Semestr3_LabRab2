#include "lfu_cache.h"
#include <iostream>
using namespace std;

LFUCache::LFUCache(int cap) {
    capacity = cap;
    size = 0;
    currentTime = 0;
    max_items = 1000; // Максимально возможное количество элементов
    items = new LFUNode[max_items];
}

LFUCache::~LFUCache() {
    delete[] items;
}

void LFUCache::set(int key, int value) {
    // Проверяем, есть ли уже такой ключ
    for (int i = 0; i < size; i++) {
        if (items[i].key == key) {
            items[i].value = value; //обновляем значение и увеличиваем частоту и обновляем время
            items[i].frequency++;
            items[i].timestamp = currentTime++;
            return;
        }
    }

    // Кэш полон, удаляем наименее используемый
    if (size == capacity) {
        int minIdx = 0;
        for (int i = 1; i < size; i++) {
            // Если частота меньше, или частота равна, но время старее
            if (items[i].frequency < items[minIdx].frequency ||
               (items[i].frequency == items[minIdx].frequency && items[i].timestamp < items[minIdx].timestamp)) {
                minIdx = i;
               }
        }
        // Удаляем элемент, сдвигая массив влево
        for (int i = minIdx; i < size - 1; i++) {
            items[i] = items[i + 1];
        }
        size--;
    }

    // Добавляем новый элемент если место есть или после удаления если места нет
    items[size++] = LFUNode(key, value, 1, currentTime++);
}

int LFUCache::get(int key) {
    for (int i = 0; i < size; i++) {
        if (items[i].key == key) {
            items[i].frequency++;      // Увеличиваем частоту и обновляем время
            items[i].timestamp = currentTime++;
            return items[i].value;
        }
    }
    return -1;
}

void LFUCache::print() {
    cout << "Кэш: [";
    for (int i = 0; i < size; i++) {
        if (i > 0) cout << ", ";
        cout << items[i].key << ":" << items[i].value << "(f=" << items[i].frequency << ")";
    }
    cout << "]\n";
}