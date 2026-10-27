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

int main(int argc, char const *argv[])
{
	//声明一个链式结构的栈s,调用initStack函数返回一个链式结构的栈指针并赋值给s
	StackNode *s = initStack();
	return 0;
}