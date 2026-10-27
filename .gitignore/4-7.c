#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100 //数组大小
typedef int ElemType; //栈中元素的数据类型

//栈Stack
typedef struct 
{
	ElemType *data;
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

//新元素进栈
int push(Stack *s, ElemType e)
{
	//判断是否栈满
	if (s->top >= MAXSIZE - 1)
	{
		printf("栈已满了\n");
		return 0;
	}
	s->top++; //栈顶指针自增加1
	s->data[s->top] = e; //将新元素添加到栈顶位置
	return 1;
}

//栈顶元素出栈
int pop(Stack *s, ElemType *e)
{
	//判断是否是空栈
	if (s->top == -1)
	{
		printf("空的\n");
		return 0;
	}
	*e = s->data[s->top]; //获取出栈元素的值
	s->top--; //栈顶指针值自减1
	return 1;
}

//获取栈顶元素
int getTop(Stack *s, ElemType *e)
{
	//判断是否是空栈
	if (s->top == -1)
	{
		printf("空的\n");
		return 0;
	}
	*e = s->data[s->top];//获取栈顶元素的值
	return 1;
}

int main(int argc, char const *argv[])
{
	//声明一个顺序结构的栈s，调用initStack函数返回一个顺序结构的栈指针并赋值给s
	Stack *s = initStack();
	//依次进栈
	push(s, 10);
	push(s, 20);
	push(s, 30);
	
	//出栈
	ElemType e;
	pop(s, &e);
	printf("%d\n", e);

	//获取栈顶元素
	getTop(s, &e);
	printf("%d\n", e);
	return 0;
}



