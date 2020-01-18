#include<bits/stdc++.h>
using namespace std;
int a[4],b[4];
int main()
{
	int n,ans=0x7f7f7f7f;
	scanf("%d",&n);
	for(int i=1;i<=3;i++)scanf("%d%d",&a[i],&b[i]);
	for(int i=1;i<=3;i++) ans=min(ans,(int)(ceil(n*1.0/a[i])*b[i]));
	printf("%d",ans);
	return 0;
}
