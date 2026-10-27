#include <stdio.h>

typedef int ElemType;//队列中元素的数据类型

//链式结构队列的节点 QueueNode
typedef struct QueueNode
{
	ElemType data; //数据域：存放队列中的元素值；
	struct QueueNode *next; //指针域：存放指向下一个节点的地址（指针）
}QueueNode;

//存放队列的队头指针与队尾指针
typedef struct 
{
	QueueNode *front; //队头指针
	QueueNode *rear; //队尾打针
}Queue;

int main(int argc, char const *argv[])
{
	
	return 0;
}