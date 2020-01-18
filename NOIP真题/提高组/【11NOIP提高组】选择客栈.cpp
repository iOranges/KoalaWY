#include<cstdio>
#include<cstring>
#define N 200005
#define min(x,y) ((x) < (y) ? (x) : (y))
int log2[N],minn[N][18],c[N],s[N][55];
inline int ask(int l,int r)
{
	int x = log2[r - l + 1];
	return min(minn[l][x],minn[r - (1 << x) + 1][x]);
}

int main()
{
	int n,k,p,cnt = 0;
	register int i,j,l,r,mid,q;
	scanf("%d%d%d",&n,&k,&p);
	log2[1] = 0;
	for(i = 2;i <= n;++ i)
		log2[i] = log2[i / 2] + 1;
	memset(minn,0x7f,sizeof minn);
	for(i = 1;i <= n;++ i)
	{
		scanf("%d%d",&c[i],&minn[i][0]);
		for(j = 0;j < k;++ j)
			s[i][j] = s[i - 1][j];
		++ s[i][c[i]];
	}
	for(j = 1;j <= log2[n];++ j)
		for(i = 1;i + (1 << j) - 1 <= n;++ i)
			minn[i][j] = min(minn[i][j - 1],minn[i + (1 << (j - 1))][j - 1]);
	for(i = 1;i <= n;++ i)
	{
		l = i + 1,r = n,q = n;
		while(l <= r)
		{
			mid = (l + r) >> 1;
			if(ask(i,mid) > p)
				l = mid + 1;
			else 
				r = mid - 1,q = r;
		}
		cnt += s[n][c[i]] - s[q][c[i]];
	}
	printf("%d",cnt);
	return 0;
}
