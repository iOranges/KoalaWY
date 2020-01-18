#include<cstdio> 
#define SIZE 1 << 20
#define N 100005
#define max(x,y) ((x) > (y) ? (x) : (y))
int maxx[N][17],lg[N],n,pw[20];
char buf[SIZE],*S = buf,*T = buf;
inline char gc() {return S == T && (T = (S = buf) + fread(buf,1,SIZE,stdin),S == T) ? -1 : *S++;}
//#define getc(stdin) gc()
inline void read(int &x)
{
	x = 0;char ch = getc(stdin);
	while(ch > '9' || ch < '0') ch = getc(stdin);
	while(ch <= '9'&&ch >= '0') {x = x * 10 + (ch ^ 48);ch = getc(stdin);}
}

void build_st()
{
	register int i,j;
	for(j = 1;j <= lg[n];++ j)
		for(i = 1;i + pw[j] - 1 <= n;++ i)
			maxx[i][j] = max(maxx[i][j - 1],maxx[i + pw[j - 1]][j - 1]);
}

inline int ask(int l,int r)
{
	int x = lg[r - l + 1];
	return max(maxx[l][x],maxx[r - pw[x] + 1][x]);
}

int main()
{
	int m,l,r;
	read(n),read(m);
	register int i;
	lg[1] = 0;
	for(i = 2;i <= n;++ i)
		lg[i] = lg[i / 2] + 1;
	pw[0] = 1;
	for(i = 1;i <= lg[n];++ i)
		pw[i] = pw[i - 1] * 2;
	for(i = 1;i <= n;++ i)
		read(maxx[i][0]);
	build_st();
	for(i = 1;i <= m;++ i)
	{
		read(l),read(r);
		printf("%d\n",ask(l,r));
	}
	return 0;
}
