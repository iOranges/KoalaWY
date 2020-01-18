#include<iostream>
#include<algorithm>
using namespace std;
int father[2001];
struct node{
	int p,u,v,w;
}e[10001];
int find(int x)
{
	if(father[x] != x) father[x] = find(father[x]);
	return father[x];
}

bool check(int x,int y)
{
	x = find(x),y = find(y);
	if(x != y)
	{
		father[x] = y;
		return true;
	}
	return false;
}

bool cmp(node a,node b)
{
	if(a.p == b.p)
		return a.w < b.w;
	else 
		return a.p < b.p;
}

int main()
{
	int n,m,k=0,i,cnt=0;
	cin >> n >> m;
	for(i=1;i<=n;i++)
		father[i] = i;
	for(i=1;i<=m;i++)
		cin >> e[i].p >> e[i].u >> e[i].v >> e[i].w;
	sort(e+1,e+m+1,cmp);
	for(i=1;i<=m;i++)
	{
		if(check(e[i].u,e[i].v)||e[i].p==1)
		{
			k++;
			cnt += e[i].w;
		}
	}
	cout << cnt;
	return 0;
}
