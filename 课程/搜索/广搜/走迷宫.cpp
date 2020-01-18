#include<iostream>
using namespace std;
char a[41][41];
int n,m,x,y,b[1001][2],i,j,xx,yy,c[10001];
int move[2][4]={{1,-1,0,0},{0,0,1,-1}};
void out(int q)
{
	int tot=1;
	while(c[q])
	{
		q=c[q];
		tot++;
	}
	cout << tot << endl;
}

int main()
{
	int cnt = 1,tail = 1,head = 0;
	cin >> n >> m;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			cin >> a[i][j];	
	bool ok = true;
	b[tail][0]=1,b[tail][1]=1,c[1]=0;
	do
	{
		head++;
		for(int k=0;k<4;k++)
		{
			xx=b[head][0]+move[0][k];
			yy=b[head][1]+move[1][k];
			if(yy>=1&&yy<=m&&xx>=1&&xx<=n&&a[xx][yy]=='.')
			{
				tail++;
				b[tail][0]=xx;
				b[tail][1]=yy;
				c[tail]=head;
				a[xx][yy]='#';
				if(xx==n&&yy==m)
				{
					out(tail);
					head=tail;
					ok = false;
					break;
				}					
			}
		}
	}while(head<tail);
	if(ok) cout << "-1" << endl;
	return 0;
}
