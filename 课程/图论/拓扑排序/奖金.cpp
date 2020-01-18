#include<iostream>
using namespace std;
int f[10001][10001],r[10001],c[10001],ans[10001],money,p[10001];

int main()
{
	int n,m,a,b,tot=0,num=0,temp,i;
	cin >> n >> m;
	for(i=1;i<=n;i++)
		p[i] = 100;	
	for(i=1;i<=m;i++)
	{
		cin >> a >> b;
		c[b]++,r[a]++;
		f[b][c[b]] = a;
	}
	for(i=1;i<=n;i++)
		if(r[i]==0)
			ans[++tot]=i;
	do{
		temp = ans[tot];
		money += p[temp];   
		tot--,num++;
		for(i=1;i<=c[temp];i++)
		{
			r[f[temp][i]]--;
			p[f[temp][i]] = max(p[temp]+1,p[f[temp][i]]);
			if(r[f[temp][i]]==0)
				ans[++tot] = f[temp][i];
		}
	}while(tot!=0);
	if(num != n)
		cout << "Poor Xed";
	else
		cout << money;
	return 0;
}
