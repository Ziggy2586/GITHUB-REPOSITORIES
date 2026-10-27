#include <stdio.h>

#define MAXSIZE 100
typedef int ElemType;

//顺序表定义
typedef struct{
	ElemType data[MAXSIZE];
	int length;
}SeqList;

//顺序表初始化函数
void initList(SeqList *L)
{
	L->length = 0;
}

int main(int argc, char const *argv[])
{
	
	SeqList list;//创建顺序表
	initList(&list);//调用函数完成初始化，传入刚刚创建的顺序表地址（指针）
	printf("初始化成功，目前长度占用%d\n",list.length);
	return 0;
}