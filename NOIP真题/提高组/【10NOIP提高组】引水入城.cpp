#include<cstdio>
#include<cstring>
#define min(x,y) ((x) < (y) ? (x) : (y))
#define N 505
bool water[N],vis[N][N];
int f[N],h[N][N],n,m;
struct interval{
	int l,r;
	interval(int L = 0,int R = 0): l(L),r(R) {} 
	void operator += (const interval b)
	{
		if(b.l == 0) return;
		if(b.l < l||l == 0) l = b.l;
		if(b.r > r) r = b.r;
	}
}p[N][N];
interval dfs(int x,int y)
{
	if(vis[x][y]) return p[x][y];
	if(x > 1 && h[x][y] > h[x - 1][y])
		p[x][y] += dfs(x - 1,y);
	if(x < n && h[x][y] > h[x + 1][y])
		p[x][y] += dfs(x + 1,y);
	if(y > 1 && h[x][y] > h[x][y - 1])
		p[x][y] += dfs(x,y - 1);
	if(y < m && h[x][y] > h[x][y + 1])
		p[x][y] += dfs(x,y + 1);
	if(x == n) 
		p[x][y] += interval(y,y),water[y] = true;
	vis[x][y] = true;
	return p[x][y];
}

int main()
{
	scanf("%d%d",&n,&m);
	register int i,j,k;
	for(i = 1;i <= n;++ i)
		for(j = 1;j <= m;++ j)
			scanf("%d",&h[i][j]);
	for(i = 1;i <= m;++ i)
		dfs(1,i);
	int cnt = 0;
	for(i = 1;i <= m;++ i)
		if(water[i]) ++ cnt;
	if(cnt < m)
		printf("0\n%d",m - cnt);
	else
	{
		memset(f,0x7f,sizeof f);
		f[0] = 0; 
		for(i = 1;i <= m;++ i)
			for(j = 1;j <= m;++ j)
				if(p[1][j].l <= i&&p[1][j].r >= i)
					f[i] = min(f[i],f[p[1][j].l - 1] + 1);
		printf("1\n%d",f[m]);
	}
	return 0;
}

