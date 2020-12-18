/*********************************************************************
    ������: KMP�㷨��next���鼰next����Ľ�
    ��Ȩ:
    ����: Anmizi
    ����: 2020-12-18 15:47
    ˵��: �ַ�����0����λ�ô洢����
*********************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int KMP_index(char *, char *);

int *Get_next(char *t);	//next����
int *Get_nextval(char *t);	//�Ľ�next����
int main() {
	char ss[100];
	char tt[100];
	printf("����������:\n");
	gets(ss);
	printf("������ģʽ��:\n");
	gets(tt);
	printf("���ƥ��λ��(��ƥ�������-1)\n");
	printf("%d\n", KMP_index(ss, tt));
	return 0;
}

int KMP_index(char *s, char *t) {
	int i = 0;
	int j = 0;
	int *next = Get_next(t);
	int m = strlen(s);
	int n = strlen(t);
	while (i < m && j < n) {
		if (j == -1 || s[i] == t[j]) {
			i++;
			j++;
		} else {
			j = next[j];
		}
	}
	if (j >= n) {
		return i - j;
	} else {
		return -1;
	}
}

int *Get_next(char *t) {
	int n = strlen(t);
	int i = 0;
	int j = -1;
	int *next = (int *)malloc(sizeof(int) * n);
	next[0] = -1;
	while (i < n) {
		if (j == -1 || t[i] == t[j]) {
			i++;
			j++;
			next[i] = j;
		} else {
			j = next[j];
		}
	}
	return next;
}

int *Get_nextval(char *t) {
	int n = strlen(t);
	int i = 0;
	int j = -1;
	int *nextval = (int *)malloc(sizeof(int) * n);
	nextval[0] = -1;
	while (i < n) {
		if (j == -1 || t[i] == t[j]) {
			i++;
			j++;
			if (t[i] != t[j]) {
				nextval[i] = j;
			} else {
				nextval[i] = nextval[j];
			}
		} else {
			j = nextval[j];
		}
	}
	return nextval;
}