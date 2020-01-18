#include<iostream>
#include<cstdio>
long long l[22][22],map[23][23];
using namespace std;
void bj(int x,int y)
{
    map[x][y]=1;
    map[x-1][y-2]=1;
    map[x-2][y-1]=1;
    map[x-2][y+1]=1;
    map[x-1][y+2]=1;
    map[x+1][y-2]=1;
    map[x+2][y-1]=1;
    map[x+2][y+1]=1;
    map[x+1][y+2]=1;
}
int main()
{
	int a,b,n,m;
    scanf("%d%d%d%d",&n,&m,&a,&b);
    bj(a,b);
    l[1][0]=1;
    for(int i=1;i<=n+1;++i)
    {
        for(int j=1;j<=m+1;++j)
        {
            l[i][j]=l[i-1][j]+l[i][j-1];
            if(map[i-1][j-1]) l[i][j]=0;
        }
    }
    printf("%lld",l[n+1][m+1]);
    return 0;
}
