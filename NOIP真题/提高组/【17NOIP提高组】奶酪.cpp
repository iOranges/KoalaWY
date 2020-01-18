#include<cmath>
#include<cstdio>
struct point{
	int x,y,z;	
}p[1005];
int f[1005];
template <typename e>inline void read(e &x)
{
	x = 0;int f = 1;char ch = getc(stdin);
	while(ch > '9' || ch < '0') {if(ch == '-') f = - 1;ch = getc(stdin);}
	while(ch <= '9'&&ch >= '0') {x = x * 10 + (ch ^ 48);ch = getc(stdin);}
	x *= f;
}

inline long long pf(int x)
{
	return x * 1ll * x;
}

inline double calc(point a,point b)
{
	return sqrt(pf(a.x - b.x) + pf(a.y - b.y) + pf(a.z - b.z));
}

int find(int x)
{
	return x == f[x] ? f[x] : f[x] = find(f[x]); 
}

inline void marge(int a,int b)
{
	a = find(a),b = find(b);
	if(a != b) f[a] = b;
}

int main()
{
	int t,n,h,r;
	register int i,j;
	read(t);
	while(t --)
	{
		read(n),read(h),read(r);
		for(i = 1;i <= n;++ i)
			read(p[i].x),read(p[i].y),read(p[i].z);
		for(i = 0;i <= n + 1;++ i) f[i] = i;
		for(i = 1;i <= n;++ i)
		{
			if(p[i].z - r <= 0) marge(i,0);	
			if(p[i].z + r >= h)	marge(i,n + 1);	
		}
		for(i = 1;i <= n;++ i)
			for(j = i + 1;j <= n;++ j)
				if(calc(p[i],p[j]) <= 2.0 * r)
					marge(i,j);
		puts(find(0) == find(n + 1) ? "Yes" : "No");
	}
	return 0;
}
