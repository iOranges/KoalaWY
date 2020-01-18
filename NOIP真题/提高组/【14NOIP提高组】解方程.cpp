#include<cstdio>
const int p = 19260817;
int ans[1000005],top,a[105],sum;
#define SIZE 1<<20
char buf[SIZE],*S = buf,*T = buf;
inline char gc() {return S == T && (T = (S = buf) + fread(buf,1,SIZE,stdin),S == T) ? -1 : *S++;}
#define getc(stdin) gc()
template <typename e> inline void read(e &x)
{
	x = 0;char ch = getc(stdin);int f = 1;
	while(ch > '9' || ch < '0') {if(ch == '-') f = -1;ch = getc(stdin);}
	while(ch <= '9'&&ch >= '0') {x = (x * 10 + (ch ^ 48)) % p;ch = getc(stdin);}
	x *= f;
}

inline void write(int x)
{
	int tot = 0;
	static int s[25];
	if(!x) putchar('0');
	else{
		while(x)
		{
			s[++ tot] = x % 10;
			x /= 10;
		}
		for(register int i = tot;i >= 1;-- i)
			putchar('0' + s[i]);
	}
	putchar('\n');
}

int main()
{
	int n,m;
	read(n),read(m);
	register int i,j;
	for(i = 0;i <= n;++ i)
		read(a[i]);
	for(i = 1;i <= m;++ i)
	{
		sum = a[n];
		for(j = n - 1;j >= 0;-- j)
			sum = (sum * i % p + a[j]) % p;
		if(sum == 0) ans[++ top] = i;
	}
	write(top);
	for(i = 1;i <= top;++ i)
		write(ans[i]);
	return 0;
}
