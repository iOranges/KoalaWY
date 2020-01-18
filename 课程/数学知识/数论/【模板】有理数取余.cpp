#include<cstdio>
#define ll long long
const ll p = 19260817;
inline void read(ll &x)
{
	x = 0;char ch = getc(stdin);
	while(ch > '9' || ch < '0') ch = getc(stdin);
	while(ch <= '9'&&ch >= '0') {x = ((x * 10) % p + (ch ^ 48)) % p;ch = getc(stdin);}
}

ll ksm(ll a,ll b)
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

int main()
{
	ll a,b;
	read(a),read(b);
	if(!b)
		printf("Angry!");
	else
		printf("%lld",(a * ksm(b,p-2)) % p);
	return 0;
 } 
