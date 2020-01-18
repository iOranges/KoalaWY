#include<cstdio>
int h[100005],d[100005];
inline void read(int &x)
{
	x = 0;char ch = getc(stdin);
	while(ch > '9' || ch < '0') ch = getc(stdin);
	while(ch <= '9'&&ch >= '0') {x = x * 10 + (ch ^ 48);ch = getc(stdin);}
}

int main()
{
	int n;
	read(n);
	register int i;
	for(i = 1;i <= n;++ i)
	{
		read(h[i]);
		d[i] = h[i] - h[i - 1];
	}
	d[n + 1] = - h[n];
	int s1 = 0,s2 = 0;
	for(i = 1;i <= n + 1;++ i)
		if(d[i] > 0) s1 += d[i];
		else s2 -= d[i];
	printf("%d",s1 > s2 ? s2 : s1);
	return 0;
}
