#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
vector<int> b;
int a[100001]; 

int main()
{
	int n,i;
	cin >> n;
	for(i=1;i<=n;i++)
	{
		cin >> a[i];
		b.push_back(a[i]);
	}
	sort(b.begin(),b.end());
	b.erase(unique(b.begin(), b.end()), b.end());
	for(i=1;i<=n;i++)
	{
		a[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin() + 1;
		cout << a[i] <<' ';
	}
	return 0;
}
