#include<iostream>
using namespace std;
typedef int elem;

class Node{
    public:
    elem data;
    Node* next;
};
Node* initNode()
{
    Node* head=new Node;
    head->data=0;
    head->next=head;//头节点指向自己
    return head;
}
void insertHead(Node* L,elem e)
{
    Node* p=new Node;
    p->data=e;
    p->next=L->next;
    L->next=p;
}
int listNode(Node* L)
{

    if(L->next==L)
    {
        cout<<"空链表"<<endl;
        return 0;
    }
    Node* p=L->next;
    while ( p!=L )
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
    return 1;
}
int main(int argc,char const* argv[])
{
    Node* p=initNode();
    insertHead(p,10);
    insertHead(p,20);
    insertHead(p,30);
    insertHead(p,40);
    insertHead(p,50);
    listNode(p);
    return 0;
}