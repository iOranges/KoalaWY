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
		for(int j=1;j<=m;j++)//�ҵ�ǰ�ĸ�ˮ��ͷʱ������
		{
			if(shuilongtou[j]<minn)
			{
				minn=shuilongtou[j];
				weizhi=j;
			}
		} 
		shuilongtou[weizhi]+=a[i];//ȥ��������� 
	}
	sort(shuilongtou+1,shuilongtou+m+1);
	cout << shuilongtou[m];//��ʱ���ˮ��ͷ 
	return 0;	
}
