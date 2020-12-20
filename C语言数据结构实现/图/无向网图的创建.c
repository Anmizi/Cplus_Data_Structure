#include <stdio.h>
#include <queue.h>
typedef char VertexType; //��������
typedef int EdgeType;	//Ȩֵ����
typedef int Boolean;
#define MAXVEX 100		//��󶥵���
#define INFINITY 65535  //��65535��������
#define true 1
#define false 0
#define MAX 100

Boolean visited[MAX];	//���ʱ�־������
typedef struct {
	VertexType vexs[MAXVEX]; //�����
	EdgeType arc[MAXVEX][MAXVEX];//�ڽӾ���
	int numVertexes, numEdges; 	//ͼ�е�ǰ�Ķ������ͱ���
} MGraph;

//����������ͼ���ڽӾ����ʾ
void CreateMGraph(MGraph *G) {
	int i, j, k, w;
	printf("���붥�����ͱ�����\n");
	scanf("%d %d", &G->numVertexes, &G->numEdges);
	for (int i = 0; i < G->numVertexes; i++) {
		scanf("%c", &G->vexs[i]);	//���붥����Ϣ
	}
	for (int i = 0; i < G->numVertexes; i++) {
		for (int j = 0; j < G->numVertexes; j++) {
			G->arc[i][j] = INFINITY; //�ڽӾ����ʼ��
		}
	}
	for (int k = 0; k < G->numEdges; k++) {
		printf("�����(vi,vj)�ϵ��±�i,�±�j��Ȩw:\n");
		scanf("%d %d %d", &i, &j, &w);
		G->arc[i][j] = G->arc[j][i] = w;
	}
}

//�ڽӾ����������ȵݹ��㷨
void DFS(MGraph *G, int i) {
	visited[i] = true;
	printf("%c", G->vexs[i]); //��ӡ����
	for (int j = 0; j < G->numVertexes; j++) {
		if (G->arc[i][j] == 1 && !visited[j]) {
			DFS(G, j);
		}
	}
}

//�ڽӾ������ȱ�������
void DFSTraverse(MGraph *G) {
	for (int i = 0; i < G->numVertexes; i++) {
		visited[i] = false;		//��ʼ�����ж���
	}
	for (int i = 0; i < G->numVertexes; i++) {
		if (!visited[i]) {
			DFS(G, i);		//��Ϊ���ʹ��Ķ������DFS
		}
	}
}

//��׾���Ĺ�ȱ����㷨
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
				DeQueue(&Q, &i);		//������Ԫ�س����У���ֵ��i
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
