/*********************************************************************
    ������: ͳ��ģʽ���������г��ֵĸ���
    ��Ȩ:
    ����: Anmizi
    ����: 2020-12-16 17:17
    ˵��:
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
	cout << "����������:" << endl;
	gets(s);
	cout << "������ģʽ��(�Ӵ�):" << endl;
	gets(t);
	cout << "ͳ���Ӵ����������ֵĸ���Ϊ:" << endl;
	cout << Count(s, t) << endl;
	return 0;
}