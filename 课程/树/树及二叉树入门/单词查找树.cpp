#include<string>
#include<iostream>
using namespace std;
string ch[8001];
int main()
{
	int i,n=0,j,len;
	while(cin >> ch[++n]);
	n-=1;
	for(i=1;i<n;i++)
		for(j=i+1;j<=n;j++)
			if(ch[i]>ch[j])
				swap(ch[i],ch[j]);
	len = ch[1].length();
	for(i=2;i<=n;i++)
	{
		j=0;
		while(ch[i][j]==ch[i-1][j]&&j<ch[i-1].length())
			j++;
		len+=ch[i].length()-j;
	}
	cout << len+1;
	return 0;
 } 
