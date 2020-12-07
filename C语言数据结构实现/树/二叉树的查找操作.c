#include <stdio.h>
Position Find(Elementtype X,BinTree BST){
	if(!BST) return NULL;
	if(x>BST->Data)
		return Find(X,BST->Right);//�������м������� 
	else if(X<BST->Data)
		return Find(X,BST->Left);//�������м������� 
	else
		return BST;//���ҳɹ� 
}
//���ڷǵݹ麯����ִ��Ч�ʸߣ��ɽ�β�ݹ麯����Ϊ��������
//����Ч��ȡ�������ĸ߶� 
Position InterFind(ElementType X,BinTree BST){
	while(BST){
		if(X>BST->Data){
			BST = BST->Right;
		}else if(X<BST->Data){
			BST = BST->Left;
		}else{
			return BST;
		}
	}
	return NULL;
} 
//����������СԪ��
//���Ԫ��һ�����������ҷ�֧�Ķ˽ڵ���
//��СԪ��һ�������������֧�Ķ˽ڵ���
Position FindMin(BinTree BST){
	if(!BST){
		return NULL;//�յĶ���������������NULL 
	}else if(!BST->Left){
		return BST;
	}else{
		return FindMin(BST->Left);//�����֧�������� 
	}
} 
Position FindMax(BinTree BST){
	if(BST){
		while(BST->Right) BST=BST->Right;
		//���ҷ�֧���ң�ֱ������Ҷ�ڵ� 
	}
	return BST;
} 
//�������
BinTree Insert(Element X,BinTree BST){
	if(!BST){
		BST = malloc(sizeof(struct TreeNode));
		BST->Data = X;
		BST->Left = BST->Right = NULL;
	}else 
		if(X<BST->Data)
			BST->Left = Insert(X,BST->Left);
		else if(X>BST->Data){
			BST->Right = Insert(X,BST->Right);
		}
	return BST;
} 
int main(){
	return 0;
} 
