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

// 双向链表头插法插入新节点
void insertHeadDoubly(DNode* L, ElemType e) {
    // 创建新节点并为数据域赋值
    DNode* newNode = (DNode*)malloc(sizeof(DNode));
    newNode->data = e;

    // 新节点的后继指向原第一个节点（头节点的后继）
    newNode->next = L->next;

    // 若原第一个节点存在，更新它的前驱指针
    if (L->next != NULL) {
        L->next->prior = newNode;
    }

    // 新节点的前驱指针指向头节点
    newNode->prior = L;

    // 头节点的后继指针指向新节点，完成链接
    L->next = newNode;
}


int main(int argc, char const *argv[])
{
	DNode* list = initDoublyList();  // 初始化双向链表

    // 使用头插法插入多个节点
    insertHeadDoubly(list, 10);
    insertHeadDoubly(list, 20);
    insertHeadDoubly(list, 30);

	return 0;
}