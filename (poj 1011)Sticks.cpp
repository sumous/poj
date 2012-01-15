#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
using namespace std;
int part[65], n, res, sum, sticks;
bool vis[65];

bool cmp(int a, int b)
{
    return a>b;
}
bool dfs(int cnt, int remain, int pos)
{
    if(cnt==sticks) return true;

    for(int i = pos+1 ; i < n ; i++)
    {
        if(vis[i]) continue;

        if(remain==part[i])//���Դճ�һ�����
        {
            vis[i] = true;
            if( dfs(cnt+1, res, -1) ) return true;
            vis[i] = false;
            return false;
        }
        else if(remain>part[i])//����ʣ��
        {
            vis[i] = true;
            if( dfs(cnt,remain-part[i], i) ) return true;

            vis[i] = false;
            if(remain==res) return false;

            while(part[i]==part[i+1]) i++;

        }

    }
    return false;
}
void load()//���벢��������
{
    sum = 0;
    for(int i  = 0 ; i < n;i ++)
    {
        int p;
        cin>>p, part[i] = p, sum += p;
    }
    sort(part, part+n, cmp);
}
int main()
{
    freopen("data.txt", "r",stdin);
    while(cin>>n && n)
    {
        load();

        for(res = part[0];res < sum;res++)
        {
            if(sum%res==0)
            {
                memset(vis, false, sizeof(vis));

                sticks = sum/res;
                if(dfs(1, res, -1)) break;
            }
        }
        cout<<res<<endl;
    }
    return 0;
}
