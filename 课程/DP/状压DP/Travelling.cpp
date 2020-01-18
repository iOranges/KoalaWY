#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int tri[11] = {1,3,9,27,81,243,729,2187,6561,19683,59049},dig[59050][10],f[59050][10],e[10][10];
void read(int &x)
{
	int t=1;char ch;x=0;
	ch = getchar();
	while(ch>'9'||ch<'0') {if(ch=='-') t=-1;ch=getchar();}
	while(ch<='9'&&ch>='0') {x = (x<<1)+(x<<3)+(ch^48);ch = getchar();}
	x*=t;
}

int main()
{
	int i,j,k,t,n,m,a,b,s,c;
	for(i=0;i<=59049;++i)
	{
		t = i;
		for(j=0;j<10;++j)
		{
			dig[i][j] = t%3;
			t/=3;
			if(!t) break;
		}
	}
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		int ans = 0x3f3f3f3f;
		memset(f,0x3f,sizeof f);
		memset(e,0x3f,sizeof e);
		for(i=1;i<=m;++i)
		{
			read(a),read(b),read(c);
			e[b-1][a-1] = e[a-1][b-1] = min(c,e[a-1][b-1]);
		}
		for(i=0;i<n;i++) f[tri[i]][i] = 0; 
		s = tri[n] - 1;
		for(i=0;i<=s;++i)
		{
			bool visit = true;
			for(j=0;j<n;j++)
			{
				if(!dig[i][j]) visit = false;
				if(f[i][j] == 0x3f3f3f3f) continue;
				for(k=0;k<n;k++)
				{
					if(k == j||dig[i][k] >= 2||e[j][k] == 0x3f3f3f3f) continue;
					f[i+tri[k]][k] = min(f[i+tri[k]][k],f[i][j]+e[j][k]);
				}
			}
			if(visit)
				for(j=0;j<n;j++)
					ans = min(ans,f[i][j]);
		}
		if(ans == 0x3f3f3f3f)
			printf("-1\n");
		else
			printf("%d\n",ans);
	}
	return 0;
}
