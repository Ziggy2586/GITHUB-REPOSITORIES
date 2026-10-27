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

//判断当前队列是否真的满了，返回0表示真的满了，返回1表示队列已调整完毕
int queueFull(Queue *Q)
{
	//队头指针front的值如果寺于0，说明当前队列前面有空闲位置，可以调整队列
	if (Q->front > 0)
	{
		//变量step用来保存要将队列中的元素整体向前挪多少个位置
		int step = Q->front;
		//从队头循环到队尾，将每一个元素向前挪动step个位置
		for (int i = Q->front; i <= Q->rear; ++i)
		{
			//调整挪动队列中元素位置
			Q->data[i - step] = Q->data[i];
		}
		//调整位置后，队头指针重新指向下标0
		Q->front = 0;
		//调整位置后，队尾指针指向当前队列中队尾元素的下一个位置
		Q->rear = Q->rear - step;
		return 1;
	}
	else
	{
		printf("真的满了\n");
		return 0;
	}
}

//队列入队
int enqueue(Queue *Q, ElemType e)
{
	//判断队尾指针，是否已指向当前队列最末尾的元素
	if (Q->rear >= MAXSIZE)
	{
		//调用queueFull函数，判断当前队列是否真的满了，如果不是真的满了，则调整队列
		if(!queueFull(Q))
		{
			return 0;
		}
	}
	//新元素入队
	Q->data[Q->rear] = e;
	//入队后队尾指针rear自增加1，队尾指针总rear是指向当前队列中队尾元素的下一个位置
	Q->rear++;
	return 1;
}

//队列出队
int dequeue(Queue *Q, ElemType *e)
{
	//判断当前队列是否为空
	if (Q->front == Q->rear)
	{
		printf("空的\n");
		return 0;
	}
	//获取出队元素的值
	*e = Q->data[Q->front];
	//队头指针front自增加1
	Q->front++;
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
	//出队两次
	ElemType e;
	dequeue(q, &e);
	printf("%d\n",e);
	dequeue(q, &e);
	printf("%d\n",e);
	//获取队头元素
	getHead(q, &e);
	printf("%d\n",e);
	return 0;
}



