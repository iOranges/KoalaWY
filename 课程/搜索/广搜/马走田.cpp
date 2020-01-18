#include<cstring>
#include<iostream>
using namespace std;
int move[2][12]={{2,-2,1,1,-1,-1,-2,2,2,2,-2,-2},
				 {1,1,2,-2,-2,2,-1,-1,2,-2,2,-2}};
int n,m,a[10001][2],b[10001];
bool s[101][101];
void cnt(int p)
{
	int tot=0;
	while(b[p])
	{
		p = b[p];
		tot++;
	}
	cout << tot << endl;
}

void Bfs()
{
	int tail=1,head=0,i,x,y;
	a[1][0]=n,a[1][1]=m;
	s[n][m]=true,b[1]=0;
	do{
		head++;
		for(i=0;i<12;i++)
		{
			x=a[head][0]+move[0][i];
			y=a[head][1]+move[1][i];
			if(x>=1&&x<=100&&y>=0&&y<=100&&s[x][y]==false)
			{
				tail++;
				a[tail][0]=x;
				a[tail][1]=y;
				b[tail]=head;
				s[x][y]=true;
				if(x==1&&y==1)
				{
					cnt(tail);
					head=tail;
					break;
				}
			}
		 } 
	}while(head<tail);
}

int main()
{
	while(cin >> n >> m)
	{
		memset(s,false,sizeof(s));
		Bfs();
	}
	return 0;
}
