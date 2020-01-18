#include<cmath>
#include<cstdio>
#include<cstring>
#define N 200005
#define max(x,y) ((x) > (y) ? (x) : (y))
#define min(x,y) ((x) < (y) ? (x) : (y))
int l[505],r[505],num[N],n,maxx[505],v[N];

void build()
{
	register int i;
	int block = sqrt(n);
	int cnt = n / block;
	if(n % block) ++cnt;
	for(i = 1;i <= cnt;++ i)
	{
		l[i] = (i - 1) * block + 1;
		r[i] = i * block;
	}
	r[cnt] = n;
	for(i = 1;i <= n;++ i)
	{
		num[i] = (i - 1) / block + 1;	
		maxx[num[i]] = max(maxx[num[i]],v[i]);
	}
}

int query(int a,int b)
{
	register int i;
	int ans = -1;
	for(i = a;i <= min(r[num[a]],b);++ i)
		ans = max(v[i],ans);
	if(num[a] != num[b])
		for(i = l[num[b]];i <= b;++ i)
			ans = max(v[i],ans);
	for(i = num[a] + 1;i < num[b];++ i)
		ans = max(ans,maxx[i]);
	return ans;
}

int main()
{
	char ch[10];
	register int i;
	int m,a,b;
	while(~scanf("%d%d",&n,&m))
	{
		memset(maxx,0,sizeof maxx);
		for(i = 1;i <= n;++ i)
			scanf("%d",&v[i]);
		build();
		for(i = 1;i <= m;++ i)
		{
			scanf("%s%d%d",ch,&a,&b);
			if(ch[0] == 'U'&&v[a] < b)
			{
				v[a] = b;
				maxx[num[a]] = max(maxx[num[a]],b);
			}
			else if(ch[0] == 'Q')
				printf("%d\n",query(a,b));
		}
	}
	return 0;
}
