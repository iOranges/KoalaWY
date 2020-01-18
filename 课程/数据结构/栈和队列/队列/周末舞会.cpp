#include<iostream>
using std::cin;
using std::cout;
int a[1001],b[1001];
int main()
{
	int n,m,k,i;
	cin >> n >> m >> k;
	int h1=1,h2=1,t1=n,t2=m;
	for(i=1;i<=n;i++)
		a[i]=i;
	for(i=1;i<=m;i++)
		b[i]=i;
	for(i=1;i<=k;i++)
	{
		cout << a[h1] << " " << b[h2] << '\n';
		t1++,t2++;
		a[t1]=a[h1++];
		b[t2]=b[h2++]; 
	}
	return 0;
}
