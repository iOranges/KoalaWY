#include<cstdio>
#include<cstring>
int k,w,n,k2,x;
struct ll{
	int a[205],len;
	ll()
	{
		memset(a,0,sizeof a);
		len = 0;
	}
	ll operator + (const ll other) const{
		ll t = *this,b = other;
		if(t.len < b.len)
		{
			ll temp = t;
			t = b;
			b = temp;
		}
		register int i;
		for(i = 1;i <= t.len;++ i)
		{
			t.a[i] += b.a[i];
			t.a[i + 1] += t.a[i] / 10;
			t.a[i] %= 10;
		}
		if(t.a[i]) ++ t.len;
		return t;
	}
	ll operator - (const ll other) const{
		ll t = *this,b = other;
		register int i;
		for(i = 1;i <= t.len;++ i)
		{
			t.a[i] -= b.a[i];
			if(t.a[i] < 0) -- t.a[i + 1],t.a[i] += 10;
		}
		if(!t.a[t.len]) -- t.len;
		return t;
	}
	void print()
	{
		register int i;
		for(i = len;i > 0;-- i)
			putchar(a[i] + '0');
	}
};
ll f[512],sum[512][2],ans;
void work()
{
	n = w / k;
	register int i,j,p = 0;
	sum[0][0].a[1] = 1,sum[0][0].len = 1;
	for(i = 1;i <= k2;++ i)
		sum[i][0] = sum[i - 1][0] + sum[0][0];
	sum[0][0].a[1] = 0,sum[0][0].len = 0;
	x = k2;
	for(i = 2;i <= n;++ i,-- x,p ^= 1)
		for(j = 1;j <= x;++ j)
		{
			f[j] = sum[x][p] - sum[j][p];
			sum[j][p ^ 1] = sum[j - 1][p ^ 1] + f[j];
			ans = ans + f[j];
		}
	if(w % k&&x > 0)
	{
		int k3 = (1 << (w - w / k * k)) - 1;
		if(k3 > x) k3 = x;
		for(i = 1;i <= k3;++ i)
			ans = ans + (sum[x][p] - sum[i][p]);
	}
}

int main()
{
	scanf("%d%d",&k,&w);
	k2 = 1 << k;-- k2;
	work();
	ans.print();
	return 0;
}

