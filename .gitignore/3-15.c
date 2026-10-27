//在链表的指定位置插入数据
int insertNode(Node *L, int pos, ElemType e)
{
	//用来保存插入位置的前驱节点
	Node *p = L;
	//用来控制循环次数
	int i = 0;
	
	//遍历链表找到插入位置的前驱节点
	while(i < pos-1)
	{
		//每次循环指向下一个节点
		p = p->next;
		//自增加1，控制循环次数
		i++;
		//如果循环还没结束，发现p的值为NULL，说明插入位置大于尾节点位置，插入位置错误。
		if (p == NULL)
		{
			return 0;
		}
	}
	
	//创建要插入的新节点
	Node *q = (Node*)malloc(sizeof(Node));
	//为数据域赋值
	q->data = e;
	//新节点，指向插入位置前驱指向的节点
	q->next = p->next;
	//插入位置前驱指向新节点
	p->next = q;
	return 1;
}