#include <stdio.h>
#include <stdlib.h>
// 顶点和边的数据类型定义
typedef int VertextType;
typedef int EdgeType;
#define MAXSIZE 100           // 顶点和辅助数组最大容量
#define MAX 0x7fffffff        // 表示不可达的极大值

// 邻接矩阵图结构体
typedef struct
{
	VertextType vertex[MAXSIZE];         // 顶点数组
	EdgeType arc[MAXSIZE][MAXSIZE];      // 邻接矩阵
	int vertex_num;                      // 顶点数
	int edge_num;                        // 边数
}Mat_Graph;

// 邻接表边结点结构体
typedef struct EdgeNode
{
	int edge_vex;                        // 邻接点下标
	int weight;                          // 边权值（活动持续时间）
	struct EdgeNode* next;               // 指向下一条边
}EdgeNode;

// 邻接表顶点结构体
typedef struct VertextNode
{
	int in;                              // 入度
	VertextType data;                    // 顶点信息
	EdgeNode* head;                      // 指向第一条边
}VertextNode;

typedef VertextNode Adj_List[MAXSIZE];

// 邻接表图结构体
typedef struct
{
	Adj_List adj_list;
	int vertex_num;
	int edge_num;
}Adj_Graph;

typedef Adj_Graph* Adj_List_Graph;

// 创建邻接矩阵图
void create_graph(Mat_Graph* G)
{
	G->vertex_num = 10;         // 顶点数
	G->edge_num = 13;           // 边数

	for (int i = 0; i < G->vertex_num; i++)
	{
		G->vertex[i] = i;       // 顶点编号即下标
	}

	for (int i = 0; i < G->vertex_num; i++)
	{
		for (int j = 0; j < G->vertex_num; j++)
		{
			if (i == j)
			{
				G->arc[i][j] = 0;      // 自己到自己为0
			}
			else
			{
				G->arc[i][j] = MAX;    // 其他初始为不可达
			}
		}
	}

	// 手动输入所有有向边及权值
	G->arc[0][1] = 3;G->arc[0][2] = 4;
	G->arc[1][3] = 5;G->arc[1][4] = 6;
	G->arc[2][3] = 8;G->arc[2][5] = 7;
	G->arc[3][4] = 3;
	G->arc[4][6] = 9;G->arc[4][7] = 4;
	G->arc[5][7] = 6;
	G->arc[6][9] = 2;
	G->arc[7][8] = 5;
	G->arc[8][9] = 3;
}

// 将邻接矩阵转为邻接表，同时统计每个顶点的入度
void create_adj_graph(Mat_Graph G, Adj_List_Graph* ALG)
{
	EdgeNode* e;

	*ALG = (Adj_List_Graph)malloc(sizeof(Adj_Graph));
	(*ALG)->vertex_num = G.vertex_num;
	(*ALG)->edge_num = G.edge_num;
	// 初始化邻接表顶点
	for (int i = 0; i < G.vertex_num; i++)
	{
		(*ALG)->adj_list[i].in = 0;             // 入度为0
		(*ALG)->adj_list[i].data = G.vertex[i]; // 顶点信息
		(*ALG)->adj_list[i].head = NULL;        // 边链表为空
	}
	// 扫描邻接矩阵，把所有边加入邻接表，并累加终点入度
	for (int i = 0; i < G.vertex_num; i++)
	{
		for (int j = 0; j < G.vertex_num; j++)
		{
			if (G.arc[i][j] != 0 && G.arc[i][j] < MAX)
			{
				e = (EdgeNode*)malloc(sizeof(EdgeNode));
				e->edge_vex = j;
				e->weight = G.arc[i][j];
				e->next = (*ALG)->adj_list[i].head;
				(*ALG)->adj_list[i].head = e;
				(*ALG)->adj_list[j].in++;           // 统计入度
			}
		}
	}
}

// 关键路径算法主流程
void critical_path(Adj_List_Graph ALG)
{
	EdgeNode* e;
	int top = -1;                // 辅助栈1栈顶
	int top2 = -1;               // 辅助栈2栈顶
	int stack[MAXSIZE];          // 辅助栈1：拓扑序
	int stack2[MAXSIZE];         // 辅助栈2：逆拓扑序
	int etv[MAXSIZE];            // 每个事件最早发生时间
	int ltv[MAXSIZE];            // 每个事件最迟发生时间
	int curr;
	int k;

	// 1. 将所有入度为0的顶点入栈
	for (int i = 0; i < ALG->vertex_num; i++)
	{
		if (ALG->adj_list[i].in == 0)
		{
			top++;
			stack[top] = i;
		}
	}

	// 2. 初始化所有etv为0
	for (int i = 0; i < ALG->vertex_num; i++)
	{
		etv[i] = 0;
	}

	// 3. 正向拓扑序遍历，计算所有etv（事件最早发生时间）
	while(top != -1)
	{
		curr = stack[top];
		top--;
		printf("V%d -> ", ALG->adj_list[curr].data); // 拓扑序输出

		top2++;
		stack2[top2] = curr;    // 拓扑序顺序存入stack2，逆序用于ltv计算

		e = ALG->adj_list[curr].head;
		while(e != NULL)
		{
			k = e->edge_vex;
			ALG->adj_list[k].in--;
			if (ALG->adj_list[k].in == 0)
			{
				top++;
				stack[top] = k;
			}
			// etv[k]取所有前驱etv+权值中的最大值
			if (etv[curr] + e->weight > etv[k])
			{
				etv[k] = etv[curr] + e->weight;
			}
			e = e->next;
		}
	}
	printf("End\n");

	// 4. 输出所有顶点的etv
	printf("etv: ");
	for (int i = 0; i < ALG->vertex_num; i++)
	{
		printf("%d -> ", etv[i]);
	}
	printf("End\n");

	// 5. 初始化所有ltv为项目工期（终点etv值）
	for (int i = 0; i < ALG->vertex_num; i++)
	{
		ltv[i] = etv[ALG->vertex_num - 1];
	}

	// 6. 逆拓扑序遍历，计算所有ltv（事件最迟发生时间）
	while(top2 != -1)
	{
		curr = stack2[top2];
		top2--;

		e = ALG->adj_list[curr].head;
		while(e != NULL)
		{
			k = e->edge_vex;
			// ltv[curr]取所有后继ltv-权值中的最小值
			if (ltv[k] - e->weight < ltv[curr])
			{
				ltv[curr] = ltv[k] - e->weight;
			}
			e = e->next;
		}
	}

	// 7. 输出所有顶点的ltv
	printf("ltv: ");
	for (int i = 0; i < ALG->vertex_num; i++)
	{
		printf("%d -> ", ltv[i]);
	}
	printf("End\n");

	// 8. 输出关键路径上的顶点（etv==ltv）
	for (int i = 0; i < ALG->vertex_num; ++i)
	{
		if (etv[i] == ltv[i])
		{
			printf("V%d -> ", i);
		}
	}
}

int main(int argc, char const *argv[])
{
	Mat_Graph G;
	Adj_List_Graph ALG;
	create_graph(&G);              // 构造邻接矩阵
	create_adj_graph(G, &ALG);     // 转为邻接表
	critical_path(ALG);            // 计算并输出关键路径
	return 0;
}