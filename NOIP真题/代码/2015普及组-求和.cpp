#include<bits/stdc++.h>
using namespace std;
int n,m,a[100005],b[100005],s[100005][2],ss[100005][2],sum;
const int p=10007;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&b[i]);
		s[b[i]][i%2]++;
		ss[b[i]][i%2]=(ss[b[i]][i%2]+a[i])%p; 
	}
	for(int i=1;i<=n;i++)
		sum=(sum+i*((s[b[i]][i%2]-2)*a[i]%p+ss[b[i]][i%2]%p))%p;
	printf("%d",sum);
}
