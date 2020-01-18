#include<cstdio>
#include<cstring>
#define max(x,y) ((x)>(y)?(x):(y))
#define min(x,y) ((x)<(y)?(x):(y))
int n,S,T,a[100005],q[100005];
double s[100005];

bool check(double k)
{
	register int i,l=1,r=0;
	s[0] = q[0] = 0;
	for(i=1;i<=n;i++) s[i] = s[i-1] + a[i] - k;
	for(i=1;i<=n;i++)
	{
/*		while(l <= r&&q[l] < i - T + 1) l++;
		if(s[i] - s[q[l]-1] > 0&&i - q[l] + 1 >= S&&i >= S) 
			return true;
		while(l <= r&&s[q[r]] > s[i]) r--;
		q[++r] = i;*/
		if(i>=S)
		{
			while(l <= r&&s[q[r]] > s[i-S]) r--;
			q[++r] = i - S;
		}
		while(l <= r&&q[l] < i - T) l++;
		if(s[i] - s[q[l]] >= 0&&l <= r) 
			return true;		
	}
	return false;
}

int main()
{
	int i,x;
	double l = 99999999,r = 0,mid;
	scanf("%d%d%d",&n,&S,&T);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		r = max(r,a[i]);
		l = min(l,a[i]);
	}
	while(r-l>1e-5)
	{
		mid = (r + l) / 2.0;
		if(check(mid))
			l = mid;
		else
			r = mid;
	}
	printf("%.3lf",l);
	return 0;
}
