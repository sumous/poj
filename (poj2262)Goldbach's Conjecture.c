#include<stdio.h>

int main()
{
  long i,j,n,a[100],b[100],d[1000000]={0};
for(i=2;i<=10000;i++)
{
	for(j=2*i;j<10000;j+=i) d[j]=1;
}                                 //��ɸ����1000000���ڵ������ҳ��� 
  for(n=0;;n++)
  {
  	scanf("%ld",&a[n]);
  	if(!a[n]) break;//�����ı�־ 
  	else 
  	{
  		for(j=3;;j++)
  		{
  	      if(!d[j]&&!d[a[n]-j]) {b[n]=j;break;} 
	    }//�ҳ���������������Ȼ������ѭ�� 
   }
  }

  for(i=0;i<n;i++) 
     printf("%ld=%ld+%ld\n",a[i],b[i],a[i]-b[i]);
  return 0;	
}