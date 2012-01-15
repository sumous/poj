/*鸡兔同笼*/
#include<stdio.h>
int main()
{
	int n , a[100] , i;
	scanf( "%d" , &n );
	for( i = 0;i < n;i ++){//输入数据 
		scanf( "%d" , &a[i]  );
	}
	for( i = 0;i < n;i ++){
		if(a[i]%2 == 1)//若是奇数，则不存在 
	    	printf("0 0\n");
		else 
		/*这里用了个技巧*/ 
			printf("%d %d\n" , (a[i] + 3)/4 , a[i]/2);
	}
	return 0;
}