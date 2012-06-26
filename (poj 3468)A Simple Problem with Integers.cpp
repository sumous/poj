/**
	用cout或cin的效率低于scanf和printf
*/
#include <stdio.h>
#define __uint64 long long

struct __int
{
	__uint64 a, b;
	__uint64 sum;//[a, b]区间的总和
	__uint64 add;//[a, b]区间的增量
}tree[400005];
__uint64 N, Q, tlen = 0;
__uint64 node[100005];

void load()
{
	
	scanf("%lld%lld", &N, &Q);
	for (int i = 1; i <= N; i++)
		scanf("%lld", &node[i]);
}
/* 建线段树 */
void create(__uint64 num, __uint64 a, __uint64 b)
{
	tree[num].a = a, tree[num].b = b;
	tree[num].add = 0;
	if (a == b)
	{
		tree[num].sum = node[a];
		return;
	}
	if (a < b)
	{
		__uint64 mid = (a+b)/2;
		create(num*2, a, mid);
		create(num*2+1, mid+1, b);
		
	}
	tree[num].sum = tree[num*2].sum + tree[num*2+1].sum;
}
/* 为[a, b]区间所有数加c */
void update(__uint64 num, __uint64 a, __uint64 b, __uint64 c)
{
	if (tree[num].a == a && tree[num].b == b)
	{
		tree[num].add += c;
		return;
	}
	tree[num].sum += (b - a + 1) * c;
	{
		__uint64 mid = (tree[num].a + tree[num].b)/2;
		if (b <= mid) update(num*2, a, b, c);
		else if (a > mid) update(num*2+1, a, b, c);
		else
		{
			update(num*2, a, mid, c);
			update(num*2+1, mid+1, b, c);
		}
		
	}
}
	
/* 查询[a, b]区间的总和 */
__uint64 query(__uint64 num, __uint64 a, __uint64 b)
{
	if (tree[num].a == a && tree[num].b == b)
	{
		return tree[num].sum + tree[num].add * (b-a+1);
	}
	else
	{
		__uint64 mid = (tree[num].a + tree[num].b)/2;
		if (b <= mid) return query(num*2, a, b) + tree[num].add * (b-a+1);
		else if (a > mid) return query(num*2+1, a, b) + tree[num].add * (b-a+1);
		return query(num*2, a, mid) + query(num*2+1, mid+1, b) + tree[num].add * (b-a+1);
	}
}
void solve()
{
	char ch;
	__uint64 a, b, c;
	for (int i = 0; i < Q; i++)
	{
		getchar();
		scanf("%c", &ch);
		if (ch == 'Q')
		{
			scanf("%lld%lld", &a, &b);
			printf("%lld\n", query(1, a, b) );
		}
		else
		{
			scanf("%lld%lld%lld", &a, &b, &c);
			update(1, a, b, c);
		}
	}
}


int main()
{
	freopen("data", "r", stdin);
	load();
	create(1, 1, N);
	solve();
	return 0;
}
