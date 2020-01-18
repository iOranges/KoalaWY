#include <bits/stdc++.h>
using namespace std;
int xx,yy,xxx,yyy,n,x,y,diss1,diss2,ans,maxx,minn;
struct qwq
{
	int dis1;
	int dis2;
	int ans1=0;
	int ans2=0;
}s[100005];
bool cmp1(qwq x,qwq y)
{
	return x.dis1>y.dis1;
}
int main()
{
	cin >> xx >> yy >> xxx >> yyy;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> x >> y;
		s[i].dis1=(xx-x)*(xx-x)+(yy-y)*(yy-y);
		s[i].dis2=(xxx-x)*(xxx-x)+(yyy-y)*(yyy-y);
	}
	stable_sort(s+1,s+n+1,cmp1);
	minn=s[1].dis1+diss2;
	for(int i=2;i<=n;i++)
	{
		diss2=max(s[i-1].dis2,diss2);//因为第二个点要把第一个系统没覆盖的覆盖掉，s结构体又是以dis1从大到小排序的，所以s-1就是第一个系统没覆盖到的所有点的最大点 
		diss1=s[i].dis1;
		minn=min(minn,diss1+diss2);
	}
	cout << minn;
	return 0;	
}
