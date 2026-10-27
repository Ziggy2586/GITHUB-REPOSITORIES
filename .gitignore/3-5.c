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