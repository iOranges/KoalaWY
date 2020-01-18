#include<iostream>
using namespace std;
int a[101][101],Max[101][2];
int main()
{
	int n,i,k=0,x,y,j,maxx=-1,maxy=-1,t=0;
	cin >> n;
	for(i=1;i<=n;i++)
	{
		cin >> x >> y;	
		a[x][y]=1;
		if(x>maxx) maxx=x;
		if(y>maxy) maxy=y;
	}
	for(i=maxx;i>=0;i--)
		for(j=maxy;j>k;j--)
		{
			if(a[i][j]==1)
			{
				k = j;
				t ++;
				Max[t][0]=i;
				Max[t][1]=j;
			}
		}
	for(i=t;i>=1;i--)
	{
		cout << "(" << Max[i][0] << "," << Max[i][1] << ")";
		if(i!=1)
			cout << ",";
	}
	return 0;
}
