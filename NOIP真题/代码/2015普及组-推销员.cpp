#include<bits/stdc++.h>
using namespace std;
int n,maxx,sum1[100005],p,maxn;
struct node{
	int s,a;
}q[100005];
priority_queue<int>qq;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&q[i].s);
	for(int i=1;i<=n;i++) scanf("%d",&q[i].a);
	for(int i=1;i<=n;i++) sum1[i]=q[i].a+2*q[i].s; 
	for(int i=1;i<=n;i++)
		if(sum1[i]>maxx) maxx=sum1[i],p=i;
	printf("%d\n",maxx);maxn=maxx;
	for(int i=1;i<=n;i++)
	{
		if(q[i].s<q[p].s) qq.push(q[i].a);
		else if(q[i].s>q[p].s) qq.push((q[i].a+2*(q[i].s-q[p].s)));
	}
	for(int i=2;i<=n;i++)
	{
		maxn+=qq.top();qq.pop();
		printf("%d\n",maxn);
	}
}
