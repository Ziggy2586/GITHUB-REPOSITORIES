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