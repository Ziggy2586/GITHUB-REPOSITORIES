#include <stdio.h>

typedef int ElemType;//栈中元素的数据类型

//链式结构栈的节点 StackNode
typedef struct StackNode
{
	ElemType data; //数据域：存放栈中的元素值；
	struct StackNode *next; //指针域：存放指向下一个节点的地址（指针）
}StackNode;

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}