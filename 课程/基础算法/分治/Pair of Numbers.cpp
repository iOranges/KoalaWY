#include<cmath>
#include<cstdio>
#define swap(x,y) x^=y,y^=x,x^=y
#define min(x,y) ((x)<(y)?(x):(y))
int n,minn[300005][19],gbs[300005][19],s[300005],cnt,maxx = 0,t[300005],tot;
inline int gcd(int a,int b)
{
	if(a < b) swap(a,b);
	int t = a % b;
	while(t)
	{
		a = b;
		b = t;
		t = a % b;
	}
	return b;
}

void rmq()
{
	int N = log2(n);
	for(register int j=1;j<=N;j++)
		for(register int i=1;i+(1<<j)-1<=n;i++)
		{
			minn[i][j] = min(minn[i][j-1],minn[i+(1<<(j-1))][j-1]);
			gbs[i][j] = gcd(gbs[i][j-1],gbs[i+(1<<(j-1))][j-1]);
		}
}

inline bool ask(int a,int b)
{
	int x = log2(b - a + 1);
	if(min(minn[a][x],minn[b-(1<<x)+1][x]) == gcd(gbs[a][x],gbs[b-(1<<x)+1][x]))
		return true;
	else
		return false;
}

bool check(int k)
{
	cnt = 0;
	for(register int i=1;i<=n-k+1;i++)
		if(ask(i,i+k-1))
			s[++cnt] = i;
	if(cnt) 
	{
		if(k>maxx)
		{
			tot = cnt;
			maxx = k;
			for(register int i=1;i<=cnt;i++)
				t[i] = s[i];
		}
		return true;
	}
	return false;
}

int main()
{
	int i,x,l,r,mid;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		gbs[i][0] = minn[i][0] = x;
	}
	rmq();
	l = 1,r = n;
	while(l<=r)
	{
		mid = (l+r)>>1;
		if(check(mid))
			l = mid + 1;
		else
			r = mid - 1;
	}
	printf("%d %d\n",tot,r-1);
	for(i=1;i<=tot;i++)
		printf("%d ",t[i]);
	return 0;
}
