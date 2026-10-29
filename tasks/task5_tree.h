#ifndef TASK5_TREE_H
#define TASK5_TREE_H

#include "../structs/cbt.h"

void runTask5();

// Вспомогательная: рекурсивная вставка в BST, возвращает глубину нового узла
int insertBST(TNode*& root, int val, int depth);
void clearTree(TNode* node);

#endif