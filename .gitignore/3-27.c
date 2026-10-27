#include <stdio.h>
#include <stdlib.h>

//链表中元素的数据类型
typedef int ElemType;

// 双向链表节点结构
typedef struct DNode {
	// 数据域：存储节点的数据
    ElemType data;
    // 指针域：指向前驱节点            
    struct DNode *prior;
    // 指针域：指向后继节点      
    struct DNode *next;       
} DNode;

// 初始化双向链表，创建头节点
DNode* initDoublyList() {
    DNode *head = (DNode*)malloc(sizeof(DNode));
    // 头节点数据域赋特殊值
    head->data = 0;
    // 头节点的前驱为空          
    head->prior = NULL;
     // 头节点的后继为空      
    head->next = NULL;      
    return head;
}

int main(int argc, char const *argv[])
{
	DNode* list = initDoublyList();
	return 0;
}