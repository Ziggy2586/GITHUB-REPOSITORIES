#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;

//二叉树结点
typedef struct TreeNode
{
	ElemType data; // 数据域：存储当前节点的值
	struct TreeNode *lchild; //左孩子指针
	struct TreeNode *rchild; //右孩子指针
}TreeNode;