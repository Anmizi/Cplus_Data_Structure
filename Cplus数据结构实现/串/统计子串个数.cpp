/*********************************************************************
    程序名: 统计模式串在主串中出现的个数
    版权:
    作者: Anmizi
    日期: 2020-12-16 17:17
    说明:
*********************************************************************/
#include <iostream>
#include <cstring>
using namespace std;

int Count(char *s, char *t) {
	int i = 0;
	int j = 0;
	int count = 0;
	int m = strlen(s);
	int n = strlen(t);
	while (i < m) {
		if (s[i] == t[j]) {
			i++;
			j++;
		} else {
			i = i - j + 1;
			j = 0;
		}
		if (j == n) {
			count++;
			i = i - j + 1;
			j = 0;
		}
	}
	return count;
}

int main() {
	char s[100];
	char t[100];
	cout << "请输入主串:" << endl;
	gets(s);
	cout << "请输入模式串(子串):" << endl;
	gets(t);
	cout << "统计子串在主串出现的个数为:" << endl;
	cout << Count(s, t) << endl;
	return 0;
}