#include <stdio.h>
#include <stdlib.h>

////链表中元素的数据类型
typedef int ElemType;

// Node结构体 ，表示链表中的一个结点
typedef struct node{
	ElemType data;//数据域：存放链表中的元素值；
	struct node *next;//指针域：存放指向下一个节点的地址（指针）
}Node;

//初化链表函数
Node* initList()
{
	//在堆内存中开辟空间用来存放头节点
	Node *head = (Node*)malloc(sizeof(Node));
	//通常头节点的data会赋一个特殊值，例如0或-1
	head->data = 0;
	//初始化时，头节点的指针域为NULL
	head->next = NULL;
	return head;
}

//程序入口main函数
int main(int argc, char const *argv[])
{
	//调用函数，初始化链表，返回（头）结点指针
	Node *list = initList();
	return 0;
}