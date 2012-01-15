#include<stdio.h>
#include<string.h>
typedef struct DNA
{
	char a[50];
	int b[2];
}DNA;
int main()
{
	int n,m,i,j,k,temp;
	 DNA s[100];
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++)
	{
		
			scanf("%s",s[i].a);
		
	}
	for(i=0;i<m;i++)
	{
		s[i].b[0]=0;
		for(j=0;j<n;j++)
		{
			for(k=j;k<n;k++)
			{
				if(s[i].a[j]>s[i].a[k]) s[i].b[0]++;
			}
			
		}
	}
		for(i=0;i<m;i++)
		{
			s[i].b[1]=s[i].b[0];
		}
	for(i=0;i<m-1;i++)
	{
		for(j=i+1;j<m;j++)
		{
		if(s[i].b[0]>s[j].b[0])
		{
		
			temp=s[i].b[0];
			s[i].b[0]=s[j].b[0];
			s[j].b[0]=temp;
		}
		}
	}
	for(i=0;i<m;i++)
	{
		for(j=0;j<m;j++)
		{
		if(s[i].b[0]==s[j].b[1])
	{printf("%s",s[j].a);break;}	
			
		}
		printf("\n");
	}
	return 0;
}