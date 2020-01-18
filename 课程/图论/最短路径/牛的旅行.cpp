#include<cmath>
#include<cstdio>
#include<iostream>
using namespace std;
const double Max=1e12;
double x[151],y[151],f[151][151],m[151];
double work(int i,int j)
{
	return sqrt(pow(x[i]-x[j],2)+pow(y[i]-y[j],2));
}

int main()
{
	char c;
	int n,i,j,k;
	double Min=1e20,temp;
	cin >> n;
	for(i=1;i<=n;i++)
		cin >> x[i] >> y[i];
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		{
			cin >> c;
			if(c == '1')
				f[i][j] = work(i,j);
			else 
				f[i][j] = Max;
		}
	for(k=1;k<=n;k++)
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				if(i!=j&&j!=k&&k!=i&&f[i][k]<Max&&f[k][j]<Max)
					f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(f[i][j]<Max)
				m[i] = max(f[i][j],m[i]);
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(i!=j&&f[i][j]>=Max)	
			{
				temp=work(i,j);
				Min = min(Min,m[i]+m[j]+temp);
			}
	for(i=1;i<=n;i++)
		if(m[i]>Min)
			Min = m[i];
	printf("%.6lf",Min);
	return 0;
}
