# include<iostream>
# include<cmath>
# include<cstring>
# include<cstdio>
# include<algorithm>

using namespace std;
struct point
{
    /* l表示当前点距离为d的左边, r表示当前点距离为d的右边 */
    double l, r;//一定要double型啊，我以为都是整型可以呢
}p[10005];
int n;
double d;
int res;
bool flag;
/* 求距离 */
double dist(int b)
{
    return sqrt( double(d*d-b*b) );
}
void load()
{
    for (int i = 0; i < n; i++)
    {
        cin >> p[i].l >> p[i].r;
        if (p[i].r > d || p[i].r < 0) flag = true;
        double l = dist(p[i].r), mid = p[i].l;
        p[i].l = mid - l, p[i].r = mid + l;
    }
}
/* 比较函数 */
bool cmp(struct point a, struct point b)
{
    if (a.l == b.l) return a.r < b.r;
    else return a.l < b.l;
}
void solve()
{
    sort (p, p+n, cmp);
    double r = p[0].r;
    res = 1;
    for (int i = 1; i < n; i++)
    {
        /* 无交集，需要换成下一个点 */
        if (p[i].l > r)
        {
            res ++;
            r = p[i].r;
        }
        /* 当前r比当前线段的右边界大 */
        if (p[i].r < r)
            r = p[i].r;
        
    }
}
int main()
{
    freopen("data", "r", stdin );
    int cas = 1;
    while(cin >> n >> d && n && d)
    {
        flag = false;
        load();
        if (flag) printf("Case %d: -1\n",cas);
        else
        {
            solve();
             printf("Case %d: %d\n",cas,res);
        }
        
        cas ++;
    }
    return 0;
}
