#include<iostream>
using namespace std;
bool wall[51][51][4],b[51][51];
int a[100001][2],m,n,i,j,temp;
int move[2][4]={{1,0,-1,0},{0,1,0,-1}};
void havewall(int num)
{
	if(num>=8)
	{
		num-=8;
		wall[i][j][0]=true;
	}
	if(num>=4)
	{
		num-=4;
		wall[i][j][1]=true;
	}
	if(num>=2)
	{
		num-=2;
		wall[i][j][2]=true;
	}
	if(num>=1)
	{
		num-=1;
		wall[i][j][3]=true;
	}		
}

int main()
{
	cin >> m >> n;
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
		{
			cin >> temp;
			havewall(temp);
		}
	int head=0,tail=0,cnt = 0,k,x,y,num,Max=-1;
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
			if(!b[i][j])
			{
				num=1;
				++cnt,++tail;
				a[tail][0]=i;
				a[tail][1]=j;
				b[i][j]=true;
				do{
					head++;
					for(k=0;k<=3;k++)
					{
						if(!wall[a[head][0]][a[head][1]][k]) 
						{
							x=a[head][0]+move[0][k];
							y=a[head][1]+move[1][k];
							if(x>=1&&x<=m&&y>=1&&y<=n&&!b[x][y])
							{
								b[x][y]=true,tail++,num++;
								a[tail][0]=x,a[tail][1]=y;
							}							
						}
					}
				}while(head<tail);
				Max=max(Max,num);
			}
	cout << cnt << endl << Max;
	return 0;
 } 
