#include<bits/stdc++.h>
using namespace std;
int x,y,z,cnt;
bool rn(int a)
{
	if(!(a%400)) return 1;
	else if(!(a%100)) return 0;
	else if(!(a%4)) return 1;
	return 0;
}
int main()
{
	scanf("%d%d",&x,&y);
	z=x/10000000;
	for(int i=0;i<=1;i++)
	{
		int m=9,n=1;
		if(i)m=2,n=0;
		for(int j=n;j<=m;j++)
			for(int k=0;k<=3;k++)
				for(int l=z;l<=9;l++)
				{
					int w=l*1000+k*100+j*10+i;
					int q=k*10+l; 
					int r=i*10+j;
					if(q>31 || q==0 || r==0) continue;
					if(r==2 && !rn(w) && q>=29) continue;
					if(r==2 && rn(w) && q>29) continue;
					if((r==4 || r==6 || r==9 || r==11) && q==31) continue; 
					int t=10000*w+i*1000+j*100+k*10+l;
					if(t>y || t<x) continue;
					++cnt;
				}
	}
	printf("%d",cnt);
	return 0;
}
