#include<bits/stdc++.h>
using namespace std;
struct node{
  int zero,one;			//�ֱ��ʾ���Ϊ0��1�Ƿ����� 
}q[150005];
int len,t=1;
const int p=10007;
string ss;
stack<char>s;
void mmp(char ch,node &a,node &b)	//һ��Ҫ�ӵ�ַ�� 
{
	if(ch=='+')
	{
		a.one=(a.one*(b.zero+b.one)+a.zero*b.one)%p;
		a.zero=a.zero*b.zero%p;
	}
//	��ʽ:
//	��Z��ʾ������,X0��ʾ�㵱ǰ�ķ�����0����,Y0��ʾ���ʾ��ǰ�淽����0����,X1��Y1ͬ��
//	���ǳ˺�ʱZ0=X0*Y0+X1*Y0+X0*Y1,Z1=X1*Y1
//	�ǼӺ�ʱ��Z0=X0*Y0,Z1=X0*Y1+X1*Y0+X1*Y1
	else
	{
		a.zero=(a.zero*(b.zero+b.one)+a.one*b.zero)%p;
		a.one=a.one*b.one%p;
	}
}
int main()
{
	cin>>len>>ss;ss+=')';
	q[1].zero=q[1].one=1;
	s.push('(');
	for(int i=0;i<=len;i++)
	{
		if(ss[i]=='(') s.push('(');
		else if(ss[i]==')')
		{
			while(s.top()!='(')
			{
				mmp(s.top(),q[t-1],q[t]);
				s.pop(),t--;
			}
			s.pop();
		}
		else
		{
			while(s.top()<=ss[i]&&s.top()!='(')
			{
				mmp(s.top(),q[t-1],q[t]);
				s.pop(),t--;
			}
			s.push(ss[i]);
			q[++t].zero=1;
			q[t].one=1;
		}
	}
	cout<<q[1].zero;
}
