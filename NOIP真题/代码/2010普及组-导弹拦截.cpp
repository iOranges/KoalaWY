#include<bits/stdc++.h>
using namespace std;
int a1,b1,a2,b2,n,ss[100005];
struct node{
	int x,y;
}q[100005];
bool cmp(node m,node n)
{
	int t1=pow((a1-m.x),2)+pow((b1-m.y),2);
	int t2=pow((a1-n.x),2)+pow((b1-n.y),2);
	return t1<t2;
}
int main()
{
	scanf("%d%d%d%d%d",&a1,&b1,&a2,&b2,&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&q[i].x,&q[i].y);
	stable_sort(q+1,q+n+1,cmp);
	for(int i=n;i>=1;i--)
	{
		int l=pow((a2-q[i].x),2)+pow((b2-q[i].y),2);
		ss[i]=max(ss[i+1],l);
	}
	int sum=ss[1];
	for(int i=1;i<=n;i++)
	{
		int h1=pow((a1-q[i].x),2)+pow((b1-q[i].y),2);
		h1+=ss[i+1];
		sum=min(h1,sum);
	}
	sum=min(sum,ss[1]);
	cout<<sum;	
}
