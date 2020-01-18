#include<cstdio>
#include<cstring>
int h[100005],s[100005];

int main()
{
	int n,t=0,i,top,cnt;
	while(~scanf("%d",&n))
	{
		memset(s,0,sizeof s);
		top = cnt = 0;
		t++;
		for(i=1;i<=n;i++)
			scanf("%d",&h[i]);
		printf("Case %d: ",t);	
		s[++top] = h[1];
		h[n+1] = 0;
		for(i=2;i<=n+1;i++)
			if(s[top] < h[i])
				s[++top] = h[i];
			else
			{
				while(s[top]>=h[i]&&top)
				{
					if(s[top]!=h[i])
						cnt++;
					top --;
				}
				s[++top] = h[i];	
			}
		printf("%d\n",cnt);
	}
	return 0;
}
