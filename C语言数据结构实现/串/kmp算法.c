/*********************************************************************
    程序名: KMP算法和next数组及next数组改进
    版权:
    作者: Anmizi
    日期: 2020-12-18 15:47
    说明: 字符串非0索引位置存储长度
*********************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int KMP_index(char *, char *);

int *Get_next(char *t);	//next数组
int *Get_nextval(char *t);	//改进next数组
int main() {
	char ss[100];
	char tt[100];
	printf("请输入主串:\n");
	gets(ss);
	printf("请输入模式串:\n");
	gets(tt);
	printf("输出匹配位置(不匹配输入出-1)\n");
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