#include <stdio.h>
//写一个函数计算斐波那契数列的第n项

//第一要素：明白函数要干什么 
long long Fibonacci(unsigned int n){
	//第二要素：寻找递归结束条件
	if(n<2){
		return n==0?0:1;
	} 
	//第三要素：找出函数的等价关系式 
	return Fibonacci(n-1) + Fibonacci(n-2);
} 
//迭代方式实现
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
//	测试
	printf("%lld\n",Fibonacci(8));
	printf("%lld\n",Fibonacci1(8));
	
	return 0;
}
