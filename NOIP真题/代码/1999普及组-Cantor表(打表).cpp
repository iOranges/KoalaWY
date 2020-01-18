#include<bits/stdc++.h>
using namespace std;
int n,i;
int main()
{
	scanf("%d",&n);
	while(i<n)
	{
		n-=i;
		i++;
	}
	if(i%2==0) printf("%d/%d",n,i+1-n);
	else printf("%d/%d",i+1-n,n);
}
