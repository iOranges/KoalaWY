#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int n,h[1501],tot,f[1501][2];
struct node{
	int son,next;
}t[1501];

void add(int a,int b)
{
	t[++tot].son = b;
	t[tot].next = h[a];
	h[a] = tot;
}

void work(int x)
{
	f[x][1] = 1;
	for(int i=h[x];i;i=t[i].next)
	{
		work(t[i].son);
		f[x][0] += f[t[i].son][1];
		f[x][1] += min(f[t[i].son][1],f[t[i].son][0]);
	}
}

int main()
{
	scanf("%d",&n);
	int i,x,j,m;
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&x,&m);
		for(j=1;j<=m;j++)
		{
			scanf("%d",&x);
			add(i,x);	
		}
	}
	work(0);
	printf("%d",min(f[0][0],f[0][1]));
	return 0;
}
