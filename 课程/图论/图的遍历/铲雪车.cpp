#include<cmath>
#include<iostream>
using namespace std;

int main()
{
	int nil;
	long long x1,y1,x2,y2,m,h;
	double s=0;
	cin >> nil >> nil;
	while(cin >> x1 >> y1 >> x2 >> y2)
		s+=sqrt(pow(x2-x1,2)+pow(y2-y1,2));
	s = s * 2 / 1000 / 20;
	h = (long long)s;
	m = s = (s-h)*60;
	if(s-m >= 0.5) 
		m++;
	cout << h << ':';
	if(m<10) cout << "0";
	cout << m;
	return 0;
}
