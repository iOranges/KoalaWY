#include<iostream>
using namespace std;
long long b,p,k;
long long f(int i)
{
	if(i == 0) return 1;
	int b2 = f(i/2) % k;
	b2 = (b2*b2) % k;
	if(i%2 == 1) b2 = (b2 * b) % k;
	return b2;
}

int main()
{
	cin >> b >> p >> k;
	int b2=b;
	b%=k;
	cout << b2 << "^" << p << " mod " << k << "=" << f(p);
	return 0;
}
