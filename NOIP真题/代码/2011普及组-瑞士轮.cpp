#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int n,r,q,s[200005],w[200005],a[200005],b[200005],m[200005];
bool cmp(int a,int b)
{
	if(s[a]==s[b]) return a<b;
	else return s[a]>s[b];
}
int main()
{
	scanf("%d%d%d",&n,&r,&q);
	for(int i=1;i<=2*n;i++) m[i]=i;
	for(int i=1;i<=2*n;i++) scanf("%d",&s[i]);
	for(int i=1;i<=2*n;i++) scanf("%d",&w[i]);
	stable_sort(m+1,m+2*n+1,cmp);
	for(int i=1;i<=r;i++)
	{
		int tot1=0,tot2=0;
		for(int j=1;j<=2*n;j+=2)
		{
			if(w[m[j]]>w[m[j+1]])
			{
				s[m[j]]++;
				a[++tot1]=m[j];
				b[++tot2]=m[j+1];
			}
			else
			{
				s[m[j+1]]++;
				a[++tot1]=m[j+1];
				b[++tot2]=m[j];
			}
		}
		merge(a+1,a+1+tot1,b+1,b+tot2+1,m+1,cmp);//πÈ≤¢≈≈–Ú(STL) 
//		stable_sort(m+1,m+2*n+1,cmp);
	}
//	for(int i=1;i<=2*n;i++) cout<<m[i]<<' ';
	printf("%d",m[q]);
}
