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


int main(int argc, char const *argv[])
{
	
	
	return 0;
}



