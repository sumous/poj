#include<stdio.h>
int main()
{
	int a[6], N , i , test[4]={0,5,3,1} , x ,y;
	/*x用于存储2*2的空位数目，y用于存储1*1的空位数目*/
	while(1){
		for(i = 0;i < 6;i ++) scanf( "%d" , &a[i]);
		/*判断退出条件*/
		if(a[0] == 0&&a[1] == 0&&a[2] == 0&&a[3] == 0&&a[4] == 0&&a[5] == 0)  break;
		N = a[5] + a[4] + a[3] + (a[2] + 3) / 4; 
		x = a[3] * 5 + test[a[2] % 4];
		if(a[1] > x) N += (a[1] - x + 8) / 9 ;
		y = N * 36 - a[5] * 36 - a[4] * 25 - a[3] * 16 - a[2] * 9 - a[1] * 4;
		if(a[0] > y) N += (a[0] - y +35) / 36;
		printf( "%d\n" , N );
	}
}