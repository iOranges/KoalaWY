#include<iostream>
using namespace std;
struct node{
	int xmin,xmax,ymin,ymax;
}a[30];
bool b[101];
int c[101],r[101],f[101][101],ans[201],line[101];

int main()
{
	int n,i,j,x,y,tot=0,num=0,temp;
	cin >> n;
	for(i=1;i<=n;i++)
		cin >> a[i].xmin >> a[i].xmax >> a[i].ymin >> a[i].ymax;
	for(i=1;i<=n;i++)
	{
		cin >> x >> y;
		for(j=1;j<=n;j++)
			if(x>=a[j].xmin&&x<=a[j].xmax&&y<=a[j].ymax&&y>=a[j].ymin)
			{
				c[i]++,c[n+j]++;
				r[i]++,r[n+j]++;
				f[i][c[i]]=n+j;
				f[n+j][c[n+j]]=i;
			}
	}
	for(i=1;i<=2*n;i++)
	{
		if(c[i] == 1)
			ans[++tot] = i;
		else if(c[i] == 0)
		{
			cout << "None";
			return 0;
		}
	}
	do{
		temp = ans[tot];
		tot--,num++;
		for(i=1;i<=r[temp];i++)
			if(!b[f[temp][i]])
			{
				if(temp > f[temp][i])
					line[temp] = f[temp][i];
				else
					line[f[temp][i]] = temp;
				b[f[temp][i]] = true;
				b[temp] = true;
				for(j=1;j<=c[f[temp][i]];j++)
				{
					c[f[f[temp][i]][j]]--;
					if(c[f[f[temp][i]][j]]==1&&!b[f[f[temp][i]][j]])
						ans[++tot] = f[f[temp][i]][j];
				}		
			}
	}while(tot!=0);
	for(i=n+1;i<=2*n;i++)
		if(line[i]==0)
			{
				cout << "None";
				return 0;
			}
	for(i=n+1;i<=2*n;i++)
		cout << char(i-n+'A'-1) << ' ' << line[i] << endl;
	return 0;
}
