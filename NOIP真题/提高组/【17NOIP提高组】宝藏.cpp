#include<cstdio>
#include<cstring>
#define min(x,y) ((x) < (y) ? (x) : (y))
int f[13][13][1 << 12],pw[12],siz[1 << 12],dis[13][13],Log[1 << 13];
inline int lowbit(int x)
{
	return x & (-x);
}

int main()
{
	int n,m,x,a,b;
	register int i,j,k,s;
	scanf("%d%d",&n,&m);
	pw[0] = 1; 
	for(i = 1;i <= n;++ i)
		pw[i] = pw[i - 1] << 1;
	for(i = 0;i <= n;++ i)
		Log[pw[i]] = i;
	for(i = 1;i < pw[n];++ i) 
		siz[i] = siz[i - lowbit(i)] + 1;
	memset(dis,0x3f,sizeof dis);
	for(i = 1;i <= m;++ i)
	{
		scanf("%d%d%d",&a,&b,&x);
		if(x < dis[a][b]) dis[a][b] = dis[b][a] = x;
	}
	memset(f,0x3f,sizeof f);
	for(i = 1;i <= n;++ i)
		f[n - 1][i][0] = 0;
	for(j = n - 2;j >= 0;-- j)
		for(i = 1;i <= n;++ i)
		{
			f[j][i][0] = 0;
			for(x = 0;x < pw[n];++ x)		
				if(siz[x] <= n - j - 1&&!(x & pw[i - 1])) 
					for(s = x;s;s = x & (s - 1))
					{
						int s2 = s;
						for(k = Log[lowbit(s2)] + 1;s2;s2 -= pw[k - 1],k = Log[lowbit(s2)] + 1)
							if(dis[i][k] != 0x3f3f3f3f)
								f[j][i][x] = min(f[j][i][x],dis[i][k] * (j + 1) + f[j + 1][k][s ^ pw[k - 1]] + f[j][i][x ^ s]);
					}		
		}
	int ans = 0x3f3f3f3f;
	for(i = 1;i <= n;++ i) ans = min(ans,f[0][i][(pw[n] - 1) ^ pw[i - 1]]);
	printf("%d",ans);
	return 0;
}

