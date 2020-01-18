#include<cstdio>
#define max(x,y) ((x) > (y) ? (x) : (y))
int w[35],f[35][35],pre[35][35];
void print(int l,int r)
{
	if(l == r)
		printf("%d ",l);
	if(pre[l][r])
	{
		printf("%d ",pre[l][r]);
		print(l,pre[l][r] - 1),print(pre[l][r] + 1,r);
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	register int i,j,k;
	for(i = 1;i <= n;++ i)
		scanf("%d",&w[i]);
	for(i = 1;i <= n;++ i)
		f[i][i] = w[i];
	for(i = 2;i <= n;++ i)
		for(j = i - 1;j >= 1;-- j)
			for(k = j;k <= i;++ k)
			{
				int v = max(1,f[j][k - 1]) * max(1,f[k + 1][i]) + w[k];
				if(v > f[j][i]) f[j][i] = v,pre[j][i] = k;
			}
	printf("%d\n",f[1][n]);
	print(1,n);
	return 0;
}
