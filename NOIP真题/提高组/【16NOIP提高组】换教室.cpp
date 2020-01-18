#include<cstdio>
#include<cstring>
#define min(x,y) ((x) < (y) ? (x) : (y))
double e[2005][2][2],f[2005][2005][2],p[2005];
int c[2005],d[2005],tot,h[305],mp[305][305];
template <typename e>inline void read(e &x)
{
	x = 0;char ch = getc(stdin);
	while(ch > '9' || ch < '0') ch = getc(stdin);
	while(ch <= '9'&&ch >= '0') {x = x * 10 + (ch ^ 48);ch = getc(stdin);}
}

int main()
{
	int t,q,n,m,a,b,z;
	read(t),read(q),read(n),read(m);
	register int i,j,k;
	for(i = 1;i <= t;++ i)
		read(c[i]);
	for(i = 1;i <= t;++ i)
		read(d[i]);
	for(i = 1;i <= t;++ i)
		scanf("%lf",&p[i]);
	memset(mp,0x3f,sizeof mp);
	for(i = 1;i <= m;++ i)
	{
		read(a),read(b),read(z);
		mp[a][b] = mp[b][a] = min(mp[b][a],z);
	}
	for(i = 1;i <= n;++ i)
		mp[i][i] = 0;
	for(k = 1;k <= n;++ k)
		for(i = 1;i <= n;++ i)
			for(j = 1;j <= n;++ j)
				mp[i][j] = min(mp[i][j],mp[i][k] + mp[k][j]);
	for(i = 2;i <= t;++ i)
	{
		e[i][0][0] = mp[c[i-1]][c[i]];
		e[i][0][1] = p[i] * mp[c[i-1]][d[i]] + (1.0 - p[i]) * mp[c[i-1]][c[i]];
		e[i][1][0] = p[i-1] * mp[d[i-1]][c[i]] + (1.0 - p[i-1]) * mp[c[i-1]][c[i]];
		e[i][1][1] = p[i-1] * (p[i] * mp[d[i-1]][d[i]] + (1.0 - p[i]) * mp[d[i-1]][c[i]]) + (1.0 - p[i-1]) * (p[i] * mp[c[i-1]][d[i]] + (1.0 - p[i]) * mp[c[i-1]][c[i]]);
	}
	memset(f,0x7f,sizeof f);
	f[1][0][0] = f[1][1][1] = 0;
	for(i = 2;i <= t;++ i)
		f[i][0][0] = e[i][0][0] + f[i-1][0][0];
	for(j = 1;j <= q;++ j)
		for(i = 2;i <= t;++ i)
		{
			f[i][j][0] = min(f[i][j][0],min(f[i-1][j][0] + e[i][0][0],f[i-1][j][1] + e[i][1][0]));
			f[i][j][1] = min(f[i][j][1],min(f[i-1][j-1][0] + e[i][0][1],f[i-1][j-1][1] + e[i][1][1]));
		}
	double ans = 9999999999;
	for(i = 0;i <= q;++ i)
		ans = min(f[t][i][0],min(ans,f[t][i][1]));
	printf("%.2lf",ans);
	return 0;
}
