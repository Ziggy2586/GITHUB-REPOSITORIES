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