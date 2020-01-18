#include<cstdio>
bool vis[1005][1005][2];
double f[1005][1005][2];

double dfs(int w,int b,int p)
{
	if(vis[w][b][p]) return f[w][b][p];
	if(w == 0) return p;	
	if(b == 0) return 1;
	if(!p)
		f[w][b][p] = (1 - dfs(w,b - 1,p ^ 1)) * (1.0 * b) / (w + b) + (1.0 * w) / (w + b);
	else 
	{
		if(b <= 1) f[w][b][p] += (1 - dfs(w - 1,b - 1,p ^ 1)) * (1.0 * b) / (w + b);
		else
			f[w][b][p] += (1 - dfs(w - 1,b - 1,p ^ 1)) * (1.0 * b) / (w + b) * w / (w + b - 1),
			f[w][b][p] += (1 - dfs(w,b - 2,p ^ 1)) * (1.0 * b) / (w + b) * (b - 1) / (w + b - 1);
		f[w][b][p] += (1.0 * w) / (w + b);
	}
	vis[w][b][p] = true;
	return f[w][b][p];
}

int main()
{
	int w,b;
	scanf("%d%d",&w,&b);
	printf("%.10lf",dfs(w,b,0));
	return 0;
}
