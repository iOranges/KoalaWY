#include<cstdio>
#include<cstring>
int c[100001],n;
int inline lowbit(int k)
{
	return k&-k;
}

void add(int k,int x)
{
	for(int i=k;i<=n;i+=lowbit(i))
		c[i] += x;
}

int query(int pos)
{
	int ret=0,i;
	for(i=pos;i>0;i-=lowbit(i))
		ret+=c[i];
	return ret;
}

int main()
{
	int i,a,b;
	while(scanf("%d",&n))
	{
		if(n==0) break;
		memset(c,0,sizeof c);
		for(i=1;i<=n;i++)
		{
			scanf("%d%d",&a,&b);
			add(a,1),add(b+1,-1);
		}
		printf("%d",query(1));
		for(i=2;i<=n;i++)
			printf(" %d",query(i));
		printf("\n");
	}
	return 0;
}
