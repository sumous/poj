#include <iostream>
#include <queue>
#include <string.h>
#define MAX 100000
using namespace std;
long n, k, d[2*MAX+1];

queue<long>q;

void init()
{
    for(long i = 0;i < 2*MAX+1;i ++)
        d[i] = 2*MAX+1;
}

void bfs()
{
    d[k] = k-n, d[n] = 0;
    if(d[k]==0) return;
    q.push(n);

    while(!q.empty())
    {
        long X = q.front();
        q.pop();
        if(X == k) break;

        if(X<k && d[X]+1<d[X+1])//X+1
        {
            d[X+1] = d[X]+1;
            q.push(X+1);
        }
        if(X<k && d[X]+1<d[2*X])
        {
            d[2*X] = d[X]+1;
            q.push(2*X);
        }
        if(X-1>=0 && d[X]+1<d[X-1])
        {
            d[X-1]= d[X]+1;
            q.push(X-1);
        }
    }
}
int main()
{
    cin>>n>>k;
    if(n>k){cout<<n-k<<endl;return 0;}

    init();
    bfs();
    cout<<d[k]<<endl;
    return 0;
}
