#include "task5_tree.h"
#include <iostream>
#include <string>
using namespace std;

int insertBST(TNode*& root, int val, int depth) {
    // Если дошли до пустого места — создаем узел
    if (root == nullptr) {
        root = new TNode(to_string(val)); //
        return depth; // Возвращаем глубину, на которой создали
    }

    // Условие для BST
    if (val < stoi(root->data)) {
        return insertBST(root->left, val, depth + 1);
    }
    else if (val > stoi(root->data)) {
        return insertBST(root->right, val, depth + 1);
    }

    // Если равно, то такое число уже есть
    return 0;
}


void clearTree(TNode* node) {
    if (!node) return;
    clearTree(node->left);
    clearTree(node->right);
    delete node;
}

void runTask5() {
    cout << "\n Задание 5: Глубина добавляемых элементов \n";
    cout << "Введите числа (0 - конец ввода):\n";

    TNode* root = nullptr; // Дерево пустое
    int val;

    // Читаем числа пока не будет 0
    while (cin >> val && val != 0) {

        int depth = insertBST(root, val, 1); //вставляем, глубина корня 1

        // Если depth > 0, значит число добавилось, если 0, уже было
        if (depth > 0) {
            cout << depth << " ";
        }
    }
    cout << "\n";
    clearTree(root);
}