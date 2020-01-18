#include<cstdio>
#include<cstring>
#include<algorithm>
#define min(x,y) ((x) < (y) ? (x) : (y))
using std::sort;
bool w[1000005];
int stone[105],f[1000005];
inline void read(int &x)
{
	x = 0;char ch = getc(stdin);
	while(ch < '0' || ch > '9') ch = getc(stdin);
	while(ch >= '0'&&ch <= '9') {x = x * 10 + (ch ^ 48);ch = getc(stdin);}
}

int main()
{
	int l,s,t,m,n = 0,ans = 0x7f7f7f7f;
	register int i,j;
	memset(f,0x7f,sizeof f);
	read(l),read(s),read(t),read(m);
	for(i = 1;i <= m;++ i)
		read(stone[i]);
	sort(stone + 1,stone + m + 1);
	if(s == t)
	{
		int cnt = 0;
		for(i = 1;i <= m;++ i)
			if(stone[i] % s == 0)
				++ cnt;
		printf("%d\n",cnt);
		return 0;
	}
	for(i = 1;i <= m;++ i)
	{
		if(stone[i] - stone[i - 1] > 71)
			n += (stone[i] - stone[i - 1]) % 71 + 71;
		else 
			n += (stone[i] - stone[i - 1]);
		w[n] = 1;		
	}
	if(l - stone[m] > 71)
		n += (l - stone[m]) % 71 + 71;
	else 
		n += (l - stone[m]);
	f[0] = 0;
	for(i = s;i <= n + t - 1;++ i)
		for(j = s;j <= t;++ j)
			if(i - j >= 0)
				f[i] = min(f[i],f[i - j]) + w[i];
	for(i = n;i <= n + t - 1;++ i)
		ans = min(ans,f[i]);
	printf("%d\n",ans);
	return 0;
}
