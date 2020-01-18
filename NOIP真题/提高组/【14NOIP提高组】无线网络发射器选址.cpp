#include<cstdio>
#define min(x,y) ((x) < (y) ? (x) : (y))
#define max(x,y) ((x) > (y) ? (x) : (y))
int s[130][130];
inline void read(int &x)
{
	x = 0;char ch = getc(stdin);
	while(ch > '9' || ch < '0') ch = getc(stdin);
	while(ch <= '9'&&ch >= '0') {x = x * 10 + (ch ^ 48);ch = getc(stdin);}
}

int main()
{
	int n,d,a,b;
	read(d),read(n);
	register int i,j,x,y;
	for(i = 1;i <= n;++ i)
	{
		read(a),read(b);
		read(s[a][b]);
	}
	int ans = 0,cnt = 0;
	for(i = 0;i <= 128;++ i)
		for(j = 0;j <= 128;++ j)
		{
			int res = 0;
			for(x = max(0,i - d);x <= min(128,i + d);++ x)
				for(y = max(0,j - d);y <= min(128,j + d);++ y)
					res += s[x][y];
			if(res == ans) ++ cnt;
			else if(res > ans) ans = res,cnt = 1;
		}
	printf("%d %d\n",cnt,ans);
	return 0;
}
