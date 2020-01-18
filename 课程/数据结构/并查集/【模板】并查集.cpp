#include<cstdio>
#define N 10005
#define swap(x,y) (x ^= y ^= x ^= y)
#define SIZE 1 << 20
int f[N],siz[N];
char buf[SIZE],*S = buf,*T = buf;
inline char gc() {return S == T && (T = (S = buf) + fread(buf,1,SIZE,stdin),S == T) ? -1 : *S++;}
#define getc(stdin) gc()
inline void read(int &x)
{
	x = 0;char ch = getc(stdin);
	while(ch > '9' || ch < '0') ch = getc(stdin);
	while(ch <= '9'&&ch >= '0') {x = x * 10 + (ch ^ 48);ch = getc(stdin);}
}

int find(int x)
{
	return x == f[x] ? f[x] : f[x] = find(f[x]);
}

inline void marge(int a,int b)
{
	a = find(a),b = find(b);
	if(a == b) return;
	if(siz[a] < siz[b]) swap(a,b);
	f[b] = a,siz[a] += siz[b];
}

int main()
{
	int n,m,a,b,opt;
	register int i;
	read(n),read(m);
	for(i = 1;i <= n;++ i) f[i] = i;
	for(i = 1;i <= m;++ i)
	{
		read(opt),read(a),read(b);
		if(opt ^ 1)
			putchar(find(a) == find(b) ? 'Y' : 'N'),putchar('\n');
		else
			marge(a,b);
	}
	return 0;
}
