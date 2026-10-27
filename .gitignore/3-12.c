//头插法函数
void insertHead(Node* L, ElemType e)
{
	//使用动态内存分配的形式创建新节点
	Node *p = (Node*)malloc(sizeof(Node));
	//将新节点的值赋值给数据域
	p->data = e;
	//将头节点指针域的内容赋值给新节点的指针域
	p->next = L->next;
	//将新结点的地址赋值给头节点的指针域
	L->next = p;
	return 1;
}