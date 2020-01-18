#include<bits/stdc++.h>
using namespace std;
int f[23],n;
int main()
{
	scanf("%d",&n);f[0]=f[1]=1;
	for(int i=2;i<=n;i++)       //f[0]=f[1]=1 
		for(int j=0;j<i;j++)    //f[n]=f[0]*f[n-1]+f[1]*f[n-2]+....+f[n-2][1]+f[n-1][0] 
			f[i]+=f[j]*f[i-j-1];//¿¨ÌØÀ¼Êý 
	printf("%d",f[n]);
}
