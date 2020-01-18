#include<cstdio>
#include<cstring>
int f[27],h[27];
char s1[105],s2[105],s3[105];

int main()
{
	scanf("%s%s%s",s1 + 1,s2 + 1,s3 + 1);
	int len = strlen(s1 + 1),a,b;
	register int i;
	for(i = 1;i <= len;++ i)
	{
		a = s1[i] - 'A' + 1,b = s2[i] - 'A' + 1;
		if((h[b]&&h[b] != a)||(f[a]&&f[a] != b))
		{
			printf("Failed");
			return 0;
		}
		h[b] = a,f[a] = b;
	}
	for(i = 1;i <= 26;++ i)
		if(!h[i])
		{
			printf("Failed");
			return 0;
		}
	len = strlen(s3 + 1);
	for(i = 1;i <= len;++ i)
		putchar(f[s3[i] - 'A' + 1] + 'A' - 1);	
	return 0;
}
