#include<bits/stdc++.h>
using namespace std;
int num[100005],n,p;
struct node{
	int time,people;
}port[100005];
queue<int> q;
int main()
{
	int x;scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&port[i].time,&port[i].people);
		for(int j=1;j<=port[i].people;j++)
		{
			scanf("%d",&x);
			q.push(x);
			if(!num[x]) num[0]++;
			num[x]++;
		}
		for(int k=p;k<i;k++)
		{
			if(port[i].time-port[k].time>=86400)
			{
				for(int l=1;l<=port[k].people;l++)
				{
					int y=q.front();
					num[y]--;
					if(!num[y]) num[0]--;
					q.pop();
				}
				p=k+1;
			}
			else{p=k;break;}
		}
		printf("%d\n",num[0]);
	}
}
