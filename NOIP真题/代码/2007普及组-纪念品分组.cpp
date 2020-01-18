#include<bits/stdc++.h>
using namespace std;
int w,n,a[30005],tot;
int main()
{
	scanf("%d%d",&w,&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	stable_sort(a+1,a+1+n);
	int p=1,q=n;
	while(p<=q)
	{
		if(a[p]+a[q]<=w){p++;q--;tot++;}
		else {q--;tot++;}
	}
	printf("%d",tot);
}
