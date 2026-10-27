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

//队列入队
void enqueue(Queue *q, ElemType e)
{
	//使用动态内存分配的方式创建新节点
	QueueNode *node = (QueueNode*)malloc(sizeof(QueueNode));
	//初始化新节点
	node->data = e;
	node->next = NULL;
	//尾插法入队
	q->rear->next = node;
	//入队后调整队尾指针rear位置，链式结构队列的队尾指针rear总是指向队尾元素
	q->rear = node;
}

//出队
int dequeue(Queue *q, ElemType *e)
{
	//判断当前队列是否为空
	if (q->front == q->rear)
	{
		printf("空的\n");
		return 0;
	}

	QueueNode *node = q->front->next; //用指针node记录要出队的节点
	*e = node->data;  //获取出队元素的值
	q->front->next = node->next; //改变头节点的后继节点实现出队
	//如果发现要出队的节点是尾节点，说明出队后只剩下头节点
	//于是让队头指针front与队尾指针rear都指向头节点
	if (q->rear == node)
	{
		q->rear = q->front;
	}
	free(node); //释放出队节点
	return 1;
}

//获取队头元素
int getHead(Queue *q, ElemType *e)
{
	//判断当前队列是否为空
	if (q->front == q->rear)
	{
		printf("空的\n");
		return 0;
	}
	//前队列的队头指针（也就是头节点）的next域的data,就是当前队列队头元素的值
	*e = q->front->next->data;
	return 1;
}

int main(int argc, char const *argv[])
{
	Queue *q = initQueue();
	//依次入队
	enqueue(q, 10);
	enqueue(q, 20);
	enqueue(q, 30);
	enqueue(q, 40);
	enqueue(q, 50);
	//出队
	ElemType e;
	dequeue(q, &e);
	printf("出队：%d\n", e);
	dequeue(q, &e);
	printf("出队：%d\n", e);
	//获取队头元素
	getHead(q, &e);
	printf("队头元素：%d\n", e);
	return 0;
}