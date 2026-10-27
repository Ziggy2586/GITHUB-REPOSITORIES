#include <stdio.h>
typedef int VertexType;    // 顶点的数据类型
typedef int EdgeType;      // 边权值类型
#define MAXSIZE 100        // 顶点的最大数量
#define MAXEDGE 200        // 最大边数
#define MAX 0x10000        // 用于表示不可达的最大值（无穷大）

// 图的结构体定义（邻接矩阵存储）
typedef struct
{
    VertexType vertex[MAXSIZE];         // 顶点数组
    EdgeType arc[MAXSIZE][MAXSIZE];     // 邻接矩阵，存储边的权值
    int vertex_num;                     // 顶点个数
    int edge_num;                       // 边的个数
}Mat_Graph;

// 创建邻接矩阵图
void createGraph(Mat_Graph* G)
{
    G->vertex_num = 9;
    G->edge_num = 16;
    // 初始化顶点信息（编号0~8）
    for (int i = 0; i < G->vertex_num; i++)
    {
        G->vertex[i] = i;
    }
    // 初始化邻接矩阵：对角线为0，其他为MAX
    for (int i = 0; i < G->vertex_num; i++)
    {
        for (int j = 0; j < G->vertex_num; j++)
        {
            if (i == j)
            {
                G->arc[i][j] = 0;  // 自己到自己为0
            }
            else
            {
                G->arc[i][j] = MAX; // 其余初始化为不可达
            }
        }
    }
    // 按题设手动赋权
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
    // 补全对称赋值（如果是无向图则两边都赋值；如果有向图则只需保留一边即可）
    for (int i = 0; i < G->vertex_num; i++)
    {
        for (int j = i; j < G->vertex_num; j++)
        {
            G->arc[j][i] = G->arc[i][j];
        }
    }
}

// Floyd算法：计算所有顶点对间的最短路径及路径还原
void floyd(Mat_Graph G)
{
    int path[MAXSIZE][MAXSIZE];     // path[i][j] 表示i到j路径上的下一个结点
    int distance[MAXSIZE][MAXSIZE]; // distance[i][j] 记录i到j的最短距离
    // 初始化distance和path矩阵
    for (int i = 0; i < G.vertex_num; i++)
    {
        for (int j = 0; j < G.vertex_num; j++)
        {
            distance[i][j] = G.arc[i][j]; // 初始为邻接矩阵的权值
            path[i][j] = j;               // 路径初始设为直接到达j
        }
    }
    // 三重循环核心：尝试每个中转点i是否能让j->k更短
    // j:起始顶点　i:中转顶点　k:终止顶点
    for (int i = 0; i < G.vertex_num; i++)
    {
        for (int j = 0; j < G.vertex_num; j++)
        {
            for (int k = 0; k < G.vertex_num; k++)
            {
                // 若通过i作为中转让j到k更短，则更新
                if (distance[j][k] > distance[j][i] + distance[i][k])
                {
                    distance[j][k] = distance[j][i] + distance[i][k];
                    path[j][k] = path[j][i]; // 路径也随之更新为下一跳
                }
            }
        }
    }
    int k;
    // 输出所有点对的最短路径和路径序列
    for (int i = 0; i < G.vertex_num; i++)
    {
        for (int j = i + 1; j < G.vertex_num; j++)
        {
            printf("V%d->V%d weight:%d ", i, j, distance[i][j]);
            k = path[i][j];
            printf("path:V%d", i);
            while(k != j)
            {
                printf("->V%d", k);
                k = path[k][j];
            }
            printf("->V%d\n", j);
        }
        printf("\n");
    }

}

int main(int argc, char const *argv[])
{
    Mat_Graph G;
    createGraph(&G);  // 构造图
    floyd(G);         // 执行Floyd算法
    return 0;
}
