#include <bits/stdc++.h>
/*
wdnm��ˮ��WA��3��..
ע��1:ֻȥ��ǰ��0!!! 
ע��2:a=0���0!!!
*/
using namespace std;
int a,b;
bool flag = true;
int main()
{
	cin >> a;
	if (!a)
	{
		cout << 0;
		return 0;
	}
	if (a < 0)
	{
		cout << "-";
		a = abs(a); 
	}
	while (a)
	{
		b += a % 10;
		a /= 10;
		b *= 10;
	}
	b /= 10;//��*�˸�10 
	cout << b;
}
