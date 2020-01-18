#include<string>
#include<cstring>
#include<iostream>
using namespace std;
int f[501][501],line[101];

int main()
{
	char s;
	int m,n,i,j;
	cin >> m >> n;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			f[i][j] = 999999;
	for(i=1;i<=n;i++)
		f[i][i] = 0;
	for(i=1;i<=m;i++)
	{
		int o=0,t=0;
		memset(line,0,sizeof(line));
		while(cin >> s)
		{
			if(s == '\n')
				break;
			else if(s>='0'&&s<='9')
				o = o*10+s-'0';
			else
			{
				for(j=1;j<=t;j++)
					f[line[j]][o] = 1;
				line[++t]=o;
				o = 0;
			}
		}
	}
	return 0;
}
