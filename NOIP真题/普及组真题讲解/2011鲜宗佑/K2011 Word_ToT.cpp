#include <bits/stdc++.h>
/*
wdnm做了40分钟.. 
*/
using namespace std;
string s1,s2;
int ans,length,aannss;
int main()
{
	getline(cin,s1);
	transform(s1.begin(),s1.end(),s1.begin(),::tolower);//全部变小写,就很牢固(二声) <其实是太懒不想写if>
	int l1 = s1.length();
	getline(cin,s2);
	transform(s2.begin(),s2.end(),s2.begin(),::tolower);//全部变小写,就很牢固(二声) <其实是太懒不想写if>
	int l2 = s2.length();
	for (int i = 0;i <= l2 - l1;i++)
	{
		if (i && s2[i - 1] != ' ') continue;//这个逼前面没有空格就不是单词开头,就不够好 
		for (int j = 0;j < l1;j++)
		{
			if (s2[i + j] != s1[j]) break;
			if (j == l1 - 1)
			{
				if (s2[i + j + 1] == ' ')//这个逼不是空格就不是单词结尾,就不扎实 
				{
					ans++;
					if (ans == 1)//这个逼等于1才是第一个,就很优秀 
					{
						aannss = i;
					}
				}
			}
		}
	}
	if (ans) cout << ans << " " << aannss;
	else cout << -1;
}
