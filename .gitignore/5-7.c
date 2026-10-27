#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;

// 定义线索二叉树的节点结构
typedef struct ThreadNode {
    ElemType data; // 节点存储的数据
    struct ThreadNode *lchild; // 左指针：指向左孩子或前驱
    struct ThreadNode *rchild; // 右指针：指向右孩子或后继
    int ltag; // 左标志：0 表示左孩子，1 表示前驱线索
    int rtag; // 右标志：0 表示右孩子，1 表示后继线索
} ThreadNode;

typedef ThreadNode* ThreadTree;