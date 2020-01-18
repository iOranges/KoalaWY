#include<cstdio>
#define N 1005
#define M 10005
#define max(x,y) ((x) > (y) ? (x) : (y))
int d[N],out[N],T[M],A[M],B[M],artime[N],lst[N],s[N],nxt[N];

int main()
{
	int n,m,k,maxx,ans = 0;
	register int i,j;
	scanf("%d%d%d",&n,&m,&k);
	for(i = 1;i < n;++ i) 
		scanf("%d",&d[i]);
	for(i = 1;i <= m;++ i)
	{
		scanf("%d%d%d",&T[i],&A[i],&B[i]);
		lst[A[i]] = max(lst[A[i]],T[i]);
		++ out[B[i]];
	}
	for(i = 1;i < n;++ i)
	{
		s[i + 1] = s[i] + out[i + 1];
		artime[i + 1] = max(artime[i],lst[i]) + d[i];
	} 
	while(k --)
	{
		maxx = 0,j = 0,nxt[n - 1] = n;
		for(i = n - 1;i > 1;-- i)
			if(lst[i] < artime[i]) nxt[i - 1] = nxt[i];
			else nxt[i - 1] = i;
		for(i = 1;i < n;++ i)
		{
			int len = s[nxt[i]] - s[i];
			if(len > maxx&&d[i]) maxx = len,j = i;	
		}
		if(!maxx) break;
		-- d[j];
		for(i = 1;i < n;++ i)
			artime[i + 1] = max(artime[i],lst[i]) + d[i];
	}
	for(i = 1;i <= m;++ i)
		ans += artime[B[i]] - T[i];
	printf("%d",ans);
	return 0;
}

