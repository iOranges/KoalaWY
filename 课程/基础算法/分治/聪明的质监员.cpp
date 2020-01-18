#include<cstdio>
#include<cstring>
#define max(x,y) ((x)>(y)?(x):(y))
#define min(x,y) ((x)<(y)?(x):(y))
int n,m,w[200005],v[200005],L[200005],R[200005],num[200005];
long long s,minn = 0x7f7f7f7f7f7f7f7f,V[200005];
inline void read(int &x)
{
	char ch;x = 0;
	ch = getc(stdin);
	while(ch<'0'||ch>'9') ch = getc(stdin);
	while(ch<='9'&&ch>='0') {x = (x<<1) + (x<<3) + (ch^48);ch = getc(stdin);}
}

bool check(int k)
{
	register int i;
	long long sum = 0;
	memset(V,0,sizeof V);
	memset(num,0,sizeof num);
	for(i=1;i<=n;++i)
	{
		num[i] = num[i-1];
		V[i] = V[i-1];
		if(w[i] >= k)
		{
			num[i] += 1;
			V[i] += 1ll * v[i];
		}		
	}
	for(i=1;i<=m;++i)
		sum += (V[R[i]] - V[L[i]-1]) * 1ll * (num[R[i]] - num[L[i]-1]);
	if(sum >= s)
	{
		minn = min(minn,sum - s);
		return true;
	}
	minn = min(minn,s - sum);
	return false;
}

int main()
{
	register int i,l=0x7ffffff,r=0,mid;
	read(n),read(m);
	scanf("%lld",&s);
	for(i=1;i<=n;++i)
	{
		read(w[i]),read(v[i]);	
		l = min(l,w[i]),r = max(r,w[i]);
	}
	for(i=1;i<=m;++i)
		read(L[i]),read(R[i]);
	--l,++r;
	while(l<=r)
	{
		mid = (l + r) >> 1;
		if(check(mid)) 
			l = mid + 1;
		else
			r = mid - 1;
	}
	printf("%lld",minn);
	return 0;
}
