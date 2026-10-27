#include <stdio.h>

#define MAXSIZE 100 //数组大小
typedef int ElemType; //栈中元素的数据类型

//栈Stack
typedef struct 
{
	ElemType data[MAXSIZE]; //用来存储顺序表元素的数组
	int top; //栈顶指针，总是保存当前栈顶元素的下标值
	
}Stack;

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}