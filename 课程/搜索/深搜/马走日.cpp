#include<cstring>
#include<iostream>
using namespace std;
int n,m,move[2][8]={{2,2,-2,-2,1,1,-1,-1},{1,-1,1,-1,2,-2,2,-2}},cnt=0;
bool f[11][11];
void search(int x,int y,int step)
{
	if(step>n*m)
	{
		cnt++;	
		return;	
	}
	for(int i=0;i<=7;i++)
	{
		int xx=move[0][i]+x,yy=move[1][i]+y;
		if(xx>=1&&xx<=n&&yy>=1&&yy<=m&&f[xx][yy]==false)
		{
			f[xx][yy]=true;
			search(xx,yy,step+1);
			f[xx][yy]=false;
		}
	}
}

int main()
{
	int t,x,y;
	cin >> t;
	while(t--)
	{
		cnt = 0;
		memset(f,false,sizeof(f));
		cin >> n >> m >> x >> y;
		search(x+1,y+1,2);
		cout << cnt;	
	}
	return 0;
 } 
