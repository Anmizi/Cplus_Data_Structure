#include <stdio.h>
Position Find(Elementtype X,BinTree BST){
	if(!BST) return NULL;
	if(x>BST->Data)
		return Find(X,BST->Right);//右子树中继续查找 
	else if(X<BST->Data)
		return Find(X,BST->Left);//左子树中继续查找 
	else
		return BST;//查找成功 
}
//由于非递归函数的执行效率高，可将尾递归函数改为迭代函数
//查找效率取决于树的高度 
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
//查找最大和最小元素
//最大元素一定在树的最右分支的端节点上
//最小元素一定在树的最左分支的端节点上
Position FindMin(BinTree BST){
	if(!BST){
		return NULL;//空的二叉搜索树，返回NULL 
	}else if(!BST->Left){
		return BST;
	}else{
		return FindMin(BST->Left);//沿左分支继续查找 
	}
} 
Position FindMax(BinTree BST){
	if(BST){
		while(BST->Right) BST=BST->Right;
		//沿右分支查找，直到最右叶节点 
	}
	return BST;
} 
//插入操作
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
