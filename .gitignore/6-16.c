#include <stdio.h>
#include <stdlib.h>
// 顶点和边的数据类型定义
typedef int VertextType;
typedef int EdgeType;
// 各种常量定义
#define MAXSIZE 100
// 邻接矩阵图结构体
typedef struct
{
    VertextType vertex[MAXSIZE];           // 顶点数组
    EdgeType arc[MAXSIZE][MAXSIZE];        // 邻接矩阵
    int vertex_num;                        // 顶点数量
    int edge_num;                          // 边的数量
}Mat_Graph;
// 邻接表边结点结构体
typedef struct EdgeNode
{
    int edge_vex;                          // 邻接点下标
    struct EdgeNode* next;                 // 指向下一条边
}EdgeNode;
// 邻接表顶点结构体
typedef struct VertextNode
{
    int in;                                // 入度
    VertextType data;                      // 顶点信息
    EdgeNode* head;                        // 指向该顶点的第一条边
}VertextNode;
// 邻接表整体定义
typedef VertextNode Adj_List[MAXSIZE];
// 邻接表图结构体
typedef struct
{
    Adj_List adj_list;                     // 顶点邻接表
    int vertex_num;                        // 顶点数
    int edge_num;                          // 边数
}Adj_Graph;
typedef Adj_Graph* Adj_List_Graph;
// 栈及其全局变量（配合拓扑排序用）
int top = -1;
int stack[MAXSIZE];
// 栈入栈操作
void push(int e)
{
    if (top > MAXSIZE)
    {
        printf("满了\n");
        return;
    }
    top++;
    stack[top] = e;
}
// 栈出栈操作
int pop()
{
    if (top == -1)
    {
        printf("空的\n");
        return 0;
    }
    int elem = stack[top];
    top--;
    return elem;
}
// 判栈空
int is_empty()
{
    if (top == -1)
    {
        return 0;   // 空返回0
    }
    else
    {
        return 1;   // 非空返回1
    }
}
// 构造邻接矩阵图
void create_graph(Mat_Graph* G)
{
    G->vertex_num = 14;
    G->edge_num = 20;

    for (int i = 0; i < G->vertex_num; i++)
    {
        G->vertex[i] = i;
    }

    for (int i = 0; i < G->vertex_num; i++)
    {
        for (int j = 0; j < G->vertex_num; j++)
        {
            G->arc[i][j] = 0; // 初始化为无边
        }
    }
    // 手动输入所有有向边
    G->arc[0][4] = 1; G->arc[0][5] = 1;G->arc[0][11] = 1;
    G->arc[1][2] = 1; G->arc[1][4] = 1;G->arc[1][8] = 1;
    G->arc[2][5] = 1;G->arc[2][6] = 1;G->arc[2][9] = 1;
    G->arc[3][2] = 1;G->arc[3][13] = 1;
    G->arc[4][7] = 1;
    G->arc[5][8] = 1;G->arc[5][12] = 1;
    G->arc[6][5] = 1;
    G->arc[8][7] = 1;
    G->arc[9][10] = 1; G->arc[9][11] = 1;
    G->arc[10][13] = 1;
    G->arc[12][9] = 1;
}
// 从邻接矩阵转为邻接表，并统计入度
void create_adj_graph(Mat_Graph G, Adj_List_Graph* ALG)
{
    EdgeNode* e;

    *ALG = (Adj_List_Graph)malloc(sizeof(Adj_Graph));
    (*ALG)->vertex_num = G.vertex_num;
    (*ALG)->edge_num = G.edge_num;

    // 顶点初始化
    for (int i = 0; i < G.vertex_num; i++)
    {
        (*ALG)->adj_list[i].in = 0;
        (*ALG)->adj_list[i].data = G.vertex[i];
        (*ALG)->adj_list[i].head = NULL;
    }
    // 扫描邻接矩阵，将所有边转化为邻接表，同时统计入度
    for (int i = 0; i < G.vertex_num; i++)
    {
        for (int j = 0; j < G.vertex_num; j++)
        {
            if (G.arc[i][j] == 1)
            {
                e = (EdgeNode*)malloc(sizeof(EdgeNode));
                e->edge_vex = j;
                e->next = (*ALG)->adj_list[i].head;
                (*ALG)->adj_list[i].head = e;
                (*ALG)->adj_list[j].in++;
            }
        }
    }
}
// 拓扑排序核心过程
void topological_sort(Adj_List_Graph ALG)
{
    EdgeNode* e;
    int curr;
    int k;

    // 首轮把所有入度为0的顶点入栈
    for (int i = 0; i < ALG->vertex_num; i++)
    {
        if (ALG->adj_list[i].in == 0)
        {
            push(i);
        }
    }

    // 不断出栈并输出，遍历所有顶点
    while(is_empty() != 0)
    {
        curr = pop();
        printf("V%d -> ", ALG->adj_list[curr].data);
        e = ALG->adj_list[curr].head;

        // 对所有邻接点，入度减1，若为0再入栈
        while(e != NULL)
        {
            k = e->edge_vex;
            ALG->adj_list[k].in--;
            if (ALG->adj_list[k].in == 0)
            {
                push(k);
            }
            e = e->next;
        }
    }
}
int main(int argc, char const *argv[])
{
    Mat_Graph G;
    Adj_List_Graph ALG;
    create_graph(&G);          // 构造邻接矩阵图
    create_adj_graph(G, &ALG); // 转为邻接表并统计入度
    topological_sort(ALG);     // 拓扑排序
    return 0;
}