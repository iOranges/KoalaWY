#include<iostream>
using namespace std;
int a[1005],b[1005][2];
int main()
{
	int i=2,k=1,q,j,m,p=1,maxx=1,l;
	cin >> a[1];
	b[1][0]=a[1];
	b[1][1]=1;
	while(cin >> m) 
	{
		b[++p][0]=m;
		b[p][1]=1;
		q=0;
		for(j=1;j<=k;j++)
			if(a[j]>=m)
				if(q == 0||a[j] < a[q])	q=j;
		if(q == 0)
		{
			++k;
			a[k] = m;
		}
		else a[q] = m;
		i++;
	}
	for(i=p-1;i>=1;i--)
	{
		l=0;
		for(j=i+1;j<=p;j++)
			if(b[j][0]<=b[i][0]&&b[j][1]>l)
				l=b[j][1];
		if(l!=0)
			b[i][1]=l+1;
	}
	for(i=1;i<=p;i++)
		if(b[i][1]>b[maxx][1]) maxx=i;
	cout << b[maxx][1] << endl << k;
	return 0;
}
