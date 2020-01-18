#include<cstring>
#include<iostream>
using namespace std;
int a[105], v[105], p[105], f[105];
int main()
{
	int t,n,k,i,j;
	cin >> t;
	while(t--)
	{
		memset(p,0,sizeof(p));
		memset(f,0,sizeof(f));
		cin >> n >> k;
		for(i=1;i<=n;i++)
			cin >> a[i];
		for(i=1;i<=n;i++)
			cin >> v[i];
		for(i=2;i<= n;i++)
			for(j=i-1;j>=1;j--)
				if(a[i]-a[j]>k)
				{
					p[i] = j; 
					break;
				}
		f[1] = v[1];
		for(i=2;i<= n;i++)
			f[i]=max(f[i-1],f[p[i]]+v[i]);
		cout << f[n] << endl;
	}
	return 0;
}
