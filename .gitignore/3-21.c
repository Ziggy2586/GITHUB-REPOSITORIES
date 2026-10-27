#include <stdio.h>
#include <stdlib.h>

//链表中元素的数据类型
typedef int ElemType;

// Node结构体 ，表示循环链表中的一个结点
typedef struct node{
	ElemType data;//数据域：存放链表中的元素值；
	struct node *next;//指针域：存放指向下一个节点的地址（指针）
}Node;

//获取尾部节点
Node*  getTail(Node  *L)
{
	//L为头节点，将头节点赋值给指针p
	Node *p = L;
	//以循环的方式遍历每一个节点，直到发现某个节点的指针域为头节点，说明该节点为尾节点
	while(p->next != L)
	{
		//p指向下一个节点
		p = p->next;
	}
	//返回找到的尾节点
	return p;
}

//尾插法插入节点
Node* insertTailCircular(Node* L, Node *tail, ElemType e) {
	//L为头节点，tail为当前尾节点，e为要插入的数据
	//使用动态内存分配的方式创建新节点
    Node *newNode = (Node*)malloc(sizeof(Node));
    //将新节点的值赋值给数据域
    newNode->data = e;
    //让尾节点指向新节点
    tail->next = newNode;
    //新节点将成为新的尾节点，所以将头节点赋值给新节点的指针域
    newNode->next = L;
    //返回新节点（新的尾节点）
    return newNode;
}


int main(int argc, char const *argv[])
{
	
	return 0;
}