#include <stdio.h>
#include <stdlib.h>

////链表中元素的数据类型
typedef int ElemType;

// Node结构体 ，表示链表中的一个结点
typedef struct node{
	ElemType data;//数据域：存放链表中的元素值；
	struct node *next;//指针域：存放指向下一个节点的地址（指针）
}Node;

//初化链表函数
Node* initList()
{
	//在堆内存中开辟空间用来存放头节点
	Node *head = (Node*)malloc(sizeof(Node));
	//通常头节点的data会赋一个特殊值，例如0或-1
	head->data = 0;
	//初始化时，头节点的指针域为NULL
	head->next = NULL;
	return head;
}

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
}

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

//程序入口main函数
int main(int argc, char const *argv[])
{
	//调用函数，初始化链表，返回（头）结点指针
	Node *list = initList();
	//头插法添加新节点
	insertHead(list, 70);
	insertHead(list, 80);
	insertHead(list, 90);
	//遍历链表
	listNode(list);
	//释放链表
	freeList(list);
	//获取尾节点
	Node *tail = getTail(list);
	//连续使用尾插法添加数据，注意：返回值为最新的尾节点，所以不需要重新调用函数获取尾节点
	tail  = insertTail(tail, 10);
	tail  = insertTail(tail, 20);
	tail  = insertTail(tail, 30);
	//遍历链表
	listNode(list);
	//在链表指定位置插入节点
	insertNode(list, 2, 15);
	//遍历链表
	listNode(list);
	//删除链表中指定位置节点
	deleteNode(list, 2);
	//遍历链表
	listNode(list);
	//查看链表长度
	printf("%d\n", listLength(list));
	//释放链表
	freeList(list);
	//查看释放后链表长度，注意：这里长度返回1是因为还保留着头节点
	printf("%d\n", listLength(list));
	return 0;
}