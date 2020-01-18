#include<cstdio>
bool f[1005];
int w[7] = {0,1,2,3,5,10,20},c[7];

int main()
{
	int m = 0,cnt = 0;
	register int i,j,k;
	for(i = 1;i <= 6;++ i)
	{
		scanf("%d",&c[i]);	
		m += c[i] * w[i];
	}
	f[0] = true;
	for(i = 1;i <= 6;++ i)
		for(j = m;j >= w[i];-- j)
			for(k = c[i];k > 0;-- k)
			{
				if(w[i] * k > j) continue;
				f[j] = f[j] || f[j - w[i] * k];
			}
	for(i = 1;i <= m;++ i)
		if(f[i]) ++ cnt;
	printf("Total=%d",cnt);
	return 0;
}
