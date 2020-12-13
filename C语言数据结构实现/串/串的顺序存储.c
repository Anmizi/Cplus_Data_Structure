#include <stdio.h>
#include <string.h>

#define MAXLEN 255
typedef int bool;
#define true 1
#define false 0
typedef struct {
	char ch[MAXLEN];//静态数组(定长)实现
	int length;
} SString;

/*
//数组0位不存字符
typedef struct {
	char *ch;	//按串长分配存储区，ch指向串长的基地址
	int length;
} HString;		//动态数组实现(对分配存储)
*/

//串的初始化
SString InitStr(SString S, char str[]) {
	S.length = strlen(str);
	for (int i = 1; i <= S.length; i++) {
		S.ch[i] = str[i - 1];
	}
	return S;
}

//求串长
int StrLength(SString S) {
	return S.length;
}

//求子串
bool SubString(SString *Sub, SString S, int pos, int len) {
	if (pos + len - 1 > S.length)
		return false;
	for (int i = pos; i < pos + len; i++) {
		Sub->ch[i - pos + 1] = S.ch[i];
	}
	Sub->length = len;
	return true;
}

//比较操作
int StrCompare(SString S, SString T) {
	for (int i = 1; i <= S.length && i <= T.length; i++) {
		if (S.ch[i] != T.ch[i])
			return S.ch[i] - T.ch[i];
	}
	return S.length - T.length;
}

//定位操作
int Index(SString S, SString T) {
	int i = 1, n = StrLength(S), m = StrLength(T);
	SString sub;
	while (i < n - m + 1) {
		SubString(&sub, S, i, m);
		if (StrCompare(sub, T) != 0)
			++i;
		else
			return i;
	}
	return 0;
}

//打印串
void PrintStr(SString S) {
	for (int i = 1; i <= S.length; i++) {
		printf("%c", S.ch[i]);
	}
	printf("\n");
}

int main() {
	char str[] = "hello,world";
	printf("%d", strlen(str));
	SString ss;
	ss = InitStr(ss, str);
	PrintStr(ss);
	SString ss1;
	SubString(&ss1, ss, 3, 6);
	PrintStr(ss1);
	SString ss2;
	ss2 = InitStr(ss2, "wor");
	int ret = Index(ss, ss2);
	printf("%d", ret);
	return 0;
}
