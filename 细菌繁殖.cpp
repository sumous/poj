/*ϸ����ֳ*/
#include<stdio.h>
/*date[]����ȷ��ÿ���µ�����*/
int date[] = {0,31,28,31,30,31,30,31,31,30,31,30,31,30};
int exp_via_repeated_squaring(int a,int day)
{
	int	result = a,x = 2 ;	
	while(day>0)
	{
		if(day%2==1) result*=x;
		x*=x;
		day/=2;
	}
	return result;
}
int main()
{
	int n , a[5] , i , day ,result;
	scanf( "%d" , &n );
	while(n --){
		for( i = 0;i < 5; i ++){
			scanf( "%d" , &a[i] );
		}
		/*�����ܹ�������*/
		if(a[0] == a[3]) //ͬһ���·ݵ�ʱ�� 
			day = a[4] - a[1];
		else
			day = date[a[0]] - a[1] + a[4];
		for( i = a[0] + 1;i < a[3];i ++ ){
			day += date[i];
		}
		result = exp_via_repeated_squaring(a[2] , day);
		printf( "%d %d\n" , result , day );
	}
	return 0;
}