//获取链表长度
int listLength(Node *L)
{
	//用来指向遍历过程中的每一个节点
	Node *p = L;
	//用来计数，存放遍历的次数
	int len = 0;
	//p不为NULL（没到尾节点）就继续循环
	while(p != NULL)
	{
		//每次p向后移动，指向下一个节点
		p = p->next;
		//自增加1，记录循环次数
		len++;
	}
	//返回链表长度
	return len;
}