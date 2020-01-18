//关于SPFA,它死了
#include<bits/stdc++.h>
using namespace std;
int a[801][801],num[801];
//a[i][j] 第i个结点的第j个后继结点,num[i]i结点的后继个数
int dis[801];//最短路
int w[801][801],b[801];//邻接矩阵,奶牛所在的牧场编号 
int que[1501];//队列
bool vis[801];
int n,p,c,x,y,head,tail,sum,len,u;
int i,j;
int main()
{
	cin>>n>>p>>c;
	for(i=1;i<=n;i++) cin>>b[i];
	memset(w,0x7f,sizeof w);
	for(i=1;i<=c;i++) 
	{
		cin>>x>>y>>len;
		w[x][y]=w[y][x]=len;
		a[x][++num[x]]=y;
		a[y][++num[y]]=x;
	}
	int minl=0x7fffffff;
	for(int k=1;k<=p;k++)
	{
		memset(que,0,sizeof que);
		memset(dis,0x7f,sizeof dis);
		memset(vis,0,sizeof vis);
		dis[k]=0;
		que[1]=k;
		head=0;
		tail=1;
		vis[k]=true;
		do{
		
			head++;
			head=(head-1)%1501+1;
			u=que[head];
			vis[u]=false;
			for(j=1;j<=num[u];j++)
			{	
		
				int h=a[u][j];
				if(dis[u]+w[u][h]<dis[h]) 
				{
					dis[h]=dis[u]+w[u][h];
					if(!vis[h]) 
					{
						tail++;
						tail=(tail-1)%1501+1;
						que[tail]=h;
						vis[h]=true;	
					}
				}
			}
		}while(head<tail);
		sum=0;
		for(int i=1;i<=n;i++)sum+=dis[b[i]];
		if(sum<minl) minl=sum;
	}
	cout<<minl<<endl;
	return 0;
 } 
