#include <stdio.h>
typedef int VertexType;
typedef int EdgeType;
#define MAXSIZE 100
#define MAXEDGE 200
#define MAX 0x10000 // 用于表示“无穷大”的值

// 图的结构体定义（邻接矩阵）
typedef struct
{
    VertexType vertex[MAXSIZE];         // 顶点数组
    EdgeType arc[MAXSIZE][MAXSIZE];     // 邻接矩阵
    int vertex_num;                     // 顶点个数
    int edge_num;                       // 边的个数
} Mat_Graph;

// 初始化图的函数
void createGraph(Mat_Graph* G)
{
    G->vertex_num = 9;
    G->edge_num = 16;

    for (int i = 0; i < G->vertex_num; i++)
    {
        G->vertex[i] = i;
    }

    for (int i = 0; i < G->vertex_num; i++)
    {
        for (int j = 0; j < G->vertex_num; j++)
        {
            if (i == j)
                G->arc[i][j] = 0;
            else
                G->arc[i][j] = MAX;
        }
    }
    G->arc[0][1] = 1;
    G->arc[0][2] = 5;
    G->arc[1][2] = 3;
    G->arc[1][3] = 7;
    G->arc[1][4] = 5;
    G->arc[2][4] = 1;
    G->arc[2][5] = 7;
    G->arc[3][4] = 2;
    G->arc[3][6] = 3;
    G->arc[4][5] = 3;
    G->arc[4][6] = 6;
    G->arc[4][7] = 9;
    G->arc[5][7] = 5;
    G->arc[6][7] = 2;
    G->arc[6][8] = 7;
    G->arc[7][8] = 4;
}

// 迪杰斯特拉算法：从顶点v0出发，求到所有点的最短路径
void Dijkstra(Mat_Graph G, int v0, int dist[], int path[])
{
    int final[MAXSIZE]; // final[i]为1表示已确定最短路径，0表示未确定
    int i, j, k, min;

    // 初始化
    for (i = 0; i < G.vertex_num; i++)
    {
        final[i] = 0;                    // 初始时所有点的最短路径都未确定
        dist[i] = G.arc[v0][i];         // dist数组保存起点v0到其他顶点的初始距离
        if (dist[i] < MAX && i != v0)
            path[i] = v0;               // 如果有路径，则前驱是v0
        else
            path[i] = -1;               // 否则没有前驱
    }

    final[v0] = 1; // 起点自身的最短路径已经确定

    // 进行 n-1 次循环，确定其余顶点的最短路径
    for (i = 1; i < G.vertex_num; i++)
    {
        min = MAX;  // 每次从未处理的点中找最小的dist
        for (j = 0; j < G.vertex_num; j++)
        {
            if (!final[j] && dist[j] < min)
            {
                k = j;
                min = dist[j];
            }
        }

        final[k] = 1; // 将k点纳入已确定集合

        // 更新dist和path
        for (j = 0; j < G.vertex_num; j++)
        {
            // 只更新那些尚未处理，且通过k能更近的点
            if (!final[j] && dist[k] + G.arc[k][j] < dist[j])
            {
                dist[j] = dist[k] + G.arc[k][j]; // 更新最短距离
                path[j] = k;                     // 更新前驱节点
            }
        }
    }
}

// 输出最短路径结果
void printPath(int dist[], int path[], int n, int v0)
{
    printf("从顶点 %d 到其他顶点的最短路径如下：\n", v0);
    for (int i = 0; i < n; i++)
    {
        printf("到顶点 %d 的最短路径长度为: %d，路径为: ", i, dist[i]);
        // 回溯输出路径
        int stack[MAXSIZE], top = -1;
        int p = i;
        while (p != -1 && p != v0)
        {
            stack[++top] = p;
            p = path[p];
        }
        printf("%d", v0);
        while (top != -1)
        {
            printf(" -> %d", stack[top--]);
        }
        printf("\n");
    }
}

// 主函数
int main()
{
    Mat_Graph G;
    int dist[MAXSIZE]; // 最短距离数组
    int path[MAXSIZE]; // 最短路径的前驱数组
    createGraph(&G);              // 构建图
    Dijkstra(G, 0, dist, path);   // 从顶点0出发执行Dijkstra算法
    printPath(dist, path, G.vertex_num, 0); // 打印结果
    return 0;
}
