/*Êý×ÖÇóºÍ*/
#include<stdio.h>
int main()
{
	int n ,a[6] , i;
	scanf( "%d" , &n);
	for( i = 0;i < 5; i ++ ) scanf( "%d" , &a[i] );
	for( i = 0;i < 5;i ++ ){
 		if(a[i] < n) printf( "%d\n" , a[i]);
	} 
	return 0;
} 