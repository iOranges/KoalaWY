#include<cmath>
#include<queue>
#include<cstdio>
#include<cstring>
#define N 105
using std::priority_queue;
struct edge{
	double v;
	int to,nxt;
}e[N * N * 16];
int tot,h[N * 4],n,st,ed,t,num;
double id[N][5][2],distance[N * 4];
inline void add(int a,int b,double v)
{
	e[++ tot].to = b;
	e[tot].nxt = h[a];
	h[a] = tot;
	e[tot].v = v;
}

inline void clear()
{
	memset(h,0,sizeof h);
	memset(e,0,sizeof e);
	tot = num = 0;
}

inline double dis(double x1,double y1,double x2,double y2,bool twice)
{
	double z = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
	return twice ? z : sqrt(z);
}

void init()
{
	clear();
	scanf("%d%d%d%d",&n,&t,&st,&ed);
	int w;
	register int i,j,k,q;
	for(i = 1;i <= n;++ i)
	{
		for(j = 1;j <= 3;++ j)
			scanf("%lf%lf",&id[i][j][0],&id[i][j][1]);
		double d12 = dis(id[i][1][0],id[i][1][1],id[i][2][0],id[i][2][1],true) - id[i][3][0] * id[i][3][0] - id[i][3][1] * id[i][3][1];
		double d13 = dis(id[i][1][0],id[i][1][1],id[i][3][0],id[i][3][1],true) - id[i][2][0] * id[i][2][0] - id[i][2][1] * id[i][2][1];
		double d23 = dis(id[i][3][0],id[i][3][1],id[i][2][0],id[i][2][1],true) - id[i][1][0] * id[i][1][0] - id[i][1][1] * id[i][1][1];
		id[i][4][0] = ((id[i][1][1] - id[i][3][1]) * (d13 - d23) - (id[i][1][1] - id[i][2][1]) * (d12 - d23)) / 2.0 / ((id[i][1][0] - id[i][2][0]) * (id[i][1][1] - id[i][3][1]) - (id[i][1][0] - id[i][3][0]) * (id[i][1][1] - id[i][2][1]));
		if(id[i][1][1] - id[i][2][1] != 0) id[i][4][1] = (d13 - d23 - 2 * id[i][4][0] * (id[i][1][0] - id[i][2][0])) / 2.0 / (id[i][1][1] - id[i][2][1]);
		else id[i][4][1] = (d12 - d23 - 2 * id[i][4][0] * (id[i][1][0] - id[i][3][0])) / 2.0 / (id[i][1][1] - id[i][3][1]);
		scanf("%d",&w);
		for(j = 1;j <= 4;++ j)
			for(k = 1;k <= 4;++ k)
				if(j != k)
					add(num + j,num + k,dis(id[i][j][0],id[i][j][1],id[i][k][0],id[i][k][1],false) * w);
		num += 4;
	}
	for(i = 1;i <= n;++ i)
		for(j = 1;j <= n;++ j)
			if(i != j)
				for(k = 1;k <= 4;++ k)
					for(q = 1;q <= 4;++ q)
						add((i - 1) * 4 + k,(j - 1) * 4 + q,dis(id[i][k][0],id[i][k][1],id[j][q][0],id[j][q][1],false) * t);
}

struct node{
	int pos;
	double dis;
	bool operator < (const node b) const{
		return dis > b.dis;
	}
};
priority_queue<node> q;
void dij()
{
	while(!q.empty()) q.pop();
	register int i;
	for(i = 1;i <= n * 4;++ i)
		distance[i] = 99999999999999;
	for(i = 1;i <= 4;++ i)
	{
		q.push((node){(st - 1) * 4 + i,0});	
		distance[(st - 1) * 4 + i] = 0;
	}
	while(!q.empty())
	{
		int u = q.top().pos;
		double DIS = q.top().dis;
		q.pop();
		if(DIS != distance[u]) continue;
		if((u - 1) / 4 + 1 == ed)
		{
			printf("%.1lf\n",distance[u]);
			break;		
		}
		for(i = h[u];i;i = e[i].nxt)
		{
			int v = e[i].to;
			if(distance[v] > distance[u] + e[i].v)
			{
				distance[v] = distance[u] + e[i].v;
				q.push((node){v,distance[v]});
			}
		}
	} 
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T --)
	{
		init();
		dij();
	}
	return 0; 
}

