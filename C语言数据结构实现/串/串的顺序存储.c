#include <stdio.h>
#include <string.h>

#define MAXLEN 255
typedef int bool;
#define true 1
#define false 0
typedef struct {
	char ch[MAXLEN];//��̬����(����)ʵ��
	int length;
} SString;

/*
//����0λ�����ַ�
typedef struct {
	char *ch;	//����������洢����chָ�򴮳��Ļ���ַ
	int length;
} HString;		//��̬����ʵ��(�Է���洢)
*/

//���ĳ�ʼ��
SString InitStr(SString S, char str[]) {
	S.length = strlen(str);
	for (int i = 1; i <= S.length; i++) {
		S.ch[i] = str[i - 1];
	}
	return S;
}

//�󴮳�
int StrLength(SString S) {
	return S.length;
}

//���Ӵ�
bool SubString(SString *Sub, SString S, int pos, int len) {
	if (pos + len - 1 > S.length)
		return false;
	for (int i = pos; i < pos + len; i++) {
		Sub->ch[i - pos + 1] = S.ch[i];
	}
	Sub->length = len;
	return true;
}

//�Ƚϲ���
int StrCompare(SString S, SString T) {
	for (int i = 1; i <= S.length && i <= T.length; i++) {
		if (S.ch[i] != T.ch[i])
			return S.ch[i] - T.ch[i];
	}
	return S.length - T.length;
}

//��λ����
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

//��ӡ��
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
