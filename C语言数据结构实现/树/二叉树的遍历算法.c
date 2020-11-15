#include <stdio.h>
//中序遍历
void Inorder(BinTree BT){
	if(BT){
		Inorder(BT->Left);
		printf("%d ",BT->Data);
		Inorder(BT->Right);
	}
} 
//前序遍历
void Preorder(BinTree BT){
	if(BT){
		printf("%d ",BT->Data);
		Preorder(BT->Left);
		Preorder(BT->Right);
	}
} 
//后序遍历
void Postorder(BinTree BT){
	if(BT){
		Postorder(BT->Left);
		Postorder(BT->Right);
		printf("%d ",BT->Data);
	}
} 
//层次遍历
void Levelorder(BinTree BT){
	Quene Q;
	BinTree T;
	if(!BT) return ;
	Q = CreateQuene();
	AddQ(Q,BT);
	while(!IsEmpty(Q)){
		T = DeleteQ(Q);
		printf("%d ",T->Data);
		if(T->Left) AddQ(Q,T->Left);
		if(T->Right) AddQ(Q,T->Right);
	}
}
int main(){
//  改代码不可直接编译运行 
//	请自行修改代码进行测试 
	return 0;
} 
