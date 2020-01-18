#include<cstdio>
int a[105];
inline void read(int &x)
{
	x = 0;char ch = getc(stdin);
	while(ch < '0' || ch > '9') ch = getc(stdin);
	while(ch <= '9'&&ch >= '0') {x = x * 10 + (ch ^ 48);ch = getc(stdin);}
}

int main()
{
	int n,sum = 0,cnt = 0;
	register int i,j;
	read(n);
	for(i = 1;i <= n;++ i)
	{
		read(a[i]);
		sum += a[i];
	}
	sum /= n;
	for(i = 1;i <= n;++ i)
		a[i] -= sum;
	i = 1,j = n;
	while(a[i] == 0&&i <= n) ++ i;
	while(a[j] == 0&&j >= 1) -- j;
	while(i < j)
	{
		a[i + 1] += a[i];
		a[i] = 0;
		++ cnt;
		while(a[i] == 0&&i < j) ++ i;
	}
	printf("%d",cnt);
	return 0;
}
