#include<iostream>
using namespace std;
int w[5]={0,10,20,50,100};
long long f[10001];
int main()
{
	int n,i,v;
	cin >> n;
	f[0]=1;
	for(i=1;i<=4;i++)
		for(v=w[i];v<=n;v++)
			f[v]+=f[v-w[i]];
	cout << f[n];
	return 0;
}
