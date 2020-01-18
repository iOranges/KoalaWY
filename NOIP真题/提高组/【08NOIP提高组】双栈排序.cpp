#include<cstdio>
char op[5005];
int a[1005],s1[1005],s2[1005],top1,top2,num,cnt;

int main()
{
	int n;
	scanf("%d",&n);
	register int i,j;
	for(i = 1;i <= n;++ i)
		scanf("%d",&a[i]);
	num = 1;
	for(i = 1;i <= n;++ i)
	{
		if(a[i] == num)
			op[++ cnt] = 'a',op[++ cnt] = 'b',++ num;
		else if((s1[top1] > a[i]||!top1)&&(s2[top2] > a[i]||!top2))
		{
			bool flag = false;
			for(j = i + 1;j <= n;++ j)
				if(a[j] == num) flag = true;
				else if(a[j] > num) break;
			if(flag) s1[++ top1] = a[i],op[++ cnt] = 'a';
			else if(!top1&&!top2) s1[++ top1] = a[i],op[++ cnt] = 'a';
			else if(!top1) s2[++ top2] = a[i],op[++ cnt] = 'c';
			else if(!top2) s1[++ top1] = a[i],op[++ cnt] = 'a';
			else if(s1[top1] > s2[top2]) s2[++ top2] = a[i],op[++ cnt] = 'c';
			else s1[++ top1] = a[i],op[++ cnt] = 'a';
		}
		else if(s1[top1] > a[i]||!top1)
			s1[++ top1] = a[i],op[++ cnt] = 'a';
		else if(s2[top2] > a[i]||!top2)
			s2[++ top2] = a[i],op[++ cnt] = 'c';
		else {
			printf("0");
			return 0;
		}
		while(true)
		{
			bool flag = false;
			if(s1[top1] == num&&top1 > 0)
			{
				op[++ cnt] = 'b';
				++ num,-- top1;
				flag = true;
			}
			else if(s2[top2] == num&&top2 > 0)
			{
				op[++ cnt] = 'd';
				++ num,-- top2;
				flag = true;	
			}
			if(!flag) break;
		}		
	}
	for(i = 1;i <= cnt;++ i)
		putchar(op[i]),putchar(' ');
	return 0; 
}

