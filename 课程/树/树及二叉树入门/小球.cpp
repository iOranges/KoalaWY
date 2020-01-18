#include<cmath>
#include<iostream>
using namespace std;
int tree[1200000][3];
int main()
{
	int d,k,n=0,j,i;
	cin >> d >> k;
	for(i=1;i<=d;i++)
		n += pow(2,i-1);
	for(i=1;i<=n;i++)
	{
		tree[i][2]=1;
		if(i>1)
		{
			if(i%2==0)
				tree[i/2][0] = i;
			else
				tree[(i-1)/2][1] = i;
		}
	}
	for(i=1;i<=k;i++)
	{
		j=1;
		while(true)
		{
			if(tree[j][0] == 0&&tree[j][1] == 0)
				break;
			else if(tree[j][2]==1)
			{
				tree[j][2]=-1;
				j = tree[j][0];
			}
			else 
			{
				tree[j][2]=1;
				j = tree[j][1];				
			}
		}
	}
	cout << j;
	return 0;
}
