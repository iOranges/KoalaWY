#include<cmath>
#include<iostream>
using namespace std;
int a[100001];
int main()
{
	int n,m,minn,k,i,l,j,num,fab;
	bool ok;
	cin >> n;
	for(i=1;i<=n;i++)
		cin >> a[i];
	cin >> m;
	for(i=1;i<=m;i++)
	{
		cin >> k;
		minn = 999999999;
		ok = false;
		for(j=1;j<=n;j++)
		{		
			fab = fabs(k-a[j]);
			if(fab < minn)
			{
				minn = fab;
				num = a[j];
			}
			else if(ok&&fab != minn) break;
			else ok = true;
		}
		cout << num << endl;
	}
	return 0;
}
