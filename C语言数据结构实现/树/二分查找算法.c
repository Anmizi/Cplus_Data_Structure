#include <stdio.h> 
int BinarySearch(StaticTable *Tbl,ElementType K){
	//�ڱ�tbl�в��ҹؼ���Ϊk������Ԫ�� 
	int left,right,mid,NoFound = -1;
	left = 1;//��ʼ��߽� 
	right = Tbl->Length;//��ʼ�ұ߽�
	while(left<=right){
		mid=(left+right)/2;//�����м�Ԫ������ 
		if(K<Tbl->Element[mid]) right = mid-1;//������߽� 
		else if(K>Tbl->Element[mid]) left = mid+1;//�����ұ߽� 
		else return mid;//���ҳɹ����������� 
	} 
	return NotFound;//����ʧ�ܣ����ش����־ 
}
int main(){
	//���㷨��Ϊ˼·�������и��Ĵ�����в��� 
	return 0;
}
