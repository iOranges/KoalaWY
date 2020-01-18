#include<cstring>
#include<iostream>
using namespace std;
int h[30],f[30];

int main()
{
	memset(f,0xf,sizeof(f));
	h[1] = f[1] = 1;
	int i,j,minn,k,n;
	cin >> n;
	for(i=2;i<=n;i++)
		h[i] = 2*h[i-1]+1;
	for(i=1;i<=n;i++)
		for(j=0;j<=n;j++)
			f[i] = min(f[i],2*f[i-j]+h[j]);	
	cout << f[n] << endl;
	return 0;
}
