#include <stdio.h> 
int BinarySearch(StaticTable *Tbl,ElementType K){
	//在表tbl中查找关键字为k的数据元素 
	int left,right,mid,NoFound = -1;
	left = 1;//初始左边界 
	right = Tbl->Length;//初始右边界
	while(left<=right){
		mid=(left+right)/2;//计算中间元素坐标 
		if(K<Tbl->Element[mid]) right = mid-1;//调整左边界 
		else if(K>Tbl->Element[mid]) left = mid+1;//调整右边界 
		else return mid;//查找成功，返回坐标 
	} 
	return NotFound;//查找失败，返回错误标志 
}
int main(){
	//该算法仅为思路，可自行更改代码进行测试 
	return 0;
}
