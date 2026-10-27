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

int main(int argc, char const *argv[])
{
	//声明一个顺序结构的队列q，调用initQueue函数返回一个顺序结构的队列指针并赋值给q
	Queue *q = initQueue();
	return 0;
}



