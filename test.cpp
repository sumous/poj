#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
struct binTree
{
    int l,r,color;
    bool cover;
}Tree[500000];
void build_tree(int v,int l,int r)
{
    Tree[v].l=l;
    Tree[v].r=r;
    Tree[v].color=1;
    Tree[v].cover=true;
    if(l==r) return ;
    int m=(l+r)/2;
    build_tree(v*2,l,m);
    build_tree(v*2+1,m+1,r);
}
void insert(int v,int l,int r,int color)
{
    if(Tree[v].l==l&&Tree[v].r==r){
        Tree[v].cover=true;
        Tree[v].color=color;
        return ;
    }
    if(Tree[v].cover){
        Tree[v*2].color=Tree[v*2+1].color=Tree[v].color;
        Tree[v*2].cover=Tree[v*2+1].cover=true;
        Tree[v].cover=false;
    }
    int m=(Tree[v].l+Tree[v].r)/2;
    if(r<=m) insert(v*2,l,r,color);
    else if(l>m) insert(v*2+1,l,r,color);
    else insert(v*2,l,m,color),insert(v*2+1,m+1,r,color);
}
bool visit[31];
void query(int v,int l,int r)
{
    if(Tree[v].cover)    {visit[Tree[v].color]=1;return ;}
    int m=(Tree[v].l+Tree[v].r)/2;
    if(r<=m) query(v*2,l,r);
    else if(l>m) query(v*2+1,l,r);
    else query(v*2,l,m),query(v*2+1,m+1,r);
}
int main()
{
    freopen("data.txt","r",stdin);
    int n,m,q,x,y,t,color,ans;
    char ch;
    while(scanf("%d %d %d",&n,&m,&q)!=EOF)
    {
        build_tree(1,1,n);getchar();
        for(int i=1;i<=q;i++)
        {
            
           	cin>>ch>>x>>y;//cout<<ch<<endl;
            if(x>y){t=x;x=y;y=t;}
            if(ch=='C') {
                scanf("%d",&color);
                insert(1,x,y,color);
            }
            else{
                ans=0;
                memset(visit,0,sizeof(visit));
                query(1,x,y);
                for(int j=1;j<=m;j++) ans+=visit[j]; printf("%d\n",ans);   
            }//getchar();
        }
    }
    return 0;
}
