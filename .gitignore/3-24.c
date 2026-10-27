#include <stdio.h>
#include <stdlib.h>

//链表中元素的数据类型
typedef int ElemType;

// Node结构体 ，表示循环链表中的一个结点
typedef struct node{
	ElemType data;//数据域：存放链表中的元素值；
	struct node *next;//指针域：存放指向下一个节点的地址（指针）
}Node;

//初始化循环链表
Node* initCircularList() {
    Node *head = (Node*)malloc(sizeof(Node));
    head->data = 0;          // 头节点数据可为特殊值
    head->next = head;       // 头节点指向自己
    return head;
}

//获取尾部节点
Node*  getTail(Node  *L)
{
	//L为头节点，将头节点赋值给指针p
	Node *p = L;
	//以循环的方式遍历每一个节点，直到发现某个节点的指针域为头节点，说明该节点为尾节点
	while(p->next != L)
	{
		//p指向下一个节点
		p = p->next;
	}
	//返回找到的尾节点
	return p;
}

//尾插法插入节点
Node* insertTailCircular(Node* L, Node *tail, ElemType e) {
	//L为头节点，tail为当前尾节点，e为要插入的数据
	//使用动态内存分配的方式创建新节点
    Node *newNode = (Node*)malloc(sizeof(Node));
    //将新节点的值赋值给数据域
    newNode->data = e;
    //让尾节点指向新节点
    tail->next = newNode;
    //新节点将成为新的尾节点，所以将头节点赋值给新节点的指针域
    newNode->next = L;
    //返回新节点（新的尾节点）
    return newNode;
}

//遍历循环链表
void traverseCircularList(Node* L) {
	//L为头节点，获取头节点的指针域
    Node *p = L->next;
    //遍历条件改为判断是否回到头节点
    while(p != L) {       
    	//输出节点数据
        printf("%d ", p->data);
        //p指向下一个节点
        p = p->next;
    }
    printf("\n");
}

//删除循环链表中指定位置节点
int deleteCircularNode(Node* L, int pos) {
	//L为头节点，pos为要删除节点的位置
	//用来指向要删除节点的前驱
    Node *p = L;
    //用来控制循环次数
    int i = 0;
    //遍历链表，找到要删除节点的前驱。
    while(i < pos - 1) {
    	//每次循环指向下一个节点
        p = p->next;
        //自增加1，控制循环次数
        i++;
        //如果循环还没结束，发现p的后继为头节点，说明删除位置大于尾节点位置，删除位置错误。
        if(p->next == L) {
            return 0; 
        }
    }
    //q指向要删除的节点
    Node *q = p->next;
    //让要删除节点的前驱指向要删除节点的后继
    p->next = q->next;
    //释放要删除节点的内存空间
    free(q);
    return 1;
}

//获取循环链表长度
int circularListLength(Node *L)
{
    //L为头节点
    //p用来指向遍历过程中的每一个节点
    Node *p = L->next;
    //用来计数，存放遍历的次数
    int len = 0;
    //p不为L（没到尾节点）就继续循环
    while(p != L)
    {
        //每次p向后移动，指向下一个节点
        p = p->next;
        //自增加1，记录循环次数
        len++;
    }
    //返回循环链表长度
    return len;
}


int main(int argc, char const *argv[])
{
	Node *cirList = initCircularList();
	Node* tail = getTail(cirList);
	tail = insertTailCircular(cirList, tail, 10);
	tail = insertTailCircular(cirList, tail, 20);
	tail = insertTailCircular(cirList, tail, 30);
	traverseCircularList(cirList);
	deleteCircularNode(cirList, 2);
	traverseCircularList(cirList);
    printf("%d\n", circularListLength(cirList));
	return 0;
}