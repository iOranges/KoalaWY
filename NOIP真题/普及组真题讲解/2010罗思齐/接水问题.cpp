#include <bits/stdc++.h>
using namespace std;
int n,m,shuilongtou[100005],a[100005],weizhi,minn=0x7f7f7f7f;
int main()
{
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	for(int i=1;i<=n;i++)
	{
		minn=0x7f7f7f7f;
		for(int j=1;j<=m;j++)//找当前哪个水龙头时间最少
		{
			if(shuilongtou[j]<minn)
			{
				minn=shuilongtou[j];
				weizhi=j;
			}
		} 
		shuilongtou[weizhi]+=a[i];//去哪里接最少 
	}
	sort(shuilongtou+1,shuilongtou+m+1);
	cout << shuilongtou[m];//用时最长的水龙头 
	return 0;	
}
