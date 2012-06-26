#include <stdio.h>
#define lowbit(x) (x&(-x))
#define MAX 32005

int res[MAX], com[MAX];
int query(int k)
{
	int sum = 0;
	while (k>0)
	{
		sum += com[k];
		k -= lowbit(k);
	}
	return sum;
}
void update(int k, int val)
{
	while (k < MAX)
	{
		com[k] += val;
		k += lowbit(k);
	}
}
int main()
{
	int x, N, i;
	scanf("%d", &N);
	for (i = 0; i < N; i++)
	{
		scanf("%d%*d", &x);
		x++;
		res[ query(x) ]++;
		update(x, 1);
	}
	
	for (i = 0; i < N; i++)
		printf("%d\n", res[i]);
	return 0;
}
