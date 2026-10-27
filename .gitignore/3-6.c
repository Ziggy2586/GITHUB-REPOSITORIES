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