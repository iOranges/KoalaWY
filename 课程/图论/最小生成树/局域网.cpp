#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
struct node{
	int u,v,w;
}e[10010];
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

bool cmp(node a,node b)
{
	return a.w < b.w;
}

int main()
{
	int n,m,i,all=0;
	cin >> n >> m;
	for(i=1;i<=n;i++)
		father[i] = i;
	for(i=1;i<=m;i++)
		cin >> e[i].u >> e[i].v >> e[i].w,all += e[i].w;
	sort(e+1,e+m+1,cmp);
	int k=0,cnt=0;
	for(i=1;i<=m;i++)
	{
		if(check(e[i].u,e[i].v))
		{
			k++;
			cnt += e[i].w;
			if(k == n-1) break;
		}
	}
	cout << all-cnt;
	return 0;
}
