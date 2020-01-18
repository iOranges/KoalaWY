#include<cstdio>
#define N 500005
struct node{
	int to,nxt;
}e[N << 1];
int w[N],h[N],tot,s[N],num[N],pre[N],f[N];
long long ans;
inline void read(int &x)
{
	x = 0;char ch = getchar();int f = 1;
	while(ch > '9' || ch < '0') {if(ch == '-') f = -1;ch = getchar();}
	while(ch <= '9'&&ch >= '0') {x = x * 10 + (ch ^ 48);ch = getchar();}
	x *= f;
}

inline void add(int a,int b)
{
	e[++tot].to = b;
	e[tot].nxt = h[a];
	h[a] = tot;
}

void dfs(int u,long long preans)
{
	if(w[u] == -1) 
	{
		if(s[u])
		{
			s[u] -= 1;
			preans += 1,num[u] = 1;
			if(pre[u]) preans = preans + num[pre[u]],num[u] += num[pre[u]],pre[u] = pre[pre[u]];	
		}	
	}
	else if(w[u] == 1) 
	{
		++ s[u];
		pre[u] = f[u];	
	}
	ans = ans ^ (preans * u);
	for(int i = h[u];i;i = e[i].nxt)
	{
		int v = e[i].to;
		s[v] = s[u];
		f[v] = u;
		pre[v] = pre[u];
		dfs(v,preans);
	}
}

int main()
{
	int n,a;
	char ch;
	scanf("%d",&n);
	register int i = 0;
	ch = getchar();
	while(ch != '('&&ch != ')') ch = getchar();
	while(ch == '('||ch == ')')
		w[++ i] = (ch == '(' ? 1 : -1),ch = getchar();
	for(i = 2;i <= n;++ i)
	{
		read(a);
		add(a,i);
	}
	dfs(1,0);
	printf("%lld",ans);
	return 0;
}
