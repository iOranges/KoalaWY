#include<cstdio>
#define max(x,y) ((x) > (y) ? (x) : (y))
int a[2000010],q[2000010];

inline void read(int &x)
{
	x = 0;char ch = getc(stdin);
	while(ch > '9' || ch < '0') ch = getc(stdin);
	while(ch <= '9'&&ch >= '0') {x = x * 10 + (ch ^ 48);ch = getc(stdin);}
}

int main()
{
//	freopen("input","r",stdin); 
	int n,ans = 0;
	register int i,l = 1,r = 0;
	read(n);
	for(i = 1;i <= n;++ i)
		read(a[i]),a[i + n] = a[i];
	for(i = 1;i <= 2 * n;++ i)
	{
		while(l <= r&&i - q[l] > n / 2) ++ l;
		ans = max(ans,a[i] + i + a[q[l]] - q[l]);
		while(l <= r&&a[q[r]] - q[r] < a[i] - i) -- r;
		q[++ r] = i;
	}
	printf("%d",ans); 
	return 0;
 }
