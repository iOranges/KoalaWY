#include<iostream>
using namespace std;
int a[5][5],b[2001][2],c[2001];
bool s[5][5];
int move[2][4]={{1,-1,0,0},{0,0,1,-1}};
void print(int q)
{
	cout << "(" << b[q][0] << ", " << b[q][1] << ")\n";
	while(c[q])
	{
		q=c[q];
		cout << "(" << b[q][0] << ", " << b[q][1] << ")\n";
	}
}

int main()
{
	int i,j,head=0,tail=1,x,y;
	for(i=0;i<5;i++)
		for(j=0;j<5;j++)
			cin >> a[i][j];
	c[1]=0;
	b[tail][0]=4,b[tail][1]=4;
	s[4][4]=true;
	do{
		head++;
		for(int k=0;k<=3;k++)
		{
			x=b[head][0]+move[0][k];
			y=b[head][1]+move[1][k];
			if(x>=0&&x<=4&&y>=0&&y<=4&&a[x][y]==0&&!s[x][y])
			{
				s[x][y]=true;
				tail++;
				b[tail][0]=x;
				b[tail][1]=y;
				c[tail]=head;
				if(x==0&&y==0)
				{
					print(tail);
					head=tail;
					break;
				}
			}
		}
	}while(head<tail);
	return 0;
}
