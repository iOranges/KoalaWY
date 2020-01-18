#include<cstdio>
#include<cstring>
int c[5001],a[5001],n;

int lowbit(int k)
{
	return k&(-k);
}

void add(int x)
{
	for(int i=x;i<=n;i+=lowbit(i))
		c[i]++;
}

int query(int pos)
{
	int ret = 0;
	for(int i=pos;i>=1;i-=lowbit(i))
		ret += c[i];
	return ret;
}

int main()
{
	while(scanf("%d",&n)==1)
	{
		memset(c,0,sizeof c);
		int i,j;
		long long ans = 0,minn;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);		
			add(a[i]+1);
			ans += i-query(a[i]+1);
		}
		minn = ans;
		for(i=1;i<=n;i++)
		{ 
			ans += (n-1-a[i]) - a[i];
			if(ans<minn) minn = ans;
		}
		printf("%lld\n",minn);		
	}
	return 0; 
}

