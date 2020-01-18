#include<iostream>
using namespace std;
int father[10001][10001],r[10001],c[10001],ans[10001],money,p[10001];

int main()
{
	int n,m,i,a,b,tot=0,num=0,temp;
	cin >> n >> m;
	for(i=1;i<=n;i++)
		p[i] = 100;
	for(i=1;i<=m;i++)
	{
		cin >> a >> b;
		c[a]++,r[b]++;
		father[b][r[b]] = a;
	}
	for(i=1;i<=n;i++)
		if(c[i]==0)
			ans[++tot] = i;
	do{
		temp = ans[tot];
		tot--,num++;
		money += p[temp];
		for(i=1;i<=r[temp];i++)
		{
			c[father[temp][i]]--;
			p[father[temp][i]] = max(p[father[temp][i]],p[temp]+1);
			if(c[father[temp][i]] == 0)
				ans[++tot] = father[temp][i];			
		}
	}while(tot!=0);
	if(num != n)
		cout << "Poor Xed";
	else
		cout << money;
	return 0;
}
