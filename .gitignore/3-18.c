//释放链表
void freeList(Node *L)
{
	//节点指针p指向头节点的后继节点
	Node *p = L->next;
	//声明指针q
	Node *q;
	//只要p的值不为NULL，说明还没有到尾节点，还有没被释放的节点。
	while(p != NULL)
	{
		//q指向p的后继节点
		q = p->next;
		//释放p指向的节点
		free(p);
		//p指向q所指向的节点
		p = q;
	}
	//头节点的指针赋值NULL
	L->next = NULL;
}