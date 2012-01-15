#include<stdio.h>
#include<string.h>
#define max 35
int main()
{
	char a[max];
	int i ;
	long result = 0 , pow = 2;
	scanf( "%s" , a );
	while(a[0] != '0'){//当输入的不为0时，执行以下程序 
		for ( i = strlen(a) - 1; i >= 0 ; i -- ){
			 result += (pow - 1) * (a[i] - '0');
			 pow *= 2;
		}
		printf( "%ld\n" , result );
		pow = 2;
		scanf( "%s" , a );
		result = 0;
	}
	return 0;
}