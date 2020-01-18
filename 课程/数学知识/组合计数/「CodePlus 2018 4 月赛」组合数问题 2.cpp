#include<map>
#include<cmath>
#include<queue>
#include<cstdio>
using std::map;
using std::priority_queue;
const long long p = 1e9 + 7;
int n,k;
double logfac[1000005],eps = 1e-12;
long long fac[1000005],inv[1000005],ans;
struct node{
	double lg;
	int n,m;
	node(double lgC,int x,int y) :lg(lgC),n(x),m(y) {}
	bool operator < (const node b) const{
		return lg - b.lg < eps;
	}
};
struct point{
	int x,y;
	point(node b) :x(b.n),y(b.m) {}
	bool operator < (const point b) const{
		return x != b.x ? x < b.x : y < b.y;
	}
};
map<point,bool> mp;
priority_queue<node> q;
long long ksm(long long a,long long b)
{
	long long ans = 1;
	while(b)
	{
		if(b & 1) ans = a * ans % p;
		a = a * a % p;
		b >>= 1;
	}
	return ans;
}

inline long long C(int n,int m)
{
	return fac[n] * inv[m] % p * inv[n - m] % p;
}

inline double logC(int n,int m)
{
	return logfac[n] - logfac[m] - logfac[n - m];
}

void work()
{
	node t(logC(n,n/2),n,n/2);
	q.push(t);
	mp[point(t)] = true;
	while(!q.empty())
	{
		node u = q.top();
		q.pop();-- k;
		ans = (ans + C(u.n,u.m)) % p;
		if(u.m < n&&u.m < u.n)
		{
			t = node(logC(u.n,u.m + 1),u.n,u.m + 1);
			if(!mp[point(t)])
			{
				q.push(t);
				mp[point(t)] = true;	
			}			
		}
		if(u.m > 1)
		{
			t = node(logC(u.n,u.m - 1),u.n,u.m - 1);
			if(!mp[point(t)])
			{
				q.push(t);
				mp[point(t)] = true;	
			}
		}		
		if(u.n > 1)
		{
			t = node(logC(u.n - 1,u.m),u.n - 1,u.m);
			if(!mp[point(t)])
			{
				q.push(t);
				mp[point(t)] = true;	
			}
		}		
		if(k == 0) break;
	}
}

int main()
{
	scanf("%d %d",&n,&k);
	fac[0] = inv[0] = 1;
	register int i;
	for(i = 1;i <= n;++ i)
		fac[i] = fac[i - 1] * i % p;
	inv[n] = ksm(fac[n],p - 2);
	for(i = n - 1;i >= 1;-- i)
		inv[i] = inv[i + 1] * (i + 1) % p;
	for(i = 1;i <= n;++ i)
		logfac[i] = logfac[i - 1] + log(i);
	work();
	printf("%lld",ans);
	return 0;
}
