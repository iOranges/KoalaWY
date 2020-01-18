#include<bits/stdc++.h>
using namespace std;
char s[105][105];
int m,n,a[105][105],vis[105][105];
int dx[10]={0,0,1,1,1,-1,-1,-1};
int dy[10]={1,-1,1,0,-1,1,-1,0};
int main()
{
    scanf("%d%d",&m,&n);
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            cin>>s[i][j];
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
        {
            if(s[i][j]=='*') vis[i][j]=1;
            else
            {
                for(int k=0;k<8;k++)
                    if(s[i+dx[k]][j+dy[k]]=='*') a[i][j]++;
            }
        }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(vis[i][j]) printf("*");
            else printf("%d",a[i][j]);
        }
        printf("\n");
    }
}
