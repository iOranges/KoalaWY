#include<string>
#include<cstring>
#include<iostream>
using namespace std;
int f[2001][2001];
string s1,s2;
int main()
{
	int i,j,t;
	cin >> t;
	while(t--)
	{
		memset(f,0,sizeof(f));
		cin >> s1 >> s2;
		int n=s1.length(),m=s2.length();
		for(i=1;i<=n;i++)
			f[i][0]=i;
		for(i=1;i<=m;i++)
			f[0][i]=i;
		for(i=1;i<=n;i++)
			for(j=1;j<=m;j++)
				if(s1[i-1] == s2[j-1]) f[i][j] = f[i-1][j-1];
				else f[i][j] = min(f[i-1][j-1],min(f[i-1][j],f[i][j-1]))+1;
		cout << f[n][m] << endl;		
	}
	return 0;
 } 
