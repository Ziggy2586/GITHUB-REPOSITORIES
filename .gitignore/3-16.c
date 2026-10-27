//删除链表中指定位置的节点
int deleteNode(Node *L, int pos)
{
	//用来指向要删除节点的前驱
	Node *p = L;
	//用来控制循环次数
	int i = 0;
	//遍历链表，找到要删除节点的前驱。
	while(i < pos-1)
	{
		//每次循环指向下一个节点
		p = p->next;
		//自增加1，控制循环次数
		i++;
		//如果循环还没结束，发现p的值为NULL，说明删除位置大于尾节点位置，删除位置错误。
		if (p == NULL)
		{
			return 0;
		}
	}

	if(p->next == NULL)
	{
		printf("要删除的位置错误\n");
		return 0;
	}

	//q指向要删除的节点
	Node *q = p->next;
	//让要删除节点的前驱指向要删除节点的后继
	p->next = q->next;
	//释放要删除节点的内存空间
	free(q);
	return 1;
}