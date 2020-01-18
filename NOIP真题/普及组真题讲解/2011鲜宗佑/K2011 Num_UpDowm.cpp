#include <bits/stdc++.h>
/*
wdnm的水题WA了3次..
注意1:只去除前导0!!! 
注意2:a=0输出0!!!
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
	b /= 10;//多*了个10 
	cout << b;
}
