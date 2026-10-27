#include <stdio.h>

#define MAXSIZE 100 //数组大小
typedef int ElemType; //栈中元素的数据类型

//栈Stack
typedef struct 
{
	ElemType data[MAXSIZE]; //用来存储顺序结构栈元素的数组
	int top; //栈顶指针，总是保存当前栈顶元素的下标值
	
}Stack;

//初始化栈
void initStack(Stack *s)
{
	s->top = -1; //top变量的初始值为-1
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
	////判断是否是空栈
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
	Stack s; //创建Stack结构体变量s
	initStack(&s); //调用initStack初始化栈
	return 0;
}