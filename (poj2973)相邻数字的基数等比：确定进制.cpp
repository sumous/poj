#include<stdio.h>
#define max 100
int Change10(int x , int bit)//将bit进制下的x转换位十进制数 
{
	int i = 1 , x10 = 0;
	while(x != 0)	{
		if(x % 10 >= bit) return -1;
		x10 += x % 10 * i;
		x /= 10;
		i *= bit;
	}
	return x10;
}
int FindBit(int p , int q , int r )//寻找满足的进制 
{
	int p10 = 0 , q10 = 0 , r10 = 0 , i;
	for (i = 2;i <= 16;i ++ ){
		p10 = Change10(p , i);
		q10 = Change10(q , i);
		r10 = Change10(r , i);
		if( p10 == -1 || q10 == -1 || r10 == -1) continue;
		if(q10 * p10 == r10) return i;
	}
	return 0;
}
main()
{
	int T , p , q , r , i , a[max];
	scanf( "%d" , &T);
	for( i = 0;i < T;i ++){
		scanf( "%d%d%d" , &p , &q , &r );
		a[i] = FindBit(p , q , r); 
	}
	for( i = 0;i < T;i ++){
		printf( "%d\n" , a[i] );
	}
}