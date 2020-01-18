#include<iostream>
#include<cstring>
using std::cin;
using std::cout;
const int mod = 10000;
char a[500];
long long f(int i)
{
	if(i == 0) return 1;
	int temp = f(i/2) % mod;
	temp = (temp*temp) % mod;
	if(i%2 == 1) temp = (temp * 2011) % mod;
	return temp;
}

int main()
{
    int n,len,i,k,p=0;
    cin >> n;
    for(k=1;k<=n;k++)
    {
        cin >> a;
        len = strlen(a);
        p = 0;
        for(i=len-4;i<len;++i)
        	if(i>=0)
        		p=10 * p + a[i] - 48;
        cout << f(p) << '\n';
    }
    return 0;
}
