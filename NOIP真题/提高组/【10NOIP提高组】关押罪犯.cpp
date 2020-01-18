#include<cstdio>
#include<algorithm>
using std::sort;
struct node{
	int fr,to,v;
	bool operator < (const node b) const{
		return v > b.v;
	}
}e[100005];
int f[20005],siz[20005],p[20005];
int find(int x)
{
	return f[x] != x ? f[x] = find(f[x]) : f[x];
}

inline void marge(int a,int b)
{
	if(siz[a] > siz[b]) f[b] = a,siz[a] += siz[b];
	else f[a] = b,siz[b] += siz[a];
}

int main()
{
	int n,m,a,b;
	scanf("%d%d",&n,&m);
	register int i;
	for(i = 1;i <= n;++ i) f[i] = i,siz[i] = 1;
	for(i = 1;i <= m;++ i)
		scanf("%d%d%d",&e[i].fr,&e[i].to,&e[i].v);
	sort(e + 1,e + m + 1);
	for(i = 1;i <= m;++ i)
	{
		a = find(e[i].fr),b = find(e[i].to);
		p[a] = find(p[a]),p[b] = find(p[b]);
		if(a == b||(p[b] == p[a]&&p[b])) 
		{
			printf("%d",e[i].v);
			return 0;
		}
		if(p[b]) 	marge(a,p[b]);	
		else p[b] = a;
		if(p[a])	marge(b,p[a]);
		else p[a] = b;
	}
	printf("0");
	return 0;
}

