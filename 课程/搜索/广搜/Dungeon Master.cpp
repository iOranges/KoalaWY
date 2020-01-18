#include<cstring>
#include<iostream>
using namespace std;
char a[11][11][11];
int v[1000001][3],c[1000001];
bool b[11][11][11];
int move[3][6]={{1,-1,0,0,0,0},
			 {0,0,1,-1,0,0},
			 {0,0,0,0,1,-1}};
int main()
{
	int n,m,h,i,j,k,x,y,z,xx,yy,zz;
	while(true)
	{
		memset(b,false,sizeof(b));
		cin >> h >> n >> m;
		if(n+m+h==0) break;
		int head=0,tail=1;
		bool ok=true;		
		for(i=1;i<=h;i++)
			for(j=1;j<=n;j++)
				for(k=1;k<=m;k++)
				{
					cin >> a[i][j][k];		
					if(a[i][j][k]=='S')	
						v[1][0]=i,v[1][1]=j,v[1][2]=k,b[i][j][k]==true,c[1]=0;
					else if(a[i][j][k]=='E')
						z=i,x=j,y=k,a[i][j][k]='.';
				}
		do{
			head++;
			for(k=0;k<=5;k++)
			{
				xx=v[head][1]+move[1][k];
				yy=v[head][2]+move[2][k];
				zz=v[head][0]+move[0][k];
				if(xx>=1&&xx<=n&&yy>=1&&yy<=m&&zz>=1&&zz<=h&&!b[zz][xx][yy]&&a[zz][xx][yy]=='.')
				{
					tail++;
					v[tail][0]=zz,v[tail][1]=xx,v[tail][2]=yy;
					b[zz][xx][yy]=true,c[tail]=head;
					if(xx==x&&yy==y&&zz==z)
					{
						ok = false;
						int q=tail,cnt=0;
						while(c[q])
						{
							q=c[q];
							cnt++;
						}
						cout << "Escaped in " << cnt << " minute(s).\n";
						head=tail;
						break;
					}
				}
			}
		}while(head<tail);
		if(ok) cout << "Trapped!" << endl;
	} 
	return 0;
}
