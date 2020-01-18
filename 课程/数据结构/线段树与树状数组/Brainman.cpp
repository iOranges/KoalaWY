#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
vector<int> b;
int a[1001],c[1001],n;

inline int lowbit(int k)
{
	return k&(-k);
}

void add(int x)
{
	for(int i=x;i<=n;i+=lowbit(i))
		c[i]++;
}

int query(int x)
{
	int ret=0;
	for(int i=x;i>=1;i-=lowbit(i))
		ret+=c[i];
	return ret;
}

int main()
{
	int t,p,i,j;
	long long ans;
	scanf("%d",&t);
	for(p=1;p<=t;p++)
	{
		ans = 0;
		memset(a,0,sizeof a);
		memset(c,0,sizeof c);
		b.clear();
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			b.push_back(a[i]);
		}
		sort(b.begin(),b.end());
		b.erase(unique(b.begin(), b.end()), b.end());
		for(i=1;i<=n;i++)
			a[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin() + 1;
		for(i=1;i<=n;i++)
		{
			add(a[i]);
			ans = ans+i-query(a[i]);
		}
		printf("Scenario #%d: \n%d\n\n",p,ans);
	}
	return 0;
}
