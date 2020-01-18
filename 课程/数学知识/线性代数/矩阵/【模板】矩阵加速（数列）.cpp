#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
const ll p = 1e9+7;
using std::sort;
ll E[4][4]= 
{{0,0,0,0},
{0,1,1,0},
{0,0,0,1},
{0,1,0,0}},
A[4][4] =
{{0,0,0,0},
{0,1,0,0},
{0,0,0,0},
{0,0,0,0}};
struct query{
	int n,i;
	bool operator < (const query b) const{
		return n < b.n;
	}
}q[105];
template <typename e>inline void read(e &x)
{
	x = 0;char ch = getc(stdin);
	while(ch > '9' || ch < '0') ch = getc(stdin);
	while(ch <= '9'&&ch >= '0') {x = x * 10 + (ch ^ 48);ch = getc(stdin);}
}
ll res[105];
inline void mul(ll x[4][4],ll y[4][4],int num)
{
	ll ans[4][4];
	memset(ans,0,sizeof ans);
	register int i,j,k;
	for(i = 1;i <= 3;++ i)
		for(j = 1;j <= 3;++ j)
			for(k = 1;k <= 3;++ k)
				ans[i][j] = (ans[i][j] + x[i][k] * y[k][j] % p) % p;
	if(num)
		res[num] = ans[1][1];
	else
		for(i = 1;i <= 3;++ i)
			for(j = 1;j <= 3;++ j)
				x[i][j] = ans[i][j];	
}

inline void ksm(ll x[4][4],int b)
{
	ll ans[4][4];
	memset(ans,0,sizeof ans);
	register int i,j;
	for(i = 1;i <= 3;++ i)
		ans[i][i] = 1;
	while(b)
	{
		if(b & 1) mul(ans,x,0);
		mul(x,x,0);
		b >>= 1;
	}
	for(i = 1;i <= 3;++ i)
		for(j = 1;j <= 3;++ j)
			x[i][j] = ans[i][j];
}

inline void memE()
{
	memset(E,0,sizeof E);
	E[1][1] = E[1][2] = E[2][3] = E[3][1] = 1;
}

int main()
{
	int t;
	register int i;
	read(t);
	for(i = 1;i <= t;++ i)
		read(q[i].n),q[i].i = i;
	sort(q + 1,q + t + 1);
	for(i = 1;i <= t;++ i)
	{
		memE();
		ksm(E,q[i].n - 1);
		mul(A,E,q[i].i);
	}
	for(i = 1;i <= t;++ i)
		printf("%lld\n",res[i]);
	return 0;
}
