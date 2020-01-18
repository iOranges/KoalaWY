#include<cstdio>
#include<iostream>
#define exit(x) {printf("%d",x);return 0;} 
using std::swap;
int n;
const double eps = 1e-16;
double mp[105][105];

inline double abs(double x)
{
	return x > eps ? x : -x; 
}

bool check(int r,int j,int i)
{
	if(abs(abs(mp[r][i]) - abs(mp[j][i])) > eps) return abs(mp[r][i]) < abs(mp[j][i]);
	for(register int k = i + 1;k <= n;++ k)
		if(abs(abs(mp[r][k]) - abs(mp[j][k])) > eps)
			return abs(mp[r][k]) > abs(mp[j][k]);
 } 

/*2
0 2 3
0 0 0
answer:0*/

int main()
{
	register int i,j,k;
	scanf("%d",&n);
	for(i = 1;i <= n;++ i)
		for(j = 1;j <= n + 1;++ j)
			scanf("%lf",&mp[i][j]);
	for(i = 1;i <= n;++ i)
	{
		int r = i;
		for(j = i + 1;j <= n;++ j)
			if(check(r,j,i))
				r = j;
		if(r != i) swap(mp[r],mp[i]);
		if(abs(mp[i][i]) < eps) continue;//先换行，再判无解\无穷多解 
		double div = mp[i][i];
		for(j = i;j <= n + 1;++ j)
			mp[i][j] /= div;
		for(j = i + 1;j <= n;++ j) 
		{
			div = mp[j][i];
			for(k = i;k <= n + 1;++ k)
				mp[j][k] -= mp[i][k] * div; 
		}
	}
	for(i = n - 1;i >= 1;-- i)
		for(j = i + 1;j <= n;++ j)
			mp[i][n + 1] -= mp[i][j] * mp[j][n + 1];
	bool flag1 = false,flag2 = false;
	for(i = 1;i <= n;++ i)
		if(abs(mp[i][i]) < eps)
		{
			if(abs(mp[i][n + 1]) < eps) flag1 = true;
			else flag2 = true;
		}
	if(flag2) exit(-1);
	if(flag1) exit(0);
	for(i = 1;i <= n;++ i)
		printf("x%d=%.2lf\n",i,abs(mp[i][n + 1]) < eps ? 0 : mp[i][n + 1]);
	return 0;
}
