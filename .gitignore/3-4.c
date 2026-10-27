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