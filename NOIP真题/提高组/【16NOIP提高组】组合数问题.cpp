#include<cstdio>
#define min(x,y) ((x) < (y) ? (x) : (y))
#define max(x,y) ((x) > (y) ? (x) : (y))
int C[2005][2005],cnt[2005][2005],q[10005][2]; 
inline void read(int &x)
{
	x = 0;char ch = getc(stdin);
	while(ch > '9' || ch < '0') ch = getc(stdin);
	while(ch <= '9'&&ch >= '0') {x = x * 10 + (ch ^ 48);ch = getc(stdin);}
}

int main()
{
	int t,p,n = 0,m = 0;
	read(t),read(p);
	register int i,j,k;
	for(i = 1;i <= t;++ i)
	{
		read(q[i][0]),read(q[i][1]);
		n = max(n,q[i][0]),m = max(m,q[i][1]);
	}
	C[0][0] = 1;
	for(i = 1;i <= n;++ i)
	{
		C[i][0] = 1;
		for(j = 1;j <= min(i,m);++ j)
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % p;
		for(j = 1;j <= m;++ j)
		{
			cnt[i][j] = cnt[i - 1][j] + cnt[i][j - 1] - cnt[i - 1][j - 1]; 
			if(C[i][j] == 0&&j <= i) ++ cnt[i][j];			
		}
	}
	for(i = 1;i <= t;++ i)
		printf("%d\n",cnt[q[i][0]][q[i][1]]);
	return 0;
}
