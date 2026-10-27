#include<iostream>
using namespace std;
#define MAXSIZE 100
typedef int elementype;
struct Node{
    elementype *data;
    int length;
};
//初始化顺序表,动态分配内存
Node *initlist()
{
    Node *head=new Node;
    head->data=new elementype[MAXSIZE];
    head->length=0;
    return head;
}
//在尾部添加元素
int appendElem(Node* p,elementype e)
{
    //检查是否满了
    if(p->length>=MAXSIZE)
    {
        cout<<"full!!!"<<endl;
        return 0;
    }
    p->data[p->length]=e;
    p->length++;
    return 1;
}
//遍历顺序表
void elemlist(Node* p)
{
    for(int i=0;i<p->length;i++)
    {
        cout<<p->data[i]<<" ";
    }
    cout<<endl;
}
//在顺序表指定位置插入元素
int insertElem(Node *p,int pos,int e)
{
    //看表是否已满
    if(p->length>=MAXSIZE)
    {
        cout<<"满了！！！"<<endl;
        return 0;
    }
    //pos是否在合适范围
    if(pos<1||pos>MAXSIZE)
    {
        cout<<"超出范围！！！"<<endl;
    }
    //顺序表从尾部开始整体向后移
    for(int i=p->length;i>=pos;i--)
    {
        p->data[i]=p->data[i-1];
    }
    p->data[pos-1]=e;
    p->length++;
    return 1;
}
// 删除指定位置的元素
int deleteElem(Node* p,int pos,elementype* e)//e用来保存被删除的元素
{
    //检查顺序表是否为0
    if(p->length==0)
    {
        cout<<"顺序表为0!!!"<<endl;
        return 0;
    }
    //检查删除位置是否合适
    if(pos < 1||pos>p->length)
    {
        cout<<"目标不合法！！！"<<endl;
    }
    *e=p->data[pos-1];
    //
    if(pos<p->length)
    {
       for(int i=pos;i<=p->length-1;i++)
       {
           p->data[i-1]=p->data[i];
       }
    }
    return 1;
}
//查找某个元素
int findElem(Node *p,elementype e)
{
    if(p->length==0)
    {
        cout<<"空表"<<endl;
        return 0;
    }
    for(int i=0;i<p->length;i++)
    {
        if(p->data[i]==e)
            return i+1;
    }
    return 1;
}

int main(int argc,char const *argv[])
{
    Node *list=initlist();
    elemlist(list);
    appendElem(list,5);
    appendElem(list,8);
    appendElem(list,3);
    appendElem(list,1);
    elemlist(list);

    return 0;
}
