#include<cstdio>
#include<algorithm>
const int N = 3e5 + 5;
using std::sort;
struct node{
	int v;
	bool type;
	bool operator < (const node b) const{
		return v < b.v;
	}
}e[N << 1];
inline void read(int &x)
{
	x = 0;char ch = getchar();
	while(ch > '9' || ch < '0') ch = getchar();
	while(ch <= '9'&&ch >= '0') {x = x * 10 + (ch ^ 48);ch = getchar();}
}

int main()
{
	int n,m,sr,sl;
	long long ans = 0;
	read(n),read(m);
	register int i;
	for(i = 1;i <= n;++ i)
		read(e[i].v),e[i].type = true;
	for(i = 1;i <= m;++ i)
		read(e[i + n].v),e[i + n].type = false;
	sort(e + 1,e + n + m + 1);
	bool flag = true;
	sl = n,sr = m;
	for(i = 1;i <= n + m;++ i)
	{
		if(flag)
		{
			if(e[1].type)
			{
				if(e[i].type) -- sl,ans += (m - 1) * 1ll * e[i].v;
				else flag = false,-- sr,ans += (n - 1) * 1ll * e[i].v;
			}
			else 
			{
				if(!e[i].type) -- sr,ans += (n - 1) * 1ll * e[i].v;
				else flag = false,-- sl,ans += (m - 1) * 1ll * e[i].v;
			}
		}
		else {
			if(e[i].type&&sl > 0)
				-- sl,ans += sr * 1ll * e[i].v;
			else if(!e[i].type&&sr > 0)
				-- sr,ans += sl * 1ll * e[i].v;
		}
	}
	printf("%lld",ans);
	return 0;
}

