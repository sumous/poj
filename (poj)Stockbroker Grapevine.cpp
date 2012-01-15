#include<iostream>
#include<string.h>
using namespace std;
#define INF 2139062143
int map[105][105], d[105][105];
int main()
{
	int n;
//	freopen("data.txt","r",stdin);
	while(cin>>n && n!= 0)
	{

		memset(d,127,sizeof(d));

		for(int i = 1;i <= n;i++)
		{
			cin>>d[0][0];
			for(int j = 1;j <= d[0][0];j++)
			{
				int m;
				cin>>m;
				cin>>d[i][m];
			}
		}
		for(int i = 1;i <= n;i ++) d[i][i]=0;
		for(int i = 1; i<= n;i ++)
			for(int j = 1;j <= n;j ++)
				for(int k = 1;k <= n;k++)
				{
					if(d[j][i]!=INF && d[i][k]!= INF && d[j][k]>d[j][i]+d[i][k])
						d[j][k]=d[j][i]+d[i][k];
				}
		int start;
		int min=INF;
		for(int i = 1;i <= n;i++)
		{
			int max=0;
			for(int j = 1;j <= n;j ++)
			{
				if(d[i][j]>max) max=d[i][j];
			}
			if(max<min){min=max;start=i;}
		}
		cout<<start<<' '<<min<<endl;
	}
	return 0;
}