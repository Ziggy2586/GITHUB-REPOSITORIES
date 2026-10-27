#include <stdio.h>
#include <stdlib.h>
typedef char VertexType;   // 顶点的数据类型，使用字符表示，如 'A', 'B', 'C'
typedef int EdgeType;      // 边的权值类型
#define MAXSIZE 100        // 最大顶点数
#define MAX 0x7fffffff     // 表示无穷大，表示顶点之间没有直接连接

// 邻接矩阵表示的图结构
typedef struct
{
	VertexType vertex[MAXSIZE];         // 存储顶点信息
	EdgeType arc[MAXSIZE][MAXSIZE];     // 邻接矩阵，存储边的权值
	int vertex_num;                     // 顶点数
	int edge_num;                       // 边数
}Mat_Grph;

// 构建一个无向带权图
void create_graph(Mat_Grph* G)
{
	G->vertex_num = 9;    // 9个顶点
	G->edge_num = 15;     // 共15条边
	// 初始化顶点
	G->vertex[0] = 'A';
	G->vertex[1] = 'B';
	G->vertex[2] = 'C';
	G->vertex[3] = 'D';
	G->vertex[4] = 'E';
	G->vertex[5] = 'F';
	G->vertex[6] = 'G';
	G->vertex[7] = 'H';
	G->vertex[8] = 'I';

	// 初始化邻接矩阵
	for (int i = 0; i < G->vertex_num; i++)
	{
		for (int j = 0; j < G->vertex_num; j++)
		{
			if (i == j)
				G->arc[i][j] = 0;     // 自己到自己距离为0
			else
				G->arc[i][j] = MAX;   // 先设为无穷大，表示无连接
		}
	}

	// 输入图中各边的权值
	G->arc[0][1] = 10; G->arc[0][5] = 11;
	G->arc[1][2] = 18; G->arc[1][6] = 16; G->arc[1][8] = 12;
	G->arc[2][3] = 22; G->arc[2][8] = 8;
	G->arc[3][4] = 20; G->arc[3][6] = 24; G->arc[3][7] = 16; G->arc[3][8] = 21;
	G->arc[4][5] = 26; G->arc[4][7] = 7;
	G->arc[5][6] = 17;
	G->arc[6][7] = 19;

	// 因为是无向图，所以对称赋值
	for (int i = 0; i < G->vertex_num; i++)
	{
		for (int j = 0; j < G->vertex_num; j++)
		{
			G->arc[j][i] = G->arc[i][j];
		}
	}
}

// Prim 算法核心实现
void prim(Mat_Grph* G)
{
	int i, j, k;
	int min;
	int weight[MAXSIZE];      // 记录当前每个顶点到最小生成树中顶点的最小边权
	int vex_index[MAXSIZE];   // 记录边的起始点，下标是终点

	// 初始化：以顶点 A 为起点（即下标 0）
	weight[0] = 0;        // 表示 A 顶点已经加入最小生成树
	vex_index[0] = 0;     // 起始点自身

	// 初始化 weight 数组：以 A 为起点记录其余各点的最小权值
	for (i = 1; i < G->vertex_num; i++)
	{
		weight[i] = G->arc[0][i];   // A 到 i 的边权
		vex_index[i] = 0;           // 初始都认为是从 A 发出的边
	}

	// 共需要加入 vertex_num - 1 条边
	for (int i = 1; i < G->vertex_num; i++)
	{
		min = MAX;
		k = 0;

		// 在所有未加入树的顶点中，选择最小边权对应的点 k
		for (j = 0; j < G->vertex_num; j++)
		{
			if (weight[j] != 0 && weight[j] < min)
			{
				min = weight[j];
				k = j;
			}
		}

		// 输出当前选择的边
		printf("(%c, %c)\n", G->vertex[vex_index[k]], G->vertex[k]);

		// 标记点 k 已加入最小生成树
		weight[k] = 0;

		// 更新其余未加入点到最小生成树的最小边权
		for (j = 0; j < G->vertex_num; j++)
		{
			// 若存在更短路径，则更新 weight 和 vex_index
			if (weight[j] != 0 && G->arc[k][j] < weight[j])
			{
				weight[j] = G->arc[k][j];
				vex_index[j] = k;
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	Mat_Grph G;
	create_graph(&G);
	prim(&G);  // 执行 Prim 算法，输出最小生成树边
	return 0;
}
