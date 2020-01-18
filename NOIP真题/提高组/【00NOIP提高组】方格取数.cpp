#include<cstdio>
#define ll long long
#define max(x,y) ((x) > (y) ? (x) : (y))
int w[11][11];
ll f[11][11][21];
template <typename e>inline void read(e &x)
{
	x = 0;char ch = getc(stdin);
	while(ch > '9' || ch < '0') ch = getc(stdin);
	while(ch <= '9'&&ch >= '0') {x = x * 10 + (ch ^ 48);ch = getc(stdin);}
}

int main()
{
	int n,a,b,c;
	register int i,j,k;
	read(n);
	while(true)
	{
		read(a),read(b),read(c);
		if(a == 0&&b == 0&&c == 0)
			break;	
		w[a][b] = c;	
	}
	f[1][1][0] = w[1][1];
	for(k = 1;k <= 2 * n;++ k)
		for(i = 1;i <= n;++ i)
			for(j = 1;j <= n;++ j)		
			{
			//	if(i + j - k - 2 > 0) break;
				ll v = w[i][k-i+2] + w[j][k-j+2];
				if(i == j) v /= 2;
				f[i][j][k] = max(f[i][j][k],max(f[i-1][j-1][k-1],max(f[i-1][j][k-1],max(f[i][j-1][k-1],f[i][j][k-1]))) + v);
			}
	printf("%lld",f[n][n][2 * n]);
	return 0;
}
