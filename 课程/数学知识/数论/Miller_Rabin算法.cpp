#include<cstdio>
#define ll long long 
int prime[13] = {0,2,3,5,7,11,13,19,23,29,31,37,41};
inline void read(int &x)
{
	x = 0;char ch = getc(stdin);
	while(ch < '0' || ch > '9') ch = getc(stdin);
	while(ch >= '0'&&ch <= '9') {x = x * 10 + (ch ^ 48);ch = getc(stdin);}
}
ll ksm(ll a,ll b,ll p)
{
	ll ans = 1;
	while(b)
	{
		if(b&1) ans = (ans * a) % p;
		a = (a * a) % p;
		b >>= 1;
	}
	return ans;
}

bool check(ll p,ll n)
{
	if(n == 1) return false;
	if(p >= n) return true;
	if(ksm(p,n-1,n) != 1) return false;
	int s = 0,k = n - 1;
	while(!(k & 1)) k >>= 1,++ s;
	ll last = ksm(p,k,n),now;
	for(int i = 1;i <= s;++ i)
	{
		now = (last * last) % n;
		if(now == 1) return last == 1||last == n - 1;
		last = now;
	}
	return false;
}

int main()
{
	int n,m,a;
	register int i,j;
	read(n),read(m);
	for(i = 1;i <= m;++ i)
	{
		bool flag = true;
		read(a);
		for(j = 1;j <= 12;++ j)	
			if(!check(prime[j],a))
			{
				printf("No\n");
				flag = false;
				break;
			}
		if(flag) printf("Yes\n");	
	}
	return 0;
 } 
