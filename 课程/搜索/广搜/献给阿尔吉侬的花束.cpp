#include<iostream>
using namespace std;
char a[201][201];
int n,m,x,y,b[40001][2],i,j,xx,yy,c[40001];
int move[2][4]={{1,-1,0,0},{0,0,1,-1}};
void out(int q)
{
	int tot=0;
	while(c[q])
	{
		q=c[q];
		tot++;
	}
	cout << tot << endl;
}

int main()
{
	int T,t=0;
	cin >> T;
	for(t=1;t<=T;t++)
	{
		int cnt = 1,tail = 1,head = 0;
		cin >> n >> m;
		for(i=1;i<=n;i++)
			for(j=1;j<=m;j++)
			{
				cin >> a[i][j];	
				if(a[i][j]=='S')
					b[tail][0]=i,b[tail][1]=j,c[1]=0;
				if(a[i][j]=='E')
					x=i,y=j,a[i][j]='.';
			}
		bool ok = true;
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
					if(xx==x&&yy==y)
					{
						out(tail);
						head=tail;
						ok = false;
						break;
					}					
				}
			}
		}while(head<tail);
		if(ok) cout << "oop!" << endl;
	} 
	return 0;
}
