#include <stdio.h>
//дһ����������쳲��������еĵ�n��

//��һҪ�أ����׺���Ҫ��ʲô 
long long Fibonacci(unsigned int n){
	//�ڶ�Ҫ�أ�Ѱ�ҵݹ��������
	if(n<2){
		return n==0?0:1;
	} 
	//����Ҫ�أ��ҳ������ĵȼ۹�ϵʽ 
	return Fibonacci(n-1) + Fibonacci(n-2);
} 
//������ʽʵ��
long long Fibonacci1(unsigned int n){
	int result[2] = {0,1};
	if(n<2) return result[n];
	long long fibNumOne = 1;
	long long fibNumTwo = 0;
	long long fibN = 0;
	int i=2;
	for(i;i<=n;i++){
		fibN = fibNumOne + fibNumTwo;
		fibNumTwo = fibNumOne;
		fibNumOne = fibN;
	}
	return fibN;
} 
int main(){
//	����
	printf("%lld\n",Fibonacci(8));
	printf("%lld\n",Fibonacci1(8));
	
	return 0;
}
