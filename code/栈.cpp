#include<iostream>
using namespace std;
typedef int elem;
class StackNode{
    public:
    elem data;
    class StackNode *next;
};
StackNode* initStack()
    {
        StackNode *s=new StackNode;
        s->data=0;
        s->next=nullptr;
        return s;
    }
 int listStack(StackNode* s)
{
    if(s->next==nullptr)
    {
        cout<<"空栈"<<endl;
        return 0;
    }
    while(s!=nullptr)
    {
        s=s->next;
        cout<<s->data<<" ";
    }
    cout<<endl;
    return 1;
}
//新元素进栈
void push(StackNode* s,elem e)
{
    StackNode* p=new StackNode;
    p->data=e;
    p->next=s->next;
    s->next=p;
}
//栈顶元素出栈
int pop(StackNode* s,elem* e)
{
    if(s->next==nullptr)
    {
        cout<<"空栈"<<endl;
        return 0;
    }
    StackNode* q=s->next;
    *e=q->data;
    s->next=q->next;
    delete q;
    return 1;
}
//获取栈顶元素
int getTop(StackNode* s,elem* e)
{
    if(s->next==nullptr)
    {
        cout<<"空栈"<<endl;
        return 0;
    }
    *e=s->next->data;
    return 1;
}
int main()
{
    StackNode* s=initStack();
    push(s,10);
    push(s,20);
    push(s,30);
    listStack(s);

    elem e;
    getTop(s,&e);
    cout<<e<<endl;

    pop(s,&e);
    cout<<e<<endl;
    listStack(s);
    return 0;
}
