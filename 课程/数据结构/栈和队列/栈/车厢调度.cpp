#include<iostream>
using std::cin;
using std::cout;
int a[1001],b[1001];
int main()
{
	int n,i,top=0,train=1;
	cin >> n;
	for(i=1;i<=n;i++)
		cin >> a[i];
	for(i=1;i<=n;i++)
	{
		while(train<=a[i])
			b[++top] = train++;
		if(b[top] == a[i])
			top--;
		else{
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
	return 0;
} 
