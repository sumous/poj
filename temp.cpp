#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

typedef struct node
{
	char data;
	struct node *lchild,*rchild;
}BinTNode;
typedef BinTNode *BinTree;

BinTree CreateBinTree(BinTree bt)//生成二叉树
{
   char ch;
   ch=getchar();

   if(ch=='#')//假设#表示虚结点
        bt=NULL;
   else
   	{
     if(!(bt=(BinTNode *)malloc(sizeof(BinTNode))))
         printf("Error!");
     bt->data=ch;
     bt->lchild=CreateBinTree(bt->lchild);
     bt->rchild=CreateBinTree(bt->rchild);
    }
     return bt;
}
/* 判断是否同构 */
bool is_iso(BinTree T1, BinTree T2)
{
    if(T1 != NULL && T2 != NULL)
    {
        if(T1->data == T2->data)
        {
            if(is_iso(T1->lchild, T2->rchild) && is_iso(T1->rchild, T2->lchild))
                return true;
            else return false;
        }
        else return false;
    }
    else return false;
}
int main()
{
    cout<<"************************************************\n";
    cout<<"*                                              *\n";
    cout<<"************判断二叉树同构程序******************\n";
    cout<<"*                                              *\n";
    cout<<"************************************************\n";

	BinTree T1, T2;
	cout<<"请输入第一棵树T1：（#表示虚节点）";
	T1 = CreateBinTree(T1);
	getchar();
	cout<<"请输入第二棵树T2：（#表示虚节点）";
	T2 = CreateBinTree(T2);

	if(is_iso(T1, T2)) cout<<"是同构！"<<endl;
	else cout<<"不是同构！"<<endl;

    return 0;
}
