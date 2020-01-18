#include<cstdio>
#include<iostream>
using namespace std;
int n,f[6001][2],w[6001],r[6001],h[6001],tot;
struct node{
	int next,son;
}t[6001];

void add(int a,int b)
{
	t[++tot].son = a;
	t[tot].next = h[b];
	h[b] = tot;
}

void work(int x)
{
	int ans1=0,ans2=0;
	for(int i=h[x];i;i=t[i].next)
	{
		work(t[i].son);	
		ans1 += f[t[i].son][0];
		ans2 += f[t[i].son][1];
	}
	f[x][0] = max(f[x][0],max(ans1,ans2));
	f[x][1] = max(ans1+w[x],f[x][1]);
}

int main()
{
	scanf("%d",&n);
	int i,a,b;
	for(i=1;i<=n;i++)
		scanf("%d",&w[i]);
	for(i=1;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		add(a,b);
		r[a]++;
	}
	scanf("%d%d",&a,&b);
	for(i=1;i<=n;i++)
		if(!r[i])
		{
			work(i);
			break;		
		}
	printf("%d",max(f[i][0],f[i][1]));
	return 0;
}
