#include<cmath>
#include<iostream>
char tree[1001];
using namespace std;
string a;
int main()
{
	int i=1,n,m=0;
	cin >> a;
	n = a.length();
	while(n>m)
	{
		m+=pow(2,i-1);
		i++;
	}
	string b(m-n,'#');
	a += b;
	for(i=0;i<m;i++)
		tree[i+1] = a[i];
	i = m;
	while(i!=1)
	{
		if((tree[i-1]=='#'&&tree[i]!='#')||(tree[i-1]!='#'&&tree[i]=='#'))
		{
			cout << "No";
			return 0;
		}
		i-=2;
	}
	cout << "Yes";
	return 0;
 } 
