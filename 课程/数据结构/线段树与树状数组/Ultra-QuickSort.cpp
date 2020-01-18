#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
int c[500001],n,a[500001]; 
vector<int> b;
inline int lowbit(int k)
{
	return k&(-k);
}

void add(int k)
{
	for(int i=k;i<=n;i+=lowbit(i))
		c[i]++;
}

int query(int pos)
{
	int ret=0,i;
	for(i=pos;i>0;i-=lowbit(i))
		ret+=c[i];
	return ret;
}

int main()
{
	int x,i;
	while(scanf("%d",&n))
	{
		if(n==0) break;
		memset(c,0,sizeof c);
		b.clear();
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			b.push_back(a[i]);
		}
		sort(b.begin(),b.end());
		b.erase(unique(b.begin(), b.end()), b.end());
		for(i=1;i<=n;i++)
			a[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin() + 1;
		long long ans=0;
		for(i=n;i>=1;i--)
		{
			add(a[i]);
			ans += query(a[i]-1);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
