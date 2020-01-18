#include<cstdio>
#include<cstring>
#define swap(x,y) do{int temp=x;x=y;y=temp;}while(0)
int a[301];
bool g[301][301];

int main()
{
	int n,i,len,j,k;
	char ch[301];
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n;i++)
	{
		scanf("%s",ch);
		len = strlen(ch);
		for(j=0;j<len;j++)
			if(ch[j]=='1') 
				g[i][j] = true;
	}
	for(k=0;k<n;k++)
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)		
				if(!g[i][j]&&j!=k&&i!=k&&i!=j)
					g[i][j] = (g[i][k] && g[j][k]);
	for(i=0;i<n;i++)
		for(j=i+1;j<n;j++)
			if(g[i][j]&&a[i]>a[j])
				swap(a[i],a[j]);	
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	return 0;
}
