#include<cstring>
#include<iostream>
using namespace std;
int a[1001][2];
int main()
{
	int n,i,j,l,k=1,m;
	cin >> m;
	while(m!=0)
	{
		int answer1,answer2;
		memset(a,0,sizeof(a));
		cin >> n; 
		for(i=1;i<=n;i++)
		{
			cin >> a[i][0];
			a[i][1]=1;
		}
		for(i=n-1;i>=1;i--)
		{
			l=0;
			for(j=i+1;j<=n;j++)
				if(a[j][0]<a[i][0]&&a[j][1]>l)
					l=a[j][1];
			if(l!=0)
				a[i][1]=l+1;
		}
		for(i=1;i<=n;i++)
			if(a[i][1]>a[k][1]) k=i;
		answer1=a[k][1];
		for(i=1;i<=n;i++)
			a[i][1]=1;	
		for(i=n-1;i>=1;i--)
		{
			l=0;
			for(j=i+1;j<=n;j++)
				if(a[j][0]>a[i][0]&&a[j][1]>l)
					l=a[j][1];
			if(l!=0)
				a[i][1]=l+1;
		}
		for(i=1;i<=n;i++)
			if(a[i][1]>a[k][1]) k=i;
		answer2=a[k][1];
		cout << max(answer1,answer2) << endl;			
		m--;	
	}
	return 0;
}
