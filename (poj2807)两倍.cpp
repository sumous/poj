/*Á½±¶*/
#include<stdio.h>
int main()
{
	int a[16] , n = 0 , j ,count = 0 , i;
	char ch = getchar(); 
	while(ch != '\n'){
		scanf( "%d" , &a[n] );
		n ++;
		ch = getchar();
	}
	for( i = 0;i < n;i ++){
		for( j = i;j < n;j ++ ){
			if(a[i] % (a[j] * 2) == 0||a[j] % (a[i] * 2) == 0){
				count ++;
				break;
			}
		}
	}
	printf( "%d" , count );
	return 0;
} 