#include <stdio.h>
#include <stdlib.h>

//链表中元素的数据类型
typedef int ElemType;

// 双向链表节点结构
typedef struct DNode {
	// 数据域：存储节点的数据
    ElemType data;
    // 指针域：指向前驱节点            
    struct DNode *prior;
    // 指针域：指向后继节点      
    struct DNode *next;       
} DNode;

// 初始化双向链表，创建头节点
DNode* initDoublyList() {
    DNode *head = (DNode*)malloc(sizeof(DNode));
    // 头节点数据域赋特殊值
    head->data = 0;
    // 头节点的前驱为空          
    head->prior = NULL;
     // 头节点的后继为空      
    head->next = NULL;      
    return head;
}

// 双向链表头插法插入新节点
void insertHeadDoubly(DNode* L, ElemType e) {
    // 创建新节点并为数据域赋值
    DNode* newNode = (DNode*)malloc(sizeof(DNode));
    newNode->data = e;

    // 新节点的后继指向原第一个节点（头节点的后继）
    newNode->next = L->next;

    // 若原第一个节点存在，更新它的前驱指针
    if (L->next != NULL) {
        L->next->prior = newNode;
    }

    // 新节点的前驱指针指向头节点
    newNode->prior = L;

    // 头节点的后继指针指向新节点，完成链接
    L->next = newNode;
}

// 遍历双向链表
void traverseDoublyList(DNode *L) {
    // 从头节点的后继节点开始遍历
    DNode *p = L->next;
    // 遍历条件为节点指针不为NULL             
    while(p != NULL) {
        // 输出节点数据              
        printf("%d ", p->data);
        // 指针后移     
        p = p->next;                
    }
    printf("\n");
}

// 获取当前双向链表的尾节点
DNode* getTail(DNode *L) {
    // 从头节点开始遍历
    DNode *p = L;     
    // 当后继指针不为空时继续               
    while(p->next != NULL) {
        // 指针后移         
        p = p->next;                 
    }
    // 返回尾节点的指针
    return p;                        
}

// 双向链表尾插法插入新节点
DNode* insertTailDoubly(DNode* tail, ElemType e) {
    // 创建新节点
    DNode* newNode = (DNode*)malloc(sizeof(DNode));
    // 数据域赋值为插入的元素 
    newNode->data = e;
    // 新节点的后继指针为空，成为尾节点              
    newNode->next = NULL;
    // 新节点的前驱指针指向原尾节点           
    newNode->prior = tail;
    // 原尾节点的后继指针指向新节点          
    tail->next = newNode;
    // 返回新的尾节点（新插入节点）           
    return newNode;                 
}

// 删除双向链表中指定位置节点
int deleteDoublyNode(DNode* L, int pos) {
    // 从第一个节点开始
    DNode *p = L->next;
    // 计数器，从第一个有效节点算起             
    int i = 1;                      
    // 遍历找到待删除节点
    while(p != NULL && i < pos) {
        p = p->next;
        i++;
    }
    // 删除位置无效，返回失败
    if(p == NULL) return 0;         
    if(p->next != NULL)
        // 更新后继节点的前驱指针
        p->next->prior = p->prior;
    // 更新前驱节点的后继指针  
    p->prior->next = p->next;
    // 释放被删除节点的空间       
    free(p);                        
    return 1;
}

// 获取双向链表长度
int doublyListLength(DNode *L) {
    // 从第一个节点开始遍历
    DNode *p = L->next;
    // 长度计数器             
    int len = 0;                    
    while(p != NULL) {
        len++;
        p = p->next;
    }
    return len;
}

// 释放双向链表所有节点
void freeDoublyList(DNode* L) {
    // 指向第一个节点
    DNode *p = L->next;             
    DNode *q;
    while(p != NULL) {
        // 暂存下一个节点
        q = p->next;
        // 释放当前节点                
        free(p); 
        // 移动到下一个节点                   
        p = q;                      
    }
    // 头节点后继指针置空
    L->next = NULL;                 
}


int main(int argc, char const *argv[])
{
	DNode* list = initDoublyList();  // 初始化双向链表
    DNode* tail = getTail(list);     // 首次获取尾节点（此时是头节点）

    // 尾插法连续插入节点
    tail = insertTailDoubly(tail, 10);
    tail = insertTailDoubly(tail, 20);
    tail = insertTailDoubly(tail, 30);

    traverseDoublyList(list);        // 遍历输出链表（预期输出：10 20 30）

    deleteDoublyNode(list, 2);

    traverseDoublyList(list);

    printf("%d\n", doublyListLength(list));
	return 0;
}