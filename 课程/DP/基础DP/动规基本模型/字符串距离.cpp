#include<cmath>  //wrong!    BIG WRONG!!!
#include<cstring>
#include<iostream>
using namespace std;
char a[2][1001];
int f[1001][1001];
int main()
{
	int i,j,n; 
	cin >> n;
	while(n--)
	{
		cin >> a[0] >> a[1];
		memset(f,0,sizeof(f));
		int l1=strlen(a[0]),l2=strlen(a[1]);
		for(i=1;i<=l1;i++)
			for(j=1;j<=l2;j++)
			{
				f[i][j]=max(f[i-1][j],f[i][j-1]);
				if(a[0][i-1]==a[1][j-1])
					f[i][j]=max(f[i][j],f[i-1][j-1]+1);
			}
		cout << max(fabs(l1-f[l1][l2]),fabs(l2-f[l1][l2])) << endl;		
	}
	return 0;
}
