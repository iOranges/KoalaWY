#include<cstdio>
int L,n,m,a[50005];
bool check(int k)
{
	int tot = 0,t = 0;
	for(int i=1;i<=n;i++)
	{
		while(a[i] - t < k&&i <= n)
			i++,tot++;
		t = a[i];
	}
	if(tot > m) return false;
	return true;
}

int main()
{
	int i,l,r,mid;
	scanf("%d%d%d",&L,&n,&m);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	l = 1,r = L;
	while(l<=r)
	{
		mid = (l+r) >> 1;
		if(check(mid)) 
			l = mid + 1;
		else
			r = mid - 1;
	}
	printf("%d",r);
	return 0;
}
