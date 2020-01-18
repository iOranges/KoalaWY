#include<cstdio>
#define min(x,y) ((x) < (y) ? (x) : (y))
struct node{
	int nxt,to,fr;
}e[50005];
bool vis[10005],instack[10005];
int h[10005],num[10005],siz[10005],dfn[10005],low[10005],s[10005],dig[10005],top,tot,cnt,n,idx;
inline void add(int a,int b)
{
	e[++tot].to = b;
	e[tot].nxt = h[a];
	h[a] = tot;
	e[tot].fr = a;
}

void dfs(int u)
{
	instack[u] = vis[u] = true;
	s[++top] = u;
	dfn[u] = low[u] = ++idx;
	for(int i = h[u];i;i = e[i].nxt)
		if(!vis[e[i].to])
		{
			dfs(e[i].to);
			low[u] = min(low[u],low[e[i].to]);
		}
		else if(instack[e[i].to])
			low[u] = min(low[u],dfn[e[i].to]);
	if(dfn[u] == low[u])
	{
		num[u] = ++ cnt;
		instack[u] = false;
		siz[cnt] = 1;
		while(s[top] != u)
		{
			num[s[top]] = cnt;
			instack[s[top --]] = false;
			siz[cnt] ++;
		}
		-- top;
	}
}

int main()
{
	int m,a,b;
	register int i;
	scanf("%d%d",&n,&m);
	for(i = 1;i <= m;++ i)
	{
		scanf("%d%d",&a,&b);
		add(a,b);
	}
	for(i = 1;i <= n;++ i)
		if(!vis[i])
			dfs(i);
	for(i = 1;i <= m;++ i)
		if(num[e[i].fr] != num[e[i].to])
			++ dig[num[e[i].fr]];
	int ans = 0;
	for(i = 1;i <= cnt;++ i)
		if(!dig[i])	
		{
			if(!ans)
				ans = siz[i];
			else
			{
				ans = 0;
				break;
			}			
		}
	printf("%d",ans);
	return 0;
}
