#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;
int L, T, O;

struct Tree
{
	int l, r;
	int c, cover;
}tree[500000];
void build(int l, int r, int k)
{
	tree[k].l = l, tree[k].r = r;
	tree[k].c = 1, tree[k].cover = 1;
	if (l != r)
	{
		int mid = (l + r) >> 1;
		build(l, mid, 2*k);
		build(mid+1, r, 2*k+1);
	}
}

void update(int l, int r, int c, int k)
{
	if (tree[k].l == l && tree[k].r == r)
	{
		tree[k].c = (1<<c), tree[k].cover = 1;
	}
	else
	{
		if (tree[k].cover == 1)
		{
			tree[2*k].c = tree[2*k+1].c = tree[k].c;
			tree[2*k].cover = tree[2*k+1].cover = 1;
			tree[k].cover = 0;
		}
		
		
		int mid = (tree[k].l + tree[k].r) >> 1;
		if (mid >= r) update(l, r, c, 2*k);
		else if (mid < l) update(l, r, c, 2*k+1);
		else
		{
			update(l, mid, c, 2*k);
			update(mid+1, r, c, 2*k+1); 
			
		}
		tree[k].c = (tree[2*k].c | tree[2*k+1].c);
		
	}
}

int query(int l, int r, int k)
{
	if (tree[k].cover == 1) return tree[k].c;

	int mid = (tree[k].l + tree[k].r) >> 1;
	if (mid >= r)  return query(l, r, 2*k);
	else if (mid < l) return query(l, r, 2*k+1);
	else
	{
		return ( query(l, mid, 2*k) | query(mid+1, r, 2*k+1) );
	}

}

void sort_AB(int& A, int& B)
{
	if (A > B)
	{
		int tmp = A;
		A = B;
		B = tmp;
	}
}
int cal1(int n)
{
	int ans = 0;
	for ( ;n; n -= n&-n) ans ++;
	return ans;
}

int main()
{
	freopen("data.txt","r",stdin);
	scanf("%d %d %d", &L, &T, &O);
	build(1, L, 1);
	for (int i = 0; i < O; i++)
	{
		char ch;
		int A, B, C;
		getchar();
		scanf("%c %d %d", &ch, &A, &B);
		if (ch == 'C')
		{
			scanf("%d", &C);
			sort_AB(A, B);
			update(A, B, C, 1);
		}
		else
		{

			sort_AB(A, B);
			cout << cal1( query(A, B, 1) ) << endl;
		}
			
	}
	return 0;
}
