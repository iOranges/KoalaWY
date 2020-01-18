#include<cstdio>
#include<cstring>
#define ll long long
const ll p = 1e9+7;
int n;
struct node{
	ll a[105][105];
	node(){	memset(a,0,sizeof a);}
}A;

template <typename e>inline void read(e &x)
{
	x = 0;char ch = getc(stdin);
	while(ch > '9' || ch < '0') ch = getc(stdin);
	while(ch <= '9'&&ch >= '0') {x = x * 10 + (ch ^ 48);ch = getc(stdin);}
}

inline node mul(node x,node y)
{
	node ans;
	register int i,j,k;
	for(i = 1;i <= n;++ i)
		for(j = 1;j <= n;++ j)
			for(k = 1;k <= n;++ k)
				ans.a[i][j] = (ans.a[i][j] + x.a[i][k] * y.a[k][j] % p) % p;
	return ans;
}

inline node ksm(node x,ll b)
{
	node ans;
	for(register int i = 1;i <= n;++ i)
		ans.a[i][i] = 1;
	while(b)
	{
		if(b & 1) ans = mul(x,ans);
		x = mul(x,x);
		b >>= 1;
	}
	return ans;
}

int main()
{
	long long k;
	register int i,j;
	read(n),read(k);
	for(i = 1;i <= n;++ i)
		for(j = 1;j <= n;++ j)
			read(A.a[i][j]);
	A = ksm(A,k);
	for(i = 1;i <= n;++ i)
	{
		for(j = 1;j <= n;++ j)
			printf("%lld ",A.a[i][j]);	
		puts("");	
	}
	return 0;
}
