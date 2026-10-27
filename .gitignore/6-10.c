#include <stdio.h>
typedef char VertexType;     // 顶点的数据类型（此处为字符，如 'A'~'I'）
typedef int EdgeType;        // 边的权值类型（此处用 1 表示有边，0 表示无边）
#define MAXSIZE 100          // 最大顶点数

// 定义图的邻接矩阵结构体
typedef struct
{
    VertexType vertex[MAXSIZE];        // 顶点数组
    EdgeType arc[MAXSIZE][MAXSIZE];    // 邻接矩阵：arc[i][j] = 1 表示顶点 i 与顶点 j 有边
    int vertex_num;                    // 顶点数
    int edge_num;                      // 边数
} Mat_Grph;

int visited[MAXSIZE];                 // 标记数组：记录顶点是否被访问过

// 创建图（邻接矩阵方式）
void create_graph(Mat_Grph* G)
{
    // 设置顶点数和边数
    G->vertex_num = 9;
    G->edge_num = 15;

    // 设置顶点名称（A ~ I）
    G->vertex[0] = 'A';
    G->vertex[1] = 'B';
    G->vertex[2] = 'C';
    G->vertex[3] = 'D';
    G->vertex[4] = 'E';
    G->vertex[5] = 'F';
    G->vertex[6] = 'G';
    G->vertex[7] = 'H';
    G->vertex[8] = 'I';

    // 初始化邻接矩阵为 0（表示无边）
    for (int i = 0; i < G->vertex_num; i++)
    {
        for (int j = 0; j < G->vertex_num; j++)
        {
            G->arc[i][j] = 0;
        }
    }

    // 添加边（无向图，只添加上三角即可，后续通过对称补充下三角）
    // A-B, A-F
    G->arc[0][1] = 1;
    G->arc[0][5] = 1;

    // B-C, B-G, B-I
    G->arc[1][2] = 1;
    G->arc[1][6] = 1;
    G->arc[1][8] = 1;

    // C-D, C-I
    G->arc[2][3] = 1;
    G->arc[2][8] = 1;

    // D-E, D-G, D-H, D-I
    G->arc[3][4] = 1;
    G->arc[3][6] = 1;
    G->arc[3][7] = 1;
    G->arc[3][8] = 1;

    // E-F, E-H
    G->arc[4][5] = 1;
    G->arc[4][7] = 1;

    // F-G
    G->arc[5][6] = 1;

    // G-H
    G->arc[6][7] = 1;

    // 对称赋值：使邻接矩阵对称，表示无向图
    for (int i = 0; i < G->vertex_num; i++)
    {
        for (int j = 0; j < G->vertex_num; j++)
        {
            G->arc[j][i] = G->arc[i][j];
        }
    }
}

// 深度优先遍历（从第 i 个顶点出发）
void dfs(Mat_Grph G, int i)
{
    visited[i] = 1;                  // 标记该顶点已访问
    printf("%c\n", G.vertex[i]);     // 输出当前顶点名称

    // 遍历所有顶点，检查与当前顶点 i 相连且未访问的顶点 j
    for (int j = 0; j < G.vertex_num; j++)
    {
        if (G.arc[i][j] == 1 && visited[j] == 0)
        {
            dfs(G, j);               // 递归访问
        }
    }
}

int main(int argc, char const *argv[])
{
    Mat_Grph G;
    // 创建图
    create_graph(&G);
    // 初始化 visited 数组
    for (int i = 0; i < G.vertex_num; i++)
    {
        visited[i] = 0;
    }
    // 从顶点 A（编号0）开始 DFS 遍历
    dfs(G, 0);
    return 0;
}
