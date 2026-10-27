#include <stdio.h>
#include <stdlib.h>
typedef char ElemType;
// 定义二叉树结构体
typedef struct TreeNode {
    ElemType data;  // 当前节点存储的数据（字符型）
    struct TreeNode *lchild;  // 指向左孩子
    struct TreeNode *rchild;  // 指向右孩子
} TreeNode;
typedef TreeNode* BiTree;
// 表示二叉树中的内容，#表示空
char str[] = "ABDH#K###E##CFI###G#J##"; 
int idx = 0;

// 发前序遍历的顺序构建二叉树：每次读取一个字符，递归构建当前节点的左子树和右子树
void createTree(BiTree *T) 
{
    ElemType ch = str[idx++];  // 读取下一个字符
    if (ch == '#') 
    {
        *T = NULL; // 如果是#，则为空节点
    } 
    else 
    {
        *T = (BiTree)malloc(sizeof(TreeNode));  // 创建新节点
        (*T)->data = ch;  // 设置数据域
        createTree(&(*T)->lchild); // 递归构建左子树
        createTree(&(*T)->rchild); // 递归构建右子树
    }
}

int main(int argc, char const *argv[])
{
    //创建二叉树
	BiTree T;
	createTree(&T);
	return 0;
}