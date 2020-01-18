#include<bits/stdc++.h>
using namespace std;
long long a[23][23];
int g[23][23],m,n,x,y;
int main()
{
    scanf("%d%d%d%d",&m,&n,&x,&y);
    for(int i=0;i<=m;i++)
        for(int j=0;j<=n;j++)
        {
            if(i==x&&j==y) g[i][j]=1;
            if(abs(i-x)+abs(j-y)==3&&i!=x&&j!=y) g[i][j]=1;
        }
    for(int i=0;i<=m;i++)
        for(int j=0;j<=n;j++)
            if(!g[i][j])
            {
                a[0][0]=1;
                if(j==0&&i<=m) a[i][0]=a[i-1][0];
                else if(i==0&&j<=n) a[0][j]=a[0][j-1];
                if(i!=0&&j!=0) a[i][j]=a[i-1][j]+a[i][j-1];
            }
    cout<<a[m][n];
}
