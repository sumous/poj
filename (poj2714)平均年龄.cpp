/*平均问题*/
#include<stdio.h>
int main()
{
	int data , sum = 0 , i = 0;
	char ch;
	while(1){
		scanf( "%d" , &data);
		sum += data;
		i ++;
		ch = getchar();
		if(ch == '\n') break;
	}
	printf( "%.2f" , (float)sum/i  );
	return 0;
} 