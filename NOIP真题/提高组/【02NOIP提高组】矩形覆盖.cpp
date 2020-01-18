#include<cstdio>
#include<cstring>
#include<algorithm>
#define min(x,y) ((x) < (y) ? (x) : (y))
#define max(x,y) ((x) > (y) ? (x) : (y))
using std::sort;
inline void read(int &x)
{
	x = 0;char ch = getc(stdin);
	while(ch < '0' || ch > '9') ch = getc(stdin);
	while(ch >= '0'&&ch <= '9') {x = x * 10 + (ch ^ 48);ch = getc(stdin);}
}
int n,m,ans = 0x7f7f7f7f,s[51][51],f[51][5];
struct node{
	int x,y;
}p[55];

bool cmp1(node a,node b)
{
	return a.x != b.x ? a.x < b.x : a.y < b.y;
}

bool cmp2(node a,node b)
{
	return a.y != b.y ? a.y < b.y : a.x < b.x;
}

void work()
{
	register int i,j,k;
	for(i = 1;i <= n;++ i)
	{
		int x_1 = p[i].x,y_1 = p[i].y,x_2 = p[i].x,y_2 = p[i].y;
		for(j = i;j <= n;++ j)
		{
			x_1 = min(x_1,p[j].x),x_2 = max(x_2,p[j].x);
			y_1 = min(y_1,p[j].y),y_2 = max(y_2,p[j].y);
			s[i][j] = (x_2 - x_1) * (y_2 - y_1);
		}		
	}
	memset(f,0x7f,sizeof f);
	for(i = 1;i <= n;++ i)
		f[i][1] = s[1][i];
	for(k = 2;k <= m;++ k)
		for(i = 1;i <= n;++ i)
			for(j = k - 1;j < i;++ j)
				f[i][k] = min(f[i][k],f[j][k-1] + s[j+1][i]);
	ans = min(ans,f[n][m]);
}

int main()
{
	read(n),read(m);
	register int i;
	for(i = 1;i <= n;++ i)
		read(p[i].x),read(p[i].y);
	sort(p + 1,p + n + 1,cmp1);
	work();
	sort(p + 1,p + n + 1,cmp2);
	work();
	printf("%d",ans);
	return 0;
}
