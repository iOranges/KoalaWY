#include<cstdio>
int f[1001][2];
int main()
{
    int n,x=9,i;
    f[1][1]=1;
    f[1][0]=9;
    scanf("%d",&n);
    for(i=2;i<=n;i++)
    {
        if(i==n)	x--;
        f[i][0]=(f[i-1][0]*x+f[i-1][1])%12345;
        f[i][1]=(f[i-1][1]*x+f[i-1][0])%12345; 
    }
    printf("%d",f[n][0]);
    return 0; 
}
