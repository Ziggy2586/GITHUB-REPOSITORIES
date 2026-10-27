#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100 //数组大小
typedef int ElemType; //队列中元素的数据类型

//队列Queue
typedef struct 
{
	ElemType *data; //用来存储顺序结构队列元素的数组
	int front; //队头指针，总是保存当前队头元素的下标值
	int rear; //队尾指针，总是保存当前队尾元素的下标值
	
}Queue;

//队列初始化
Queue* initQueue()
{
	//使用动态内存分配的方式创建队列
	Queue *q = (Queue*)malloc(sizeof(Queue));
	//使用动态内存分配的方式创建数组，该数组用来保存顺序结构队列中的元素
	q->data = (ElemType*)malloc(sizeof(ElemType) * MAXSIZE);
	//队头指针，总是保存当前队头元素的下标值，初始值设置为0
	q->front = 0;
	//队尾指针，总是保存当前队尾元素的下标值，初始值设置为0
	q->rear = 0;
	return q;
}

//队列入队
int enqueue(Queue *Q, ElemType e)
{
	//判断当前队列是否已满
	if ((Q->rear + 1) % MAXSIZE == Q->front)
	{
		printf("满了\n");
		return 0;
	}
	//新元素入队
	Q->data[Q->rear] = e;
	//新元素入队后，调整队尾指针rear,队尾指针rear总是指向队尾元素的下一个位置
	Q->rear = (Q->rear + 1) % MAXSIZE;
	return 1;
}



//获取队头元素
int getHead(Queue *Q, ElemType *e)
{
	//判断当前队列是否为空
	if (Q->front == Q->rear)
	{
		printf("空的\n");
		return 0;
	}
	//获取队头元素的值
	*e = Q->data[Q->front];
	return 1;
}

int main(int argc, char const *argv[])
{
	//声明一个顺序结构的队列q，调用initQueue函数返回一个顺序结构的队列指针并赋值给q
	Queue *q = initQueue();
	//依次入队
	enqueue(q, 10);
	enqueue(q, 20);
	enqueue(q, 30);
	enqueue(q, 40);
	enqueue(q, 50);
	/*
	//出队两次
	ElemType e;
	dequeue(q, &e);
	printf("%d\n",e);
	dequeue(q, &e);
	printf("%d\n",e);
	//获取队头元素
	getHead(q, &e);
	printf("%d\n",e);
	*/
	return 0;
}



