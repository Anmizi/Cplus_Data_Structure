#include <iostream>
#include <cstring>
using namespace std;
//������ 
void StrCat(char *s1,char *s2){
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	if(len1 + len2 > MaxSize - 1){
		cerr<<"����"<<endl;exit(1); 
	}
	int i=0;
	while(s2[i]!='\0'){
		s1[i+len1] = s2[i];
		i++;
	}
	s1[1+len1] = '\0';
} 

//���Ƚ�
int StrCmp(char *s1,char *s2){
	int i=0;
	while(s1[i]==s2[i]&&s1[i]!='\0'){
		i++;
	}
	return (s1[i]-s2[i]);
} 
//������
void StrCpy(char *s1,char *s2){
	int len = strlen(s2);
	if(len>MaxSize - 1){
		cerr<<"����"<<;exit(1);
	}
	while(*s1++ = *s2++);
} 
//ģʽƥ��BF�㷨
int BFmatching(char *s,char *t){
	int i=0;
	int j=0;
	int n = strlen(s);
	int m = strlen(t);
	while(i<n&&j<m){
		if(s[i] == t[j]){
			i++;
			j++;
		}else{
			i = i-j+1;
			j=0;
		}
	}
	if(j>=m){
		return i-j;
	}else{
		return -1;
	}
} 
//���������� 
int main(){
	return 0;
}

