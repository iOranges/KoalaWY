#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int n,h[1001],tot,f[1001],ans[1001],cnt;
struct node{
    int son,next;
}t[2005];

inline void read(int& x)
{
    char ch;x = 0;
    ch = getc(stdin);
    while(ch>'9'||ch<'0') ch = getc(stdin);
    while(ch<='9'&&ch>='0') {x = (x<<1) + (x<<3) + (ch ^ 48);ch = getc(stdin);}
}

void add(int a,int b)
{
    t[++tot].son = b;
    t[tot].next = h[a];
    h[a] = tot;
}

void dfs(int u,int pre)
{
    vector<int> s; 
    for(int i=h[u];i;i=t[i].next)
        if(t[i].son!=pre)
        {
            dfs(t[i].son,u);
            s.push_back(f[t[i].son]);			
        }
    sort(s.begin(),s.end());
    int siz = s.size();
    for(int i=1;i<=siz;i++)
        f[u] = max(f[u],s[i-1]+siz-i+1); 
}

int main()
{
    int i,x,minn = 0x7fffffff;
    read(n);
    for(i=2;i<=n;i++)
    {
        read(x);
        add(x,i),add(i,x); 
    }
    for(i=1;i<=n;i++)
    {
        memset(f,0,sizeof f);
        dfs(i,0);
        ans[++cnt] = f[i];
        minn = min(minn,f[i]);
    }
    printf("%d\n",minn+1);
    for(i=1;i<=cnt;i++)
        if(ans[i]==minn)
            printf("%d ",i);
    return 0;
}
