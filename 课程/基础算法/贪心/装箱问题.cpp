#include<iostream>
using namespace std;
int cc[4]={0,5,3,1},i,j;
int main()
{
	int a,b,c,d,e,f;
	while(true)
	{
/*		bool zero = true;
		for(i=1;i<=6;i++)
		{
			cin >> a[i];
			if(a[i]!=0)
				zero = false;
		}
		if(zero) break;*/
		cin >> a >> b >> c >> d >> e >> f;
		if(a+b+c+d+e+f==0)  break;
		int n = f+e+d+(c+3)/4;
		int m = 5 * d+cc[c%4];
		if(b > m) n += (b-m+8)/9;
		int q = 36 * n - 36 * f - 25 * e -16 * d - 9 * c - 4 * b;
		if(a > q) n+=(a-q+35)/36;
		cout << n << endl; 
	}
	return 0;
}
