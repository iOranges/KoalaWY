#include<cstdio>
#include<cstring>
#define ll long long
const ll p = 1000000007;
ll A[3][3] = 
{{0,0,0},
{0,1,0},
{0,0,0}},
B[3][3] = 
{{0,0,0},
{0,1,1},
{0,1,0}};
inline void mul(ll x[3][3],ll y[3][3])
{
	ll ans[3][3];
	memset(ans,0,sizeof ans);
	register int i,j,k;
	for(i = 1;i <= 2;++ i)
		for(j = 1;j <= 2;++ j)
			for(k = 1;k <= 2;++ k)	
				ans[i][j] = (ans[i][j] + x[i][k] * y[k][j] % p) % p;
	for(i = 1;i <= 2;++ i)
		for(j = 1;j <= 2;++ j)
			x[i][j] = ans[i][j];
}

inline void ksm(ll x[3][3],ll b)
{
	ll ans[3][3];
	register int i,j;
	memset(ans,0,sizeof ans);
	for(i = 1;i <= 2;++ i) ans[i][i] = 1;
	while(b)
	{
		if(b & 1) mul(ans,x);
		mul(x,x);
		b >>= 1;
	}
	for(i = 1;i <= 2;++ i)
		for(j = 1;j <= 2;++ j)
			x[i][j] = ans[i][j];
}

int main()
{
	ll n;
	scanf("%lld",&n);
	ksm(B,n - 1);
	mul(A,B);
	printf("%lld",A[1][1]);
	return 0;
}
