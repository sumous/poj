//����POJ1003�⣺��Ƭ��Ŀ 
#include<stdio.h>
int main()
{
	double i; 	//�����double����-->ת����int���� 
	double b;  //�������ֵ 
    double sum; //�����ܺͽ��
    int k;
	while(scanf("%lf",&b)!=EOF && b!=0){
       //������һ�κ�sum�����趨Ϊ0 
       for(sum = 0,i = 2;;i++){
          sum = sum +1/i;
          if(sum>b) break;  //����ж�sum���������bֵ������ǰforѭ�� 
       }                      
       //��ʱ��Ƭ��Ϊi-1  
       k = i-1;                
       printf("%d card(s)\n",k);
     }
	return 0;
}
