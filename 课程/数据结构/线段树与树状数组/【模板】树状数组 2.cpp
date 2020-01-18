#include<cstdio>
int c[500001],d[500001],n,m;
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
	int x,k,i,o,a,b,j;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&d[i]);	
		add(i,d[i]-d[i-1]);	
	}
	for(i=1;i<=m;i++)
	{
		scanf("%d",&o);
		if(o==1) 
		{
			scanf("%d%d%d",&a,&b,&k);
			add(a,k),add(b+1,(-k));
		}
		else
		{
			scanf("%d",&x);
			printf("%d\n",query(x));
		} 
	}
	return 0;
}
