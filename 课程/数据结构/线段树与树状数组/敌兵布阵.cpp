#include<cstdio>
#include<cstring>
int c[50001],n;
inline int lowbit(int k)
{
	return k&(-k);
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
		ret += c[i];
	return ret;
}

int main()
{
	int t,x,k,a,b,i,o,m=1;
	scanf("%d",&t);
	while(m<=t)
	{
		char s[10];
		memset(c,0,sizeof(c));
		printf("Case %d:\n",m);
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&o);	
			add(i,o);		
		}
		while(scanf("%s",&s))
		{
			if(s[0]=='E') break;
			else if(s[0]=='A')
			{
				scanf("%d%d",&k,&x);
				add(k,x);
			}
			else if(s[0]=='S')
			{
				scanf("%d%d",&k,&x);
				add(k,-x);			
			}
			else
			{
				scanf("%d%d",&a,&b);
				printf("%d\n",query(b)-query(a-1));
			}
		}
		++m;
	}
	return 0;
 } 
