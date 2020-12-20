#include <stdio.h>
#include <queue.h>
typedef char VertexType; //顶点类型
typedef int EdgeType;	//权值类型
typedef int Boolean;
#define MAXVEX 100		//最大顶点数
#define INFINITY 65535  //用65535代替无穷
#define true 1
#define false 0
#define MAX 100

Boolean visited[MAX];	//访问标志的数组
typedef struct {
	VertexType vexs[MAXVEX]; //顶点表
	EdgeType arc[MAXVEX][MAXVEX];//邻接矩阵
	int numVertexes, numEdges; 	//图中当前的顶点数和边数
} MGraph;

//建立无向网图的邻接矩阵表示
void CreateMGraph(MGraph *G) {
	int i, j, k, w;
	printf("输入顶点数和边数：\n");
	scanf("%d %d", &G->numVertexes, &G->numEdges);
	for (int i = 0; i < G->numVertexes; i++) {
		scanf("%c", &G->vexs[i]);	//读入顶点信息
	}
	for (int i = 0; i < G->numVertexes; i++) {
		for (int j = 0; j < G->numVertexes; j++) {
			G->arc[i][j] = INFINITY; //邻接矩阵初始化
		}
	}
	for (int k = 0; k < G->numEdges; k++) {
		printf("输入边(vi,vj)上的下标i,下标j和权w:\n");
		scanf("%d %d %d", &i, &j, &w);
		G->arc[i][j] = G->arc[j][i] = w;
	}
}

//邻接矩阵的深度优先递归算法
void DFS(MGraph *G, int i) {
	visited[i] = true;
	printf("%c", G->vexs[i]); //打印顶点
	for (int j = 0; j < G->numVertexes; j++) {
		if (G->arc[i][j] == 1 && !visited[j]) {
			DFS(G, j);
		}
	}
}

//邻接矩阵的深度遍历操作
void DFSTraverse(MGraph *G) {
	for (int i = 0; i < G->numVertexes; i++) {
		visited[i] = false;		//初始化所有顶点
	}
	for (int i = 0; i < G->numVertexes; i++) {
		if (!visited[i]) {
			DFS(G, i);		//对为访问过的顶点调用DFS
		}
	}
}

//零阶矩阵的广度遍历算法
void BFSTraverse(MGraph *G) {
	Queue Q;
	for (int i = 0; i < G->numVertexes; i++) {
		visited[i] = false;
	}
	InitQueue(&Q);
	for (int i = 0; i < G->numVertexes; i++) {
		if (!visited[i]) {
			visited[i] = true;
			printf("%c", G->vexs[i]);
			EnQueue(&Q, i);
			while (!QueueEmpty(Q)) {
				DeQueue(&Q, &i);		//将队中元素出队列，赋值给i
				for (int j = 0; j < G->numVertexes; j++) {
					if (G->arc[i][j] == 1 && !visited[j]) {
						visited[j] = true;
						printf("%c", G->vexs[j]);
						EnQueue(&Q, j);
					}
				}
			}
		}
	}
}

int main(void) {


	return 0;
}
