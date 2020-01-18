#include<cstdio>
int l[1601],r[1601],w[40][40];

int main()
{
	int n,nn;
	scanf("%d",&n);
	l[1] = 1,r[1] = n / 2 + 1;
	w[l[1]][r[1]] = 1;
	register int i,j,k;
	nn = n * n;
	for(i = 2;i <= nn;++ i)
	{
		if(l[i - 1] == 1)
		{
			if(r[i - 1] == n)
				l[i] = l[i - 1] + 1,r[i] = r[i - 1];
			else 
				l[i] = n,r[i] = r[i - 1] + 1;
		}
		else if(r[i - 1] == n)
			r[i] = 1,l[i] = l[i - 1] - 1;
		else if(!w[l[i - 1] - 1][r[i - 1] + 1])
			l[i] = l[i - 1] - 1,r[i] = r[i - 1] + 1;
		else 
			l[i] = l[i - 1] + 1,r[i] = r[i - 1];
		w[l[i]][r[i]] = i;
	}
	for(i = 1;i <= n;++ i)
	{
		for(j = 1;j <= n;++ j)
			printf("%d ",w[i][j]);		
		puts("");
	}	
	return 0;
}
