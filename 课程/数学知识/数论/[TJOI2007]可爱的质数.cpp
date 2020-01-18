#include<map>
#include<cmath>
#include<cstdio>
#define ll long long
using std::map;
map<ll,int> h;
ll ksm(ll a,ll b,ll p)
{
	ll ans = 1;
	while(b)
	{
		if(b & 1) ans = (ans * a) % p;
		a = (a * a) % p;
		b >>= 1;
	}
	return ans;
}

int BSGS(ll a,ll b,ll p)
{
	if(b == 1||p == 1) return 0;
	b %= p;
	int s = sqrt(p);
	register int i;
	for(i = 1;i <= s;++ i)
	{
		b = b * a % p;
		h[b] = i;
	}
	ll t = 1;
	b = ksm(a,s,p);
	for(i = 1;i <= s;++ i)
	{
		t = t * b % p;
		if(h[t]) return ((i * s - h[t]) % p + p) % p;
	}
	return -1;
}

int main()
{
	int a,b,p,f;
	scanf("%d%d%d",&p,&a,&b);
	f = BSGS(a,b,p);
	if(f == -1) printf("no solution");
	else printf("%d",f);
	return 0;
 } 
