/**
 * trie树简单应用
 * 第一次写，不太清楚原理，刚开始用链表来写，我觉得应该会省点内存
 * 但是，TLE是必然，申请内存和删除内存的操作过大，必然要超时。
 * 所以只能用静态数组。
 * 考虑两种情况：（前缀字符串A， 字符串B）
 * 第一种：A在B前面出现
 * 第二种：B在A前面出现
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Trie
{
    bool end;
    int nxt[10];
}trie[1000010];
/* idx为数组trie被使用的最后一个结点的索引 */
int n, t, idx;
bool flag;

void init(int j)
{
    trie[j].end = false;
    for (int i = 0; i < 10; i++)
        trie[j].nxt[i] = 0;
}

void solve(char *s)
{
    int cur = 0;
    while(*s != '\0')
    {
        int& r = trie[cur].nxt[*s-'0'];
        if (r == 0)
        {
            idx++;
            r = idx;
            init(idx);           
        }
        /* 前缀字符串在前面出现 */
        if (trie[r].end)
        {
            flag = true;
            return;
        }
        cur = r;
        s++;
    }
    /* 前缀字符串在后面出现 */
    for (int i = 0; i < 10; i++)
        if (trie[cur].nxt[i] !=0)
        {
            flag = true;
            return;
        }
    trie[cur].end = true;
}

int main()
{
    freopen("data", "r", stdin);
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        idx = 0;
        init(0);
        scanf("%d", &n);
        char s[11];
        flag = false;

        for (int j = 0; j < n; j++)
        {
            scanf("%s", s);
            if (!flag)
                solve(s);     
        }
        
        if (!flag) printf("YES\n");
        else printf("NO\n");
        
    }
    return 0;
}
