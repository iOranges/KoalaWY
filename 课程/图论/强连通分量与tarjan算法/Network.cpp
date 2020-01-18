#include<cstdio>
#include<cstring>
#define min(x,y) ((x) < (y) ? (x) : (y))
struct node{
	int to,nxt;
}e[50005];
char s[1005];
bool vis[105],cut[105];
int h[105],low[105],dfn[105],tot,cnt,idx,num;
inline void add(int a,int b)
{
	e[++tot].to = b;
	e[tot].nxt = h[a];
	h[a] = tot;
}

void dfs(int u,int fa)
{
	dfn[u] = low[u] = ++ idx;
	vis[u] = true;
	for(int i = h[u];i;i = e[i].nxt)
		if(!vis[e[i].to]&&e[i].to != u)
		{
			dfs(e[i].to,fa);
			if(u == fa) ++ num;
			else
			{
				low[u] = min(low[u],low[e[i].to]);
				if(low[e[i].to] >= dfn[u]) cut[u] = true;
//				else cut[u] = false;
			}
		}
		else
			low[u] = min(low[u],dfn[e[i].to]);
}

int main()
{
	int n,a,b;
	register int i;
	while(scanf("%d",&n))
	{
		if(!n) break;
		memset(h,0,sizeof h);
		memset(e,0,sizeof e);
		memset(vis,0,sizeof vis);
		memset(cut,0,sizeof cut);
		cnt = idx = tot = num = 0;
		gets(s);
		while(gets(s))
		{
			i = a = 0;
			while(s[i] >= '0'&&s[i] <= '9')
				a = a * 10 + (s[i++] ^ 48);
			if(!a) break;
			int len = strlen(s);
			for(;i < len;++ i)
			{
				b = 0;
				while(s[i] >= '0'&&s[i] <= '9')
					b = b * 10 + (s[i++] ^ 48);
				if(b) add(a,b),add(b,a);
			}
		}
		dfs(1,1);
		if(num > 1) ++cnt;
		for(i = 2;i <= n;++ i)
			if(cut[i])
				++cnt;
		for(i = 2;i <= n;++ i)
			if(!vis[i])
			{
				cnt = 0;		
				break;		
			}
		printf("%d\n",cnt);
	}
	return 0;
}
