#include<bits/stdc++.h>
using namespace std;
struct node{
  int zero,one;			//分别表示结果为0或1是方案数 
}q[150005];
int len,t=1;
const int p=10007;
string ss;
stack<char>s;
void mmp(char ch,node &a,node &b)	//一定要加地址符 
{
	if(ch=='+')
	{
		a.one=(a.one*(b.zero+b.one)+a.zero*b.one)%p;
		a.zero=a.zero*b.zero%p;
	}
//	公式:
//	用Z表示方案数,X0表示你当前的方案是0的数,Y0表示则表示你前面方案是0的数,X1，Y1同理
//	当是乘号时Z0=X0*Y0+X1*Y0+X0*Y1,Z1=X1*Y1
//	是加号时则Z0=X0*Y0,Z1=X0*Y1+X1*Y0+X1*Y1
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
