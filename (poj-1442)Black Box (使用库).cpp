# include <stdio.h>
# include <queue>
# include <functional>
# include <vector>
# include <deque>
using namespace std;
long m, n;
long A[30005], u[30005];
struct cmp1  
{    
    bool operator ()(long &a,long &b)  
    {    
        return a>b;//最小值优先     
    }    
};    
struct cmp2  
{    
    bool operator ()(long &a,long &b)  
    {    
        return a<b;//最大值优先     
    }    
};
priority_queue<long,vector<long>,cmp1>q2;//最小值优先     
priority_queue<long,vector<long>,cmp2>q1;//最大值优先   

void load()
{
    scanf("%ld %ld", &m, &n);
    for (int i = 1; i <= m; i++)
        scanf("%ld", &A[i]);
    for (int i = 1; i <= n; i++)
        scanf("%ld", &u[i]);
}
void solve()
{
    int j = 1;
    for (int i = 1; i <= n; i++)
    {
        for ( ; j <= u[i]; j++)
            q2.push(A[j]);

        while (!q1.empty() && !q2.empty() && q2.top() < q1.top())
        {
            long m1 = q2.top();
            q2.pop();
            long m2 = q1.top();
            q1.pop();
            q1.push(m1);
            q2.push(m2);
        }
        q1.push(q2.top());
        q2.pop();
        printf("%ld\n",q1.top());
    }
}
int main()
{
    freopen("data", "r", stdin);
    load();
    solve();
    return 0;
}
