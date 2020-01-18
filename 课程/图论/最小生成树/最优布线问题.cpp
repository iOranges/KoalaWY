#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int f[101];
struct node{
	int u,v,w;
}e[10010];

int find(int x)
{
	if(f[x] != x) f[x] = find(f[x]);
	return f[x];
}

bool check(int a,int b)
{
	a = find(a),b = find(b);
	if(a!=b)
	{
		f[a] = b;
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
	int n,i,k=0,cnt=0,j,p=0,waste;
	cin >> n;
	for(i=1;i<=n;i++)
		f[i] = i;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(i!=j)
			{
				p++;
				e[p].u = i,e[p].v = j;
				cin >> e[p].w;
			}
			else
				cin >> waste;
	sort(e+1,e+p+1,cmp);
	for(i=1;i<=p;i++)
	{
		if(check(e[i].u,e[i].v))
		{
			k++;
			cnt+=e[i].w;
			if(k+1==n) break;
		}
	}
	cout << cnt;
	return 0;
}
