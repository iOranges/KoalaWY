#include<cstdio>
struct node{
	int to,nxt;
}e[100005 << 1];
const long long p = 1e9 + 7;
int n,k,tot,h[100005],s[100005][11];
long long f[100005][11],dp[100005][11];//f不加根,dp加根 
inline void read(int &x)
{
	x = 0;char ch = getc(stdin);
	while(ch > '9' || ch < '0') ch = getc(stdin);
	while(ch <= '9'&&ch >= '0') {x = x * 10 + (ch ^ 48);ch = getc(stdin);}
}

inline void add(int a,int b)
{
	e[++ tot].to = b;
	e[tot].nxt = h[a];
	h[a] = tot;
}

long long ksm(long long a,long long b)
{
	long long ans = 1;
	while(b)
	{
		if(b & 1) ans = a * ans % p;
		a = a * a % p;
		b >>= 1;
	}
	return ans;
}

void dfs1(int u,int pre)
{
	for(register int i = 0;i <= k;++ i) s[u][i] = f[u][i] = dp[u][i] = 1;
	for(int i = h[u];i;i = e[i].nxt)
	{
		int v = e[i].to;
		if(v == pre) continue;
		dfs1(v,u);
		register int j;
		for(j = 1;j <= k;++ j)
		{
			s[u][j] += s[v][j - 1];
			f[u][j] = f[u][j] * dp[v][j - 1] % p;
		}
	}
	for(register int i = 0;i <= k;++ i) dp[u][i] = f[u][i] * s[u][i] % p;
}

void dfs2(int u,int pre)
{
	for(register int i = k;i >= 2;-- i)
		f[u][i] = f[pre][i - 1] * ksm(dp[u][i - 2],p - 2) % p * f[u][i] % p * (s[pre][i - 1] - s[u][i - 2]) % p;
	for(register int i = k;i >= 2;-- i)
		s[u][i] = (s[u][i] + s[pre][i - 1] - s[u][i - 2]);
	s[u][1] += s[pre][0];
	for(register int i = 0;i <= k;++ i)
		dp[u][i] = f[u][i] * s[u][i] % p;
	for(int i = h[u];i;i = e[i].nxt)
	{
		int v = e[i].to;
		if(v == pre) continue;
		dfs2(v,u);
	}
}

int main()
{
	int a,b;
	read(n),read(k);
	register int i;
	for(i = 1;i < n;++ i)
	{
		read(a),read(b);
		add(a,b),add(b,a);
	}
	dfs1(1,0);
	for(i = h[1];i;i = e[i].nxt)
		dfs2(e[i].to,1);
	for(i = 1;i <= n;++ i) printf("%d ",s[i][k]);
	puts("");
	for(i = 1;i <= n;++ i) printf("%lld ",dp[i][k]);
	return 0;
}
