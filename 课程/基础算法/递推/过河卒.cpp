#include<cstdio>
long long a[25][25];

void control(int x,int y,int m,int n)
{
	a[x][y]=0;
	if(x-2>=0)
	{
		if(y-1>=0) a[x-2][y-1]=0;
		if(y+1<=m) a[x-2][y+1]=0;
	}
	if(x-1>=0)
	{
		if(y-2>=0) a[x-1][y-2]=0;
		if(y+2<=m) a[x-1][y+2]=0;
	}
	if(x+1<=n)
	{
		if(y-2>=0) a[x+1][y-2]=0;
		if(y+2<=m) a[x+1][y+2]=0;
	}
	if(x+2<=n)
	{
		if(y-1>=0) a[x+2][y-1]=0;
		if(y+1<=m) a[x+2][y+1]=0;
	}
}

int main()
{
    int n,m,i,j,cx,cy;
    scanf("%d%d%d%d",&n,&m,&cx,&cy);
    for(i=0;i<=n;i++)
        for(j=0;j<=m;j++)
            a[i][j]=1;
    control(cx,cy,m,n);
	for(i=0;i<=n;i++)
        for(j=0;j<=m;j++)
			if(a[i][j]==1)
			{
				if(i==0&&j==0);
				else if(i==0) a[i][j]=a[i][j-1];
				else if(j==0) a[i][j]=a[i-1][j];
				else  a[i][j]=a[i-1][j]+a[i][j-1];
			}
    printf("%lld",a[n][m]);
    return 0;
}
