#include<bits/stdc++.h>
using namespace std;
int n,tot[100005],last=1,x;
pair<int,int> ship[100005];
queue<int> q;
int main()
{
	scanf("%d",&n);
	for(int l=1;l<=n;l++)
	{
		scanf("%d%d",&ship[l].first,&ship[l].second);
		for(int i=1;i<=ship[l].second;i++)
		{
			scanf("%d",&x);
			q.push(x);
			if(!tot[x]) ++tot[0];
			++tot[x];
		}
		for(int j=last;j<l;j++)
			if(ship[l].first-ship[j].first>=86400)
			{
				for(int k=1;k<=ship[j].second;k++)
				{
					x=q.front();
					--tot[x];
					if(!tot[x])--tot[0];
					q.pop();
				}
				last=j+1;
			}
			else{last=j;break;}
		printf("%d\n",tot[0]);
	}
	return 0;
}
