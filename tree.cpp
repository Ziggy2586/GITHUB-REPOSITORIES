#include<iostream>
using namespace std;
typedef char elem;
class treeNode{
    public:
    //数据域
    elem data;
    //指针域
    treeNode* lchild;
    treeNode* rchild;
};

typedef treeNode* biNode;

// 表示二叉树中的内容，#表示空
char str[] = "ABDH#K###E##CFI###G#J##";
int idx =0;
//前序遍历的顺序构建二叉树
void createTree(biNode* T)
{
    char ch = str[idx++];
    if(ch='#')
    {
        *T=nullptr;
    }
    else
    {
        *T = new treeNode;//创建新节点
        (*T)->data=ch;//创建数据域
        createTree(&(*T)->lchild);// 递归构建左子树
        createTree(&(*T)->rchild);// 递归构建右子树
    }
}

int main()
{
    biNode T;
    createTree(&T);
    return 0;
}