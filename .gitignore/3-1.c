#define MAXSIZE 100 //数组大小
typedef int ElemType; //顺序表中元素的数据类型

//顺序表SeqList
typedef struct
{
	ElemType data[MAXSIZE]; //用来存储顺序表元素的数组
	int lenght; //表示当前顺序表中存储元素的个数
}SeqList;