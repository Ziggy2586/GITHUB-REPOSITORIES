#include <stdio.h>
#include <stdlib.h>

//链表中元素的数据类型
typedef int ElemType;

// Node结构体 ，表示循环链表中的一个结点
typedef struct node{
	ElemType data;//数据域：存放链表中的元素值；
	struct node *next;//指针域：存放指向下一个节点的地址（指针）
}Node;

//初始化循环链表
Node* initCircularList() {
    Node *head = (Node*)malloc(sizeof(Node));
    head->data = 0;          // 头节点数据可为特殊值
    head->next = head;       // 头节点指向自己
    return head;
}

int main(int argc, char const *argv[])
{
	//调用函数，初始化循环链表，返回头结点指针
	Node *cirList = initCircularList();
	return 0;
}