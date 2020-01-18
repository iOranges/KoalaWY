#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int n,m,h[3001],tot,f[3001][3001],d[3001];
struct node{
    int son,next,v;
}t[3001];

inline void read(int& x)
{
    char ch;x = 0;
    ch = getc(stdin);
    while(ch>'9'||ch<'0') ch = getc(stdin);
    while(ch<='9'&&ch>='0') {x = (x<<1) + (x<<3) + (ch ^ 48);ch = getc(stdin);}
}

void add(int a,int b,int k)
{
    t[++tot].son = b;
    t[tot].next = h[a];
    h[a] = tot;
    t[tot].v = k;
}

void dfs(int u)
{
    if(!h[u]) d[u] = 1;
    for(int i=h[u];i;i=t[i].next)
    {
        dfs(t[i].son);
        d[u] += d[t[i].son];
        for(int j=d[u];j>0;j--)
            for(int k=j;k>=1;k--)
                f[u][j] = max(f[u][j],f[u][j-k]+f[t[i].son][k]-t[i].v);
    }
}

int main()
{
    int i,a,b,k,j;
    read(n),read(m);
    for(i=1;i<=n-m;i++)
    {
        read(k);
        for(j=1;j<=k;j++)
        {
            read(a),read(b);
            add(i,a,b);
        }
    }
    memset(f,0xc1,sizeof f);
    for(i=1;i<=n;i++)
        f[i][0] = 0;
    for(i=n-m+1;i<=n;i++)
        read(f[i][1]);
    dfs(1);
    for(i=m;i>=0;i--)
        if(f[1][i]>=0)
        {
            printf("%d",i);	
            break;		
        }
    return 0;
}
