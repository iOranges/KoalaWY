#include<bits/stdc++.h>
using namespace std;
int s,t,w,tot;
char ss[30];
int main()
{
	scanf("%d%d%d%s",&s,&t,&w,ss);
	for(int i=1;i<=5;i++)
	{
		ss[w-1]++;         //从低位开始加
		for(int j=w-1;j>=0;j--)
		{
			if(ss[j]>t+96-tot) ss[j-1]++;
			else
			{
				for(int k=j+1;k<=w-1;k++) ss[k]=ss[k-1]+1;
				break;
			}
			tot++;
		}
		cout<<ss<<endl;
		tot=0;
	}
}
