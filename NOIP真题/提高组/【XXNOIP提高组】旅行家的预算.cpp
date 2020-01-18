#include<cstdio>
#define max(x,y) ((x) > (y) ? (x) : (y))
#define min(x,y) ((x) < (y) ? (x) : (y))
int n;
double dis[15],c,d,w[15],full;

double dfs(int node,double oil)
{
	if(node == n) return 0;
	double money = 999999999999;
	for(int i = node + 1;i <= n;++ i)
		if(dis[i] - dis[node] <= full)
		{
			double use = (dis[i] - dis[node]) / d;
			if(w[i] > w[node]) money = min(money,(c - oil) * w[node] + dfs(i,c - use));
			else money = min(money,max(0,use - oil) * w[node] + dfs(i,max(oil - use,0)));
		}
	return money;
}

int main()
{
	double t;
	register int i;
	scanf("%lf%lf%lf%lf%d",&t,&c,&d,&w[1],&n);
	n += 2,dis[n] = t,full = c * d;
	for(i = 2;i < n;++ i)
		scanf("%lf%lf",&dis[i],&w[i]);
	double ans = dfs(1,0);
	if(ans >= 999999999998) printf("No Solution");
	else printf("%.2lf",ans);
	return 0;	
}

