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

BinTree CreateBinTree(BinTree bt)//���ɶ�����
{
   char ch;
   ch=getchar();

   if(ch=='#')//����#��ʾ����
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
/* �ж��Ƿ�ͬ�� */
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
    cout<<"************�ж϶�����ͬ������******************\n";
    cout<<"*                                              *\n";
    cout<<"************************************************\n";

	BinTree T1, T2;
	cout<<"�������һ����T1����#��ʾ��ڵ㣩";
	T1 = CreateBinTree(T1);
	getchar();
	cout<<"������ڶ�����T2����#��ʾ��ڵ㣩";
	T2 = CreateBinTree(T2);

	if(is_iso(T1, T2)) cout<<"��ͬ����"<<endl;
	else cout<<"����ͬ����"<<endl;

    return 0;
}
