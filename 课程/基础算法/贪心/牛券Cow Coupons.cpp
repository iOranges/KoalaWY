#include<queue>
#include<vector>
#include<cstdio>
#include<iostream>
using std::vector;
using std::greater;
using std::priority_queue;
struct node{
	long long x;
	int num;
	bool operator < (const node b) const{
		return x > b.x;
	} 
};
bool visit[50005];
int p[50005],c[50005];
priority_queue<node> a,b;
priority_queue<long long,vector<long long>,greater<long long> > d;
template <typename e>inline void read(e &x)
{
	x = 0;char ch = getc(stdin);
	while(ch > '9' || ch < '0') ch = getc(stdin);
	while(ch <= '9'&&ch >= '0'){x = x * 10 + (ch ^ 48);ch = getc(stdin);} 
}

int main()
{
	register int i;
	int n,k,cow = 0;
	long long m;
	read(n),read(k),read(m);
	for(i = 1;i <= n;++ i)
	{
		read(p[i]),read(c[i]);
		a.push(node{1ll * p[i],i});
		b.push(node{1ll * c[i],i});
	}
	for(i = 1;i <= k;++ i) d.push(0ll);
	while(m > 0&&cow < n)
	{
		while(visit[a.top().num]) a.pop();
		while(visit[b.top().num]) b.pop();
		if(b.top().x + d.top() < a.top().x)
		{
			node t = b.top();
			long long x = b.top().x + d.top();
			if(m < x) break;
			m -= x;
			d.pop();
			d.push(p[t.num] - c[t.num]);
			visit[t.num] = true;
		}
		else
		{
			long long x = a.top().x;
			if(m < x) break;
			m -= x;
			visit[a.top().num] = true;
		 } 
		cow ++ ;
	}
	printf("%d",cow);
	return 0;
 } 
