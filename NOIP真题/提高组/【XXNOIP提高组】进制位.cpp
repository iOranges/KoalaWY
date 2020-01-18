#include<cstdio>
#include<cstring>
int two[50],sec[50];
char s[10][3],ch[10][2];

int main()
{
	int n;
	scanf("%d",&n);
	scanf("%s",s[0]);
	register int i,j,k;
	for(i = 1;i < n;++ i) scanf("%s",ch[i] + 1);
	for(i = 1;i < n;++ i)
		for(j = 1;j <= n;++ j)
		{
			scanf("%s",s[j] + 1);
			for(k = 2;k < j;++ k)
				if(strcmp(s[k] + 1,s[j] + 1) == 0)
				{
					printf("ERROR!");return 0;
				}
			if(strlen(s[j] + 1) == 2)
				++ two[i],++ sec[s[j][2] - 'A' + 1];
		}
	for(i = 1;i < n;++ i)
		if(two[i] != n - 2 - sec[ch[i][1] - 'A' + 1])
		{
			printf("ERROR!");return 0;
		}
	for(i = 1;i < n;++ i)
		printf("%c=%d ",ch[i][1],two[i]);
	printf("\n%d",n - 1);
	return 0;
}

