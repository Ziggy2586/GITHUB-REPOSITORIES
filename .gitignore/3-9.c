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

//在顺序表尾部添加新元素
int appendElem(SeqList *L, ElemType e)
{
	//判断当前顺序表是否已满
	if (L->length>=MAXSIZE)
	{
		printf("顺序表已满\n");
		return 0;
	}

	L->data[L->length] = e;
	L->length++;
	return 1;
}

//遍历顺序表
void listElem(SeqList *L)
{
	//循环获取顺序表中data数组的每一个元素
	for (int i = 0; i < L->length; i++)
	{
		printf("%d ", L->data[i]);
	}
	printf("\n");
}

//在顺序表中指定位置插入新元素
int insertElem(SeqList *L, int pos, ElemType e)
{
	//判断顺序表的存储空间是否已经满了
	if(L->length >= MAXSIZE)
	{
		printf("表已经满了\n");
		return 0;
	}
	
	//判断插入的位置是否合适
	if (pos < 1 || pos > L->length)
	{
		printf("插入位置错误\n");
		return 0;
	}

	
	//从当前顺序表的最后一个位置，循环到要插入新元素的位置
	for (int i = L->length-1; i >= pos-1; i--)
	{
		L->data[i+1] = L->data[i]; //将元素向后移动一个位置
	}
	L->data[pos-1] = e; //在指定位置插入新元素
	L->length++; //插入成功后顺序表长度加1
		
	return 1;
}

//删除顺序表中指定位置的元素
int deleteElem(SeqList *L, int pos, ElemType *e)
{
	//判断当前顺序表是否为空，空表无法删除数据
	if(L->length == 0)
	{
		printf("空表\n");
		return 0;
	}
	//判断删除的位置是否合适
	if (pos < 1 || pos > L->length)
	{
		printf("删除数据位置有误\n");
		return 0;
	}

	//保存删除的数据
	*e = L->data[pos-1];
	//有可能要删除的数据碰巧是最后一个，如果是最后一个就不需要从后向前覆盖数据了
	if (pos < L->length)
	{
		//从指定位置的下一个位置一直循环到顺序表的最后一个元素的位置
		for (int i = pos; i < L->length; i++)
		{
			//依次将每一个元素的值复制并赋值到前一个元素的位置
			L->data[i-1] = L->data[i];
		}
	}
	L->length--; //最后length减1
	return 1;
}

//查找某个元素在顺序表中的位置
int findElem(SeqList *L, ElemType e)
{
	//判断顺序表是否为空，空表无法查找
	if (L->length == 0)
	{
		printf("空列表\n");
		return 0;
	}
	//遍历顺序表
	for (int i = 0; i < L->length; i++)
	{
		//依次对比顺序表中的元素与要查找的目标元素
		if(L->data[i] == e)
		{
			//如果找到目标元素，返回位置
			return i + 1;
		}
	}
	return 0;
}

int main(int argc, char const *argv[])
{
	//声明一个顺序的指针list，调用initList函数返回一个顺序表的指针并赋值给list
	SeqList *list = initList();
	printf("初始化成功，目前长度占用%d\n",list->length);

	//在尾部添加新元素
	appendElem(list, 88);
	appendElem(list, 67);
	appendElem(list, 40);
	appendElem(list, 8);
	appendElem(list, 23);
	//遍历查看添加数据是否成功
	listElem(list);

	//在指定位置添加数据
	insertElem(list, 1, 18);
	//遍历查看添加数据是否成功
	listElem(list);

	//用来保存删除的数据
	ElemType delData;
	//删除指定位置数据
	deleteElem(list, 2, &delData);
	printf("被删除的数据为：%d\n", delData);
	//遍历查看删除数据是否成功
	listElem(list);

	//查找元素
	printf("%d\n", findElem(list, 40));

	return 0;
}