#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100 //数组大小
typedef int ElemType; //顺序表中元素的数据类型

//顺序表SeqList
typedef struct{
	//数组指针，该指针指向一个在堆内存中，用来存储顺序表的数组。调用初始化函数时创建数组
	ElemType *data; 
	//表示当前顺序表中存储元素的个数
	int length;
}SeqList;

//顺序表初始化函数－动态分配内存
SeqList* initList()
{
	//在堆内存中开辟空间创建一个顺序表SeqList，并赋值给顺序表指针L
	SeqList *L = (SeqList*)malloc(sizeof(SeqList));
	//在堆内存中创建一个大小为MAXSIZE的数组，并将地址赋值给L中的指针data
	L->data = (ElemType*)malloc(sizeof(ElemType) * MAXSIZE);
	//初始化顺序表大小为0
	L->length = 0;
	return L;
}
int main(int argc, char const *argv[])
{
	//声明一个顺序的指针list，调用initList函数返回一个顺序表的指针并赋值给list
	SeqList *list = initList();
}