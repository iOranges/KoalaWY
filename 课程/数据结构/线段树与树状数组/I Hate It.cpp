#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int n,c[200001],a[200001];
inline void read(int& x) {
    int f = 1; x = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9')   {if (ch == '-') f = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
    x *= f;
}

inline int lowbit(int k)
{
	return k&(-k);
}

void change(int x)
{
	int lx,o;
	c[x]=a[x];
	while(x<=n)
	{
		lx=lowbit(x);
		for(int i=1;i<lx;i<<=1)
			c[x] = max(c[x],c[x-i]);
		x+=lx;
	}
}

int query(int x,int y)
{
	int ans=0;
	while(y>=x)
	{
		ans = max(ans,a[y]);
		--y;
		for(;y-lowbit(y)>=x;y-=lowbit(y))
			ans = max(ans,c[y]);
	}
	return ans;
}

int main()
{
	int m,i,x,k;
	char ch;
	while(scanf("%d%d",&n,&m)==2)
	{
		memset(a,0,sizeof a);
		memset(c,0,sizeof(c));
		for(i=1;i<=n;i++)
		{
			read(a[i]);
			change(i);
		}
		for(i=1;i<=m;i++)
		{
			cin >> ch;
			read(x);
			read(k);
			if(ch=='U')
			{
				a[x] = k;
				change(x);
			}
			else
				printf("%d\n",query(x,k));
		}
	}
	return 0;
}
