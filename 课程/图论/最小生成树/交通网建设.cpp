#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
struct node{
	int u,v,w;
}e[10010],ans[101];
int father[20001];
int find(int x)
{
	if(father[x]!=x) father[x] = find(father[x]);
	return father[x];
}

bool check(int a,int b)
{
	a = find(a);
	b = find(b);
	if(a!=b)
	{
		father[a] = b;
		return true;
	}
	return false;
}

bool cmp1(node a,node b)
{
	return a.w < b.w;
}

bool cmp2(node a,node b)
{
	if(a.u!=b.u) return a.u < b.u;
	return a.v < b.v;
}

int main()
{
	int n,m,i;
	cin >> n >> m;
	for(i=1;i<=n;i++)
		father[i] = i;
	for(i=1;i<=m;i++)
		cin >> e[i].u >> e[i].v >> e[i].w;
	sort(e+1,e+m+1,cmp1);
	int k=0,cnt=0;
	for(i=1;i<=m;i++)
	{
		if(check(e[i].u,e[i].v))
		{
			k++;
			if(e[i].u>e[i].v) ans[k].u = e[i].v,ans[k].v = e[i].u;
			else ans[k].u = e[i].u,ans[k].v = e[i].v;
			if(k == n-1) break;
		}
	}
	sort(ans+1,ans+k+1,cmp2);
	for(i=1;i<=k;i++)
		cout << ans[i].u << " " << ans[i].v << endl;
	return 0;
}
