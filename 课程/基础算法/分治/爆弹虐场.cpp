#include<cstdio>
#include<algorithm>
#define max(x,y) ((x)>(y)?(x):(y))
#define min(x,y) ((x)<(y)?(x):(y))
using std::sort;
int n,k,m;
struct node{
	int fr,to,w,v;
}e[20005];
int f[10005];
bool cmp(node a,node b)
{
	return a.w < b.w;
}

int find(int x)
{
	if(x!=f[x]) f[x] = find(f[x]);
	return f[x];
}

bool check_(int a,int b)
{
	a = find(a),b = find(b);
	if(a!=b)
	{
		f[a] = b;
		return true;
	}
	return false;
}

bool check(int mid)
{
	register int i,tot=0,cnt=0;
	for(i=1;i<=n;i++) f[i] = i;
	for(i=1;i<=m;i++)
		if(mid >= min(e[i].w,e[i].v))
			if(check_(e[i].fr,e[i].to))
			{
				if(e[i].w <= mid)
					cnt ++;
				tot ++;
				if(tot == n - 1)
					break;
			}
	if(tot < n - 1) return false;
	if(cnt < k) return false;
	return true;
}

int main()
{
	int i,l = 0x7fffffff,r = 0,mid;
	scanf("%d%d%d",&n,&k,&m);
	for(i=1;i<=m;i++)
	{
		scanf("%d%d%d%d",&e[i].fr,&e[i].to,&e[i].w,&e[i].v);
		l = min(l,e[i].w),r = max(r,e[i].w);		
	}
	sort(e+1,e+m+1,cmp);
	while(l<=r)
	{
		mid = (l + r) >> 1;
		if(check(mid))
			r = mid - 1;
		else
			l = mid + 1;
	}
	printf("%d",l);
	return 0;
}
