#include <stdio.h>
typedef char VertexType;
typedef int EdgeType;
#define MAXSIZE 100

// 定义邻接矩阵图结构体
typedef struct
{
	VertexType vertex[MAXSIZE];      // 顶点数组
	EdgeType arc[MAXSIZE][MAXSIZE];  // 邻接矩阵，存储边关系
	int vertex_num;                  // 顶点数量
	int edge_num;                    // 边数量
}Mat_Grph;

int visited[MAXSIZE];               // 记录顶点是否被访问过
int front = 0;                      // 队首指针
int rear = 0;                       // 队尾指针
int queue[MAXSIZE];                // 简易模拟队列的数组

// 创建图（邻接矩阵形式）
void create_graph(Mat_Grph* G)
{
	G->vertex_num = 9;
	G->edge_num = 15;
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

	// 初始化邻接矩阵为 0
	for (int i = 0; i < G->vertex_num; i++)
	{
		for (int j = 0; j < G->vertex_num; j++)
		{
			G->arc[i][j] = 0;
		}
	}

	// 添加边（无向图，因此后续还会对称赋值）
	G->arc[0][1] = 1;
	G->arc[0][5] = 1;
	G->arc[1][2] = 1;
	G->arc[1][6] = 1;
	G->arc[1][8] = 1;
	G->arc[2][3] = 1;
	G->arc[2][8] = 1;
	G->arc[3][4] = 1;
	G->arc[3][6] = 1;
	G->arc[3][7] = 1;
	G->arc[3][8] = 1;
	G->arc[4][5] = 1;
	G->arc[4][7] = 1;
	G->arc[5][6] = 1;
	G->arc[6][7] = 1;

	// 对称复制，构造无向图
	for (int i = 0; i < G->vertex_num; i++)
	{
		for (int j = 0; j < G->vertex_num; j++)
		{
			G->arc[j][i] = G->arc[i][j];
		}
	}
}

// 广度优先遍历函数
void bfs(Mat_Grph G)
{
	int i = 0;                   // 从顶点 A（下标0）开始
	visited[i] = 1;              // 标记 A 已访问
	printf("%c\n", G.vertex[i]); // 输出顶点 A
	queue[rear] = i;             // A 入队
	rear++;

	// 队列不空则继续处理
	while(front != rear)
	{
		i = queue[front];        // 出队一个元素
		front++;

		// 遍历该顶点的所有邻接点
		for (int j = 0; j < G.vertex_num; j++)
		{
			if (G.arc[i][j] == 1 && visited[j] == 0)
			{
				visited[j] = 1;              // 标记为已访问
				printf("%c\n", G.vertex[j]); // 输出该邻接点
				queue[rear] = j;             // 邻接点入队
				rear++;
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	Mat_Grph G;
	create_graph(&G);  // 构造图
	// 初始化访问标记数组
	for (int i = 0; i < G.vertex_num; i++)
	{
		visited[i] = 0;
	}
	bfs(G);  // 执行广度优先遍历
	return 0;
}
