#include<cstdio>
#define N 100005
int h[N],f[N][2];
inline void read(int &x)
{
	x = 0;char ch = getchar();
	while(ch > '9' || ch < '0') ch = getchar();
	while(ch <= '9'&&ch >= '0') {x = x * 10 + (ch ^ 48);ch = getchar();}
}

int main()
{
	int n;
	register int i;
	read(n);
	for(i = 1;i <= n;++ i)
		read(h[i]);
	f[1][0] = f[1][1] = 1;
	for(i = 2;i <= n;++ i)
	{
		if(h[i] > h[i - 1]) f[i][0] = f[i - 1][1] + 1,f[i][1] = f[i - 1][1];
		else if(h[i] < h[i - 1]) f[i][1] = f[i - 1][0] + 1,f[i][0] = f[i - 1][0];
		else f[i][1] = f[i - 1][1],f[i][0] = f[i - 1][0];
	}
	printf("%d",f[n][0] > f[n][1] ? f[n][0] : f[n][1]);
	return 0;
}
