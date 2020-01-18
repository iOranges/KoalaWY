#include<iostream>
using namespace std;
int a[1001];
int main()
{
	int top = 0,right = 0;
	char ch;
	bool ok = true;
	while(cin >> ch)
	{
		if(ch == '@') break;
		else if(ch == '(')
			++top;
		else if(ch == ')')
		{
			if(top>0) top--;
			else right++;
		}
	}
	if(right + top==0)
		cout << "YES";
	else 
		cout << "NO";
	return 0;
 } 
