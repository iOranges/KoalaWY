#include<map>
#include<cmath>
#include<cstdio>
#include<iostream>
#include<unordered_map>
#define ll long long
using std::unordered_map;
unordered_map<ll,int> hash;
ll gcd(ll a,ll b)
{
	return b == 0 ? a : gcd(b,a%b);
}

void exgcd(ll a,ll b,ll &x,ll &y)
{
    if(b == 0)
    {
        x = 1,y = 0;
        return ;
    }
    exgcd(b,a%b,x,y);
    ll z = x;
    x = y;
    y = z - a/b * y;
}

ll inv(ll a,ll b)
{
    ll x,y;
    exgcd(a,b,x,y);
    return (x%b + b) % b;
}

ll ksm(ll a,ll b,ll p)
{
	ll ans = 1;
	while(b)
	{
		if(b & 1) ans = (a * ans) % p;
		a = (a * a) % p;
		b >>= 1; 
	}
	return ans;
}

int BSGS(ll a,ll b,ll p)
{
	hash.clear();
	int s = ceil(sqrt(p));
    b %= p;
	register int i;
	for(i = 1;i <= s;++ i)
	{
		b = b * a % p;
		hash[b] = i;
	}
	long long t = 1;
	b = ksm(a,s,p);
	for(i = 1;i <= s;++ i)
	{
		t = t * b % p;
		if(hash[t]) return (i * 1ll * s - hash[t] + p) % p;
	}
	return -1;
}

int EXBSGS(ll a,ll b,ll p)
{
	if(b == 1||p == 1) return 0;
	ll g = gcd(a,p),sa = 1;int k = 0,f;
	while(g != 1)
	{
		if(b % g != 0) return -1;
		++ k;b /= g,p /= g;
		sa = sa * (a / g) % p;
		if(b == sa) return k;
		g = gcd(a,p);
	}
	f = BSGS(a,b * inv(sa,p) % p,p);
	if(f == -1) return -1;
	return f + k;
}

int main()
{
	int a,b,p,f;
	while(scanf("%d%d%d",&a,&p,&b))
	{
		if(!a&&!b&&!p) break;
		f = EXBSGS(a,b,p);
		if(f == -1)
			printf("No Solution\n");
		else printf("%d\n",f);
	}
	return 0;
 } 
