/*����ͬ��*/
#include<stdio.h>
int main()
{
	int n , a[100] , i;
	scanf( "%d" , &n );
	for( i = 0;i < n;i ++){//�������� 
		scanf( "%d" , &a[i]  );
	}
	for( i = 0;i < n;i ++){
		if(a[i]%2 == 1)//�����������򲻴��� 
	    	printf("0 0\n");
		else 
		/*�������˸�����*/ 
			printf("%d %d\n" , (a[i] + 3)/4 , a[i]/2);
	}
	return 0;
}