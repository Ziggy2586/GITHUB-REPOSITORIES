#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100 //数组大小
typedef int ElemType; //栈中元素的数据类型

//栈Stack
typedef struct 
{
	ElemType *data; //用来存储顺序结构栈元素的数组
	int top;
	
}Stack;

//初始化
Stack* initStack()
{
	//使用动态内存分配的方式创建栈
	Stack *s = (Stack*)malloc(sizeof(Stack));
	//使用动态内存分配的方式创建数组，该数组用来保存顺序结构栈中的元素
	s->data = (ElemType*)malloc(sizeof(ElemType) * MAXSIZE);
	//栈顶指针，总是保存当前栈顶元素的下标值
	s->top = -1;
	return s;
}

int main(int argc, char const *argv[])
{
	//声明一个顺序结构的栈s，调用initStack函数返回一个顺序结构的栈指针并赋值给s
	Stack *s = initStack();
	
	return 0;
}



