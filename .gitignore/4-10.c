#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;//栈中元素的数据类型

//链式结构栈的节点 StackNode
typedef struct StackNode
{
	ElemType data; //数据域：存放栈中的元素值；
	struct StackNode *next; //指针域：存放指向下一个节点的地址（指针）
}StackNode;

//初始化
StackNode* initStack()
{
	StackNode *s = (StackNode*)malloc(sizeof(StackNode));
	s->data = 0;
	s->next = NULL;
	return s;
}

//新元素进栈
void push(StackNode *s, ElemType e)
{
	//使用动态内存分配的形式创建新节点
	StackNode *p = (StackNode*)malloc(sizeof(StackNode));
	//将新节点的值赋值给数据域
	p->data = e;
	//将头节点指针域的内容赋值给新节点的指针域
	p->next = s->next;
	//将新结点的地址赋值给头节点的指针域
	s->next = p;
}

int main(int argc, char const *argv[])
{
	//声明一个链式结构的栈s,调用initStack函数返回一个链式结构的栈指针并赋值给s
	StackNode *s = initStack();
	return 0;
}