#include<cstdio>
#include<cstring>
#define min(x,y) ((x) < (y) ? (x) : (y))
struct node{
	int to,nxt;
}e[200005];
bool vis[20005],cut[20005];
int dfn[20005],low[20005],h[20005],cnt,tot,idx,num,ans[20005];
inline void add(int a,int b)
{
	e[++tot].to = b;
	e[tot].nxt = h[a];
	h[a] = tot;
}

void dfs(int u,int fa)
{
	vis[u] = true;
	dfn[u] = low[u] = ++ idx;
	for(int i = h[u];i;i = e[i].nxt)
		if(!vis[e[i].to])
		{
			dfs(e[i].to,fa);
			if(u == fa) ++ num;
			else{
				low[u] = min(low[u],low[e[i].to]);
				if(low[e[i].to] >= dfn[u]) cut[u] = true;
			}
		}
		else 
			low[u] = min(low[u],dfn[e[i].to]);
}

int main()
{
	int n,m,a,b;
	register int i;
	scanf("%d%d",&n,&m);
	for(i = 1;i <= m;++ i)
	{
		scanf("%d%d",&a,&b);
		add(a,b),add(b,a);
	}
	for(i = 1;i <= n;++ i)
		if(!vis[i])
		{
			num = 0;
			dfs(i,i);	
			if(num > 1) ans[++ cnt] = i;					
		}
	for(i = 2;i <= n;++ i)
	{
		if(cut[i])	ans[++ cnt] = i;	
//		if(!vis[i]) {cnt = 0;break;}	
	}
	printf("%d\n",cnt);
	for(i = 1;i <= cnt;++ i)
		printf("%d ",ans[i]);
	return 0;
}
