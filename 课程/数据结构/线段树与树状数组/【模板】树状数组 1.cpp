#include<cstdio>
int c[500001],n,m;
inline int lowbit(int k)
{
	return k&(-k);
}

void add(int k,int x)
{
	for(int i=k;i<=n;i+=lowbit(i))
		c[i]+=x;
}

int query(int pos)
{
	int ret=0,i;
	for(i=pos;i>=1;i-=lowbit(i))
		ret+=c[i];
	return ret;
}

int main()
{
	int x,k,i,o;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&o);	
		add(i,o);	
	}
	for(i=1;i<=m;i++)
	{
		scanf("%d%d%d",&o,&x,&k);
		if(o==1) add(x,k);
		else printf("%d\n",query(k) - query(x-1));
	}
	return 0;
}
