#include <bits/stdc++.h>
/*
wdnm����40����.. 
*/
using namespace std;
string s1,s2;
int ans,length,aannss;
int main()
{
	getline(cin,s1);
	transform(s1.begin(),s1.end(),s1.begin(),::tolower);//ȫ����Сд,�ͺ��ι�(����) <��ʵ��̫������дif>
	int l1 = s1.length();
	getline(cin,s2);
	transform(s2.begin(),s2.end(),s2.begin(),::tolower);//ȫ����Сд,�ͺ��ι�(����) <��ʵ��̫������дif>
	int l2 = s2.length();
	for (int i = 0;i <= l2 - l1;i++)
	{
		if (i && s2[i - 1] != ' ') continue;//�����ǰ��û�пո�Ͳ��ǵ��ʿ�ͷ,�Ͳ����� 
		for (int j = 0;j < l1;j++)
		{
			if (s2[i + j] != s1[j]) break;
			if (j == l1 - 1)
			{
				if (s2[i + j + 1] == ' ')//����Ʋ��ǿո�Ͳ��ǵ��ʽ�β,�Ͳ���ʵ 
				{
					ans++;
					if (ans == 1)//����Ƶ���1���ǵ�һ��,�ͺ����� 
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
