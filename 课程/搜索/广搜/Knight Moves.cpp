#include<cstring>
#include<iostream>
using namespace std;
int move[2][8]={{2,-2,1,1,-1,-1,-2,2},
				{1,1,2,-2,-2,2,-1,-1}};
int n,m,a[100001][2],b[100001],x,y,l;
bool s[301][301];
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
	int tail=1,head=0,i,xx,yy;
	a[1][0]=n,a[1][1]=m;
	s[n][m]=true,b[1]=0;
	do{
		head++;
		for(i=0;i<8;i++)
		{
			xx=a[head][0]+move[0][i];
			yy=a[head][1]+move[1][i];
			if(xx>=0&&xx<=l&&yy>=0&&yy<=l&&s[xx][yy]==false)
			{
				tail++;
				a[tail][0]=xx;
				a[tail][1]=yy;
				b[tail]=head;
				s[xx][yy]=true;
				if(xx==x&&yy==y)
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
	int t;
	cin >> t;
	while(t!=0)
	{
		cin >> l >> n >> m >> x >> y;
		memset(s,false,sizeof(s));
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		if(n==x&&m==y) 
			cout << 0 << endl;
		else 
			Bfs(); 
		t--;
	}
	return 0;
}
