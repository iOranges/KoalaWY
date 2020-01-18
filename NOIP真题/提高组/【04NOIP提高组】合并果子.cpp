#include<cstdio>
#include<algorithm>
#define swap(x,y) (x^=y,y^=x,x^=y)
using std::sort;
int a[10001];

int main()
{
	int n,s=0;
	register int i,j;
	scanf("%d",&n);
	for(i = 1;i <= n;++ i)
		scanf("%d",&a[i]);
	sort(a + 1,a + n + 1);
	for(i = 2;i <= n;++ i)
	{
		a[i] += a[i-1];
		s += 1ll * a[i];
		j = i;
		while(a[j] > a[j + 1] && j < n)
		{
			swap(a[j],a[j + 1]);
			++ j;			
		}
	}
	printf("%d",s);
	return 0;
}
