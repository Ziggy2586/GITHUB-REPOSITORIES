#include <stdio.h>
#include<stdlib.h>

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

//初始化
Queue* initQueue()
{
	//使用动态内存分配的方式创建结构体Queue指针变量q
	Queue *q = (Queue*)malloc(sizeof(Queue));
	//使用动态内存分配的方式创建结构体QueueNode指针变量node,node是链表的头节点
	QueueNode *node = (QueueNode*)malloc(sizeof(QueueNode));
	//为头节点赋初值
	node->data = 0;
	node->next = NULL;
	//队头指针与队尾指针初始化，将头节点赋值给队头指针和队尾指针
	q->front = node;
	q->rear = node;
	return q;
}

int main(int argc, char const *argv[])
{
	Queue *q = initQueue();
	return 0;
}