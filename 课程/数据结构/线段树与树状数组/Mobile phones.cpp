#include<cstdio>
int c[1025][1025],n;
inline int lowbit(int k)
{
	return k&(-k);
}

void add(int x,int y,int o)
{
	for(int i=x;i<=n;i+=lowbit(i))
		for(int j=y;j<=n;j+=lowbit(j))
			c[i][j]+=o;
}

int query(int x,int y)
{
	int ret=0,i,j;
	for(i=x;i>0;i-=lowbit(i))
		for(j=y;j>0;j-=lowbit(j))
			ret+=c[i][j];
	return ret;
}

int main()
{
	int ch,x,y,k,a,b,o1,o2,o3,o4;
	while(scanf("%d",&ch))
	{
		if(ch==3) break;
		if(ch==0)
			scanf("%d",&n);
		else if(ch==1)
		{
			scanf("%d%d%d",&x,&y,&k);
			x++,y++;
			add(x,y,k);
		}
		else if(ch==2)
		{
			scanf("%d%d%d%d",&x,&y,&a,&b);
			a++,b++;
			printf("%d\n",query(a,b)+query(x,y)-query(a,y)-query(x,b));
		}
	}
	return 0;
}

