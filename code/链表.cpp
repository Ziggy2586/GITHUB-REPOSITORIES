#include<iostream>
using namespace std;
typedef int elem;
class Node{
    public:
    elem data;//数据域
    Node *next;//指针域
};
//初始化
Node* initList()
{
    Node* head=new Node;
    head->data=0;
    head->next=nullptr;
    return head;
}
//头插法函数
void insertHead(Node *L,elem e)
{
    Node* p=initList();
    p->data=e;
    p->next=L->next;
    L->next=p;
}
//遍历链表
void showList(Node *L)
{
    Node *p=L->next;
    while(p!=nullptr)
    {
        cout<<p->data<<" ";
        p=p->next;//指向下一个节点
    }
    cout<<endl;
}
//获取尾部节点
Node* getTail(Node* L)
{
    Node *p=L;
    while(p->next!=nullptr)
    {
        p=p->next;//p指向下一个节点
    }
    return p;//返回尾部节点
}
//尾插法
void insertTail(Node* L,int e)
{
    Node* p=new Node;
    p->data=e;
    p->next=getTail(L)->next;
    getTail(L)->next=p;
    //return p;
}
//指定位置插入数据
int insertElem(Node* L,int pos,int e)//pos:要插入的位置，e：插入的元素
{
    Node* p=new Node;
    //保存前驱节点
    p=L;
    int i=0;
    while(i<pos-1)
    {
        p=p->next;
        i++;
        //如果前驱节点的下一个节点是空，说明插入错误
        if(p->next==nullptr)
        return 0;

    }
    //创建新节点
    Node* q=new Node;
    //给新节点值
    q->data=e;
    //前驱节点指向新节点
    q->next=p->next;
    p->next=q;
    return 1;
}
//获取链表长度
int listLength(Node* L)
{
    Node* p=L->next;
    int i=0;
    while(p!=nullptr)
    {
        i++;
        p=p->next;
    }
    return i;
}
//释放链表
void freeList(Node* L)
{
    Node* p=L->next;
    Node* q;
    while(p!=nullptr)
    {
        //q指向p的后继节点
        q=p->next;
        delete p;
        p=q;
    }
    L->next=nullptr;
}
int main(int argc,char const *argv[])
{
    Node* p=initList();
    insertTail(p,3);
    insertTail(p,5);
    insertTail(p,9);
    showList(p);

    insertElem(p,2,99);
    showList(p);

    int len=listLength(p);
    cout<<len<<endl;

    freeList(p);
    return 0;
}
