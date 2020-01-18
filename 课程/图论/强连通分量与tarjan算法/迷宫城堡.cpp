#include<cstdio>
#include<cstring>
#define min(x,y) ((x) < (y) ? (x) : (y))
struct node{
	int to,nxt;
}e[100005];
bool vis[10005],instack[10005];
int h[10005],dfn[10005],num[10005],low[10005],s[10005],top,cnt,tot,idx;
inline void add(int a,int b)
{
	e[++tot].to = b;
	e[tot].nxt = h[a];
	h[a] = tot;
}

void dfs(int u)
{
	low[u] = dfn[u] = ++ idx;
	instack[u] = vis[u] = true;
	s[++top] = u;
	for(int i = h[u];i;i = e[i].nxt)
		if(!vis[e[i].to])
		{
			dfs(e[i].to);
			low[u] = min(low[u],low[e[i].to]);
		}
		else if(instack[e[i].to])
			low[u] = min(low[u],dfn[e[i].to]);
	if(low[u] == dfn[u])
	{
		num[u] = ++ cnt;
		instack[u] =false;
		while(s[top] != u)
		{
			instack[s[top]] = false;
			num[s[top--]] = cnt;
		}
		-- top;
	}
}

int main()
{
	int n,m,a,b;
	register int i;
	while(scanf("%d%d",&n,&m))
	{
		if(n == 0&&m == 0) break;
		memset(h,0,sizeof h);
		memset(s,0,sizeof s);
		memset(vis,false,sizeof vis);
		memset(instack,false,sizeof instack);
		tot = top = cnt = idx = 0;
		for(i = 1;i <= m;++ i)
		{
			scanf("%d%d",&a,&b);
			add(a,b);
		}
		for(i = 1;i <= n;++ i)
			if(!vis[i])
				dfs(i);
		if(cnt != 1)
			printf("No\n");
		else
			printf("Yes\n");
	}
}
