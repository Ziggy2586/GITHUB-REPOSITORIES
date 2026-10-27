//遍历链表
void listNode(Node* L)
{
	//获取头节点的指针域
	Node *p = L->next;
	//只要指针变量p不为空，就持续循环
	while(p != NULL)
	{
		//输出节点数据
		printf("%d　", p->data);
		//p指向下一个节点
		p = p->next;
	}
	printf("\n");
}