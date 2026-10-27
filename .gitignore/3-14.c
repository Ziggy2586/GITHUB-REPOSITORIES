//获取尾部结点
Node*  getTail(Node  *L)
{
	//将头节点赋值给指针p
	Node *p = L;
	//以循环的方式遍历每一个节点，直到发现某个节点的指针域为NULL，说明该节点为尾节点
	while(p->next != NULL)
	{
		//p指向下一个节点
		p = p->next;
	}
	//返回找到的尾节点
	return p;
}

//尾插法
Node* insertTail(Node *tail, ElemType e)
{
	//使用动态内存分配的方式创建新节点
	Node *p = (Node*)malloc(sizeof(Node));
	//将新节点的值赋值给数据域
	p->data = e;
	//让尾节点指向新节点
	tail->next = p;
	//新节点成为新的尾节点，所以将NULL赋值给指针域
	p->next = NULL;
	//返回新节点（新的尾节点）
	return p;
}