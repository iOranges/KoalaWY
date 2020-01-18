#include<cstdio>
#include<cstring>
int s[50005],h[50005],l[50005],r[50005];

int main()
{
	int n,t,i,top;
	scanf("%d",&t);
	for(int o=1;o<=t;o++)
	{
		scanf("%d",&n);
		memset(s,0,sizeof s);
		for(i=1;i<=n;i++)
			scanf("%d",&h[i]);
		h[n+1] = h[0] = 0;
		s[1] = top = 1;
		l[1] = r[n] = 0;
		for(i=2;i<=n+1;i++)
			if(h[s[top]] > h[i])
			{
				l[i] = 0;
				s[++top] = i;				
			}
			else
			{
				while(h[s[top]] <= h[i]&&top)
				{
					l[i] = s[top];
					top --;					
				}
				s[++top] = i;
			}
		memset(s,0,sizeof s);
		top = 1;
		s[1] = n;
		for(i=n-1;i>=0;i--)
			if(h[s[top]] > h[i])
			{
				r[i] = 0;
				s[++top] = i;				
			}
			else
			{
				while(h[s[top]] <= h[i]&&top)
				{
					r[i] = s[top];
					top --;					
				}
				s[++top] = i;
			}
		printf("Case %d:\n",o);
		for(i=1;i<=n;i++)
			printf("%d %d\n",l[i],r[i]);		
	}
	return 0;
}
