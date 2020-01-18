#include<cstdio>
#define max(x,y) ((x)>(y)?(x):(y))
int f[100005],s[100005];

int main()
{
	int m,n,p,t,i,head = 0,tail = 1,l,r,x,y,z;
	scanf("%d%d%d%d",&m,&n,&p,&t);
	s[0] = -t;
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&l,&r);
		f[i] = f[i-1];
		s[i] = s[i-1];
		while(head<=tail && s[head] + t <= r)
		{
			x = max(s[head] + t,l);
			y = f[head] + (r - x) / p;
			z = r - (r - x) % p;
			if(y > f[i])
				f[i] = y,s[i] = z;
			else if(y == f[i]&&s[i] > z)
				s[i] = z;
			++ head;
		}
		-- head,++ tail;
	}
	printf("%d",f[n]);
	return 0;
 } 
