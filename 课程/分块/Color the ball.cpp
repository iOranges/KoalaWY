#include<cmath>
#include<cstdio>
#include<cstring>
#define N 100005
#define min(x,y) ((x)<(y)?(x):(y))
int l[350],r[350],num[N],v[N],lzy[N],n;

void build()
{
	register int i;
	int block = sqrt(n);
	int cnt = n / block;
	if(n % block) ++ cnt;
	for(i = 1;i <= cnt;++ i)
	{
		l[i] = (i - 1) * block + 1;
		r[i] = i * block;
	}
	r[cnt] = n;
	for(i = 1;i <= n; ++ i)
		num[i] = (i - 1) / block + 1;
}

void add(int a,int b)
{
	register int i;
	for(i = a;i <= min(b,r[num[a]]);++ i)
		v[i] ++;
	if(num[a]!=num[b])
		for(i = l[num[b]];i <= b;++ i)
			v[i] ++;
	for(i = num[a] + 1;i < num[b];++ i)
		lzy[i] ++;
}

int main()
{
	int a,b;
	register int i;
	while(~scanf("%d",&n))
	{
		if(!n) break;
		memset(v,0,sizeof v);
		memset(lzy,0,sizeof lzy);
		build();
		for(i = 1;i <= n;++ i)
		{
			scanf("%d%d",&a,&b);
			add(a,b);
		}
		printf("%d",v[1] + lzy[num[1]]);
		for(i = 2;i <= n;++ i)
			printf(" %d",v[i] + lzy[num[i]]);
		printf("\n");
	}
	return 0;
}
