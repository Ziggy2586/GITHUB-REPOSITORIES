#include <stdio.h>
#include <stdlib.h>
typedef char VertexType;  // 顶点数据类型
typedef int EdgeType;     // 边的权值类型
#define MAXSIZE 100
#define MAXEDGE 200
#define MAX 0x7fffffff  // 表示无穷大，用于无边时初始化邻接矩阵
// 图的结构：邻接矩阵 + 顶点数组
typedef struct
{
	VertexType vertex[MAXSIZE];       // 顶点数组
	EdgeType arc[MAXSIZE][MAXSIZE];   // 邻接矩阵
	int vertex_num;                   // 顶点数量
	int edge_num;                     // 边数量
} Mat_Grph;

// 边的结构体：起点、终点、权值
typedef struct
{
	int beigin;
	int end;
	int weight;
} Edge;

// 创建图（使用邻接矩阵表示）
void create_graph(Mat_Grph* G)
{
	G->vertex_num = 9;
	G->edge_num = 15;

	// 初始化顶点（A~I）
	G->vertex[0] = 'A';
	G->vertex[1] = 'B';
	G->vertex[2] = 'C';
	G->vertex[3] = 'D';
	G->vertex[4] = 'E';
	G->vertex[5] = 'F';
	G->vertex[6] = 'G';
	G->vertex[7] = 'H';
	G->vertex[8] = 'I';

	// 初始化邻接矩阵（先设置为无穷）
	for (int i = 0; i < G->vertex_num; i++)
		for (int j = 0; j < G->vertex_num; j++)
			G->arc[i][j] = (i == j) ? 0 : MAX;

	// 添加各条边（无向图，因此只需输入上三角，后面对称复制）
	G->arc[0][1] = 10;  G->arc[0][5] = 11;
	G->arc[1][2] = 18;  G->arc[1][6] = 16; G->arc[1][8] = 12;
	G->arc[2][3] = 22;  G->arc[2][8] = 8;
	G->arc[3][4] = 20;  G->arc[3][6] = 24; G->arc[3][7] = 16; G->arc[3][8] = 21;
	G->arc[4][5] = 26;  G->arc[4][7] = 7;
	G->arc[5][6] = 17;
	G->arc[6][7] = 19;

	// 由于是无向图，对称赋值
	for (int i = 0; i < G->vertex_num; i++)
		for (int j = 0; j < G->vertex_num; j++)
			G->arc[j][i] = G->arc[i][j];
}

// 交换两条边的位置（用于排序）
void swap(Edge* edges, int i, int j)
{
	int temp;
	temp = edges[i].beigin; edges[i].beigin = edges[j].beigin; edges[j].beigin = temp;
	temp = edges[i].end;    edges[i].end = edges[j].end;       edges[j].end = temp;
	temp = edges[i].weight; edges[i].weight = edges[j].weight; edges[j].weight = temp;
}

// 对边按权值进行升序排序
void sortEdges(Edge edges[], int edge_num)
{
	for (int i = 0; i < edge_num; i++)
		for (int j = i + 1; j < edge_num; j++)
			if (edges[i].weight > edges[j].weight)
				swap(edges, i, j);
}

// 并查集查找操作（用于判断两个点是否在同一集合）
int find(int* parent, int index)
{
	while(parent[index] > 0)
		index = parent[index];
	return index;
}

// 克鲁斯卡尔算法主函数
void Kruskal(Mat_Grph G)
{
	Edge edges[MAXEDGE]; // 存储所有边
	int k = 0;

	// 从邻接矩阵提取所有边（三角上部分）
	for (int i = 0; i < G.vertex_num; i++)
	{
		for (int j = i + 1; j < G.vertex_num; j++)
		{
			if (G.arc[i][j] < MAX)
			{
				edges[k].beigin = i;
				edges[k].end = j;
				edges[k].weight = G.arc[i][j];
				k++;
			}
		}
	}
	// 将所有边按权值从小到大排序
	sortEdges(edges, G.edge_num);
	// 初始化并查集（parent[i] = 0 表示每个点为独立集合）
	int parent[MAXSIZE] = {0};

	int n, m;
	for (int i = 0; i < G.edge_num; i++)
	{
		// 查找边的两个端点所属集合
		n = find(parent, edges[i].beigin);
		m = find(parent, edges[i].end);

		// 如果不在同一集合，说明不会成环，可以加入生成树
		if (n != m)
		{
			parent[n] = m; // 合并集合
			printf("(%c, %c) %d\n", G.vertex[edges[i].beigin], G.vertex[edges[i].end], edges[i].weight);
		}
	}
}

// 主函数
int main(int argc, char const *argv[])
{
	Mat_Grph G;
	create_graph(&G); // 创建图
	Kruskal(G);       // 执行 Kruskal 算法
	return 0;
}
