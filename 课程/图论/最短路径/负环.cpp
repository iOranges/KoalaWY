#include<queue>
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
struct node{
	int v,to,next;
}e[6005];
bool visit[2005];
int h[2005],tot,cnt[2005],dis[2005],n;

inline void read(int &x)
{
    int f=1;x=0;char s=getchar();
    while(s>'9'||s<'0'){if(s=='-')f=-1;s=getchar();}
    while(s<='9'&&s>='0'){x=x*10+s-'0';s=getchar();}
    x*=f;
}

void add(int a,int b,int k)
{
	e[++tot].to = b;
	e[tot].v = k;
	e[tot].next = h[a];
	h[a] = tot;
}

bool spfa()
{
	memset(visit,0,sizeof visit);
	memset(cnt,0,sizeof cnt);
	memset(dis,0x7f,sizeof dis);
	visit[1] = true;
	dis[1] = 0;
	cnt[1] = 1;
	queue<int> q;
	q.push(1);
	do{
		int u = q.front();
		q.pop();
		visit[u] = false;
		for(int i=h[u];i;i=e[i].next)
		{
			int v = e[i].to;
			if(cnt[v] >= n) return true;
			if(dis[v] > dis[u] + e[i].v)
			{
				dis[v] = dis[u] + e[i].v;
				if(!visit[v])
					cnt[v] ++,visit[v] = true,q.push(v); 
			}
		}
	}while(!q.empty());
	return false;
}

int main()
{
	int t,i,m,a,b,c;
	read(t);
	while(t--)
	{
		tot = 0;
		memset(h,0,sizeof h);
		memset(e,0,sizeof e);
		read(n),read(m);
		for(i=1;i<=m;i++)
		{
			scanf("%d%d%d",&a,&b,&c);
			if(c>=0) add(b,a,c);
			add(a,b,c);
		}
		if(spfa())
			printf("YE5\n");
		else
			printf("N0\n");
	}
	return 0;
}
