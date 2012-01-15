#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
int n, k, cnt;
bool vis[9][9], col[9];
void load()
{
    cnt = 0;
    memset(col, false, sizeof(col));
    memset(vis, false, sizeof(vis));

    for(int i = 0;i < n;i ++)
        for(int j = 0;j < n;j ++)
        {
            char ch;
            cin>>ch;
            if(ch=='#') vis[i][j] = true;
        }
}
void dfs(int row, int piece)
{
    if(piece==0)
    {
        cnt++;
        return;
    }

    for(int i = 0;i < n;i ++)
    {
        if(vis[row][i] && !col[i])
        {
            col[i] = true;
            dfs(row+1, piece-1);
            col[i] = false;
        }
    }

    if(n-row>piece) dfs(row+1, piece);
}
int main()
{
    freopen("data.txt", "r", stdin);
    while(cin>>n>>k && n!=-1)
    {
        load();
        dfs(0, k);
        cout<<cnt<<endl;
    }
    return 0;
}
