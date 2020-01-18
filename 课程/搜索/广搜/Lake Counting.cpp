#include<iostream>
using namespace std;
char a[111][111],b[1001][2];
int xm[8]={0,0,1,-1,1,1,-1,-1},ym[8]={1,-1,0,0,1,-1,1,-1};
int main()
{
	int n,i,m,j,head=0,tail=0,xx,yy,k,cnt=0;
	cin >> n >> m;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			cin >> a[i][j];
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
		{
			if(a[i][j]=='W')
			{
				cnt++;
				b[++tail][0]=i;
				b[tail][1]=j;
				a[i][j]='.';
				while(head<tail)
				{
					head++;
					for(k=0;k<=7;k++)
					{
						xx=b[head][0]+xm[k];
						yy=b[head][1]+ym[k];
						if(xx>=1&&xx<=n&&yy>=1&&yy<=m&&a[xx][yy]=='W')
						{
							++tail;
							b[tail][0]=xx;
							b[tail][1]=yy;
							a[xx][yy]='.';
						}
					}
				}
			}
		}
	cout << cnt;
	return 0;
}
