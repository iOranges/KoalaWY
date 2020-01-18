#include<cstdio>
#define SIZ 1<<10 
const int mod = (1 << 30) - 1,N = 4e7 + 5,M = 1e5 + 5;
int pre[N],q[N],b[N],l[M],r[M],p[M];
long long s[N];
char buf[SIZ],*S = buf,*T = buf;
inline char gc() {return S == T&&(T = (S = buf) + fread(buf,1,SIZ,stdin),T == S) ? -1 : *(S++);}
#define getchar() gc()
inline void read(int &x)
{
	x = 0;char ch = getchar();
	while(ch > '9' || ch < '0') ch = getchar();
	while(ch <= '9'&&ch >= '0') {x = x * 10 + (ch ^ 48);ch = getchar();}
}

void print(__int128 x)
{
	static int stack[2000];int top = 0;
	while(x)
	{
		stack[++ top] = x % 10;
		x /= 10;
	}
	while(top) putchar(stack[top --] + '0');
}

int main()
{
	int n,type,a,m,x,y,z,nw;
	register int i,head = 1,tail = 1,j;
	read(n),read(type);
	if(type)
	{
		read(x),read(y),read(z),read(b[1]),read(b[2]),read(m);
		for(i = 1;i <= m;++ i) read(p[i]),read(l[i]),read(r[i]);
		for(i = 3;i <= n;++ i) b[i] = (((x * 1ll * b[i - 1]) & mod) + ((y * 1ll * b[i - 2]) & mod) + z) & mod;
		for(i = 1;i <= m;++ i)
			for(j = p[i - 1] + 1;j <= p[i];++ j)
				s[j] = s[j - 1] + (b[j] % (r[i] - l[i] + 1)) + l[i];
	}
	else for(i = 1;i <= n;++ i)
		read(a),s[i] = s[i - 1] + a;
	for(i = 1;i <= n;++ i)
	{
		while(tail - head > 0&&(s[q[head + 1]] << 1) - s[pre[q[head + 1]]] <= s[i]) ++ head;
		pre[i] = q[head];
		while(head <= tail&&(s[i] << 1) - s[pre[i]] <= (s[q[tail]] << 1) - s[pre[q[tail]]]) -- tail;
		q[++ tail] = i;
	}
	__int128 ans = 0,t;nw = n;
	while(nw) {
		t = s[nw] - s[pre[nw]];
		ans += t * t;
		nw = pre[nw];
	}
	print(ans); 
	return 0; 
}

