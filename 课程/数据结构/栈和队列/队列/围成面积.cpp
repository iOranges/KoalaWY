#include<iostream>
using namespace std;
const int s=100;
int a[12][12],b[101][2];
int xm[4]={0,0,1,-1},ym[4]={1,-1,0,0};
int main()
{
	int i,j,head=0,tail=0,cnt=0,xx,yy,k;
	for(i=1;i<=10;i++)
		for(j=1;j<=10;j++)
		{
			cin >> a[i][j];	
			if(a[i][j]==1)
				cnt++;		
		}
	for(i=1;i<=10;i++)
		a[0][i]=2,a[11][i]=2;
	for(j=1;j<=10;j++)
		a[j][0]=2,a[j][11]=2;
	for(i=1;i<=10;i++)
		for(j=1;j<=10;j++)
		{
			if(a[i][j]==0)
			{
				for(k=0;k<=3;k++)
				{
					xx=i+xm[k];
					yy=j+ym[k];
					if(xx>=0&&xx<=11&&yy>=0&&yy<=11&&a[xx][yy]==2)
					{
						++tail;
						b[tail][0]=i;
						b[tail][1]=j;
						a[i][j]=2;
						break;
					}
				}
				while(head<tail)
				{
					head++;
					for(k=0;k<=3;k++)
					{
						xx=b[head][0]+xm[k];
						yy=b[head][1]+ym[k];
						if(xx>=1&&xx<=10&&yy>=1&&yy<=10&&a[xx][yy]==0)
						{
							++tail;
							b[tail][0]=xx;
							b[tail][1]=yy;
							a[xx][yy]=2;
						}
					}
				}
			}
		}
	cout << s-cnt-tail;
	return 0;
}
