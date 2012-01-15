#include<stdio.h>
int main()
{
	int L , M , count = 0 , a[10001] = {0} , i , j;
	//for( i = 1;i < 10001;i ++ ) a[i] = 0;
	scanf( "%d%d" ,&L , &M );
	for( i = 0;i < M ;i ++ ){
		int begin , end;
		scanf( "%d%d" , &begin , &end );
		for( j = begin;j <= end;j ++ ){
			a[j] = 1;
		}
	}
	for( i = 1;i <= L;i ++  ){
		if(!a[i]) count ++;
	}
	printf( "%d" , count );
	return 0;
}