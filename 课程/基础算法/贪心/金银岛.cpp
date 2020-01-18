#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
double a[101][3];
void qsort(int l,int r)
{
	int i=l,j=r;
	double mid=a[(l+r)/2][2];
	do{
		while(a[i][2]>mid)	i++;
		while(a[j][2]<mid)	j--; 
		if(i<=j)
		{
			swap(a[i],a[j]);
			i++,j--; 
		}
	}while(i<=j);
	if(l<j)	qsort(l,j);
	if(r>i)	qsort(i,r);
}

int main()
{
	int k,i,s,j,w;
	cin >> k;
	for(i=1;i<=k;i++)
	{
		double money = 0;
		cin >> w >> s;
		for(j=1;j<=s;j++)
		{
			cin >> a[j][0] >> a[j][1];
			a[j][2] = a[j][1]/a[j][0];
		}
		qsort(1,s);
		for(j = 1;j <= s;j++)
		{
			if(a[j][0]<=w)
			{
				w-=a[j][0];
				money+=a[j][1];
			}
			else if(a[j][0]>w)
			{
				money+=w*a[j][2];
				w=0;
			} 
			if(w==0) break;
		}
		printf("%.2lf\n",money);
	}
	return 0;
 } 
