//Dijkstra-���׵�˼��-ö������ 
//����Ȩ ���� 
#include<bits/stdc++.h>
using namespace std;
int a[110][3];//����ʼ�������� 
double c[110];//��ʼ�㵽���i��������· 
bool b[110];
double f[110][110];
int n,m;//���ͱ� 
int x,y;
int s,e,k;
double minx=0,maxx=1e30;
double dis(int x,int y)
{
	return sqrt(pow(a[x][1]-a[y][1],2)+pow(a[x][2]-a[y][2],2));
}
int main()
{
	cin>>n;//����n����㣻
	for(int i=1;i<=n;i++)
	cin>>a[i][1]>>a[i][2];
//	memset(f,0x7f,sizeof f);
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	f[i][j]=maxx;
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y;
		f[x][y]=f[y][x]=dis(x,y);
	}

	cin>>s>>e;
	for(int i=1;i<=n;i++) c[i]=f[s][i]; 
	memset(b,false,sizeof(b));
	b[s]=true;
	c[s]=0;
	for(int i=1;i<=n-1;i++)
	{
		minx=maxx;
		k=0;
		for(int j=1;j<=n;j++)
			if(b[j]==false&&c[j]<minx)
			{
				minx=c[j];
				k=j;
			}
		if(k==0) break;
		b[k]=true;
		for(int j=1;j<=n;j++)
		{
			if(c[k]+f[k][j]<c[j])
			c[j]=c[k]+f[k][j];
		}
	}
	printf("%.2lf",c[e]); 
	return 0;
}

