#include<bits/stdc++.h>
const long long mod = 1e9 + 7;
using namespace std;
inline void read(char *s,int &len)
{
	char ch = getchar();len = 0;
	while(ch == '\r'||ch == '\n') ch = getchar();
	while(ch != '\r'&&ch != '\n')
	{
		if(ch != ' ') s[++ len] = ch;
		ch = getchar();
	}
}
char ch[105];
int num[21] = {0,114514,19260817,233,2,911,1331};
long long ans[21];
long long quick_pow(long long a,long long b)
{
	long long ans = 1;
	while(b)
	{
		if(b & 1) ans = ans * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return ans;
}

long long calc(char *s,int l,int r,int a)
{
	register int i;
	int pos = 0,minn = 0x7f7f7f7f,prio = 0,p;
	for(i = r;i >= l;-- i) //从右往左枚举(从左往右算，所以这样枚举可以使在右边(即后算)的运算符优先被选中) 
	{
		p = 0x7f7f7f7f;
		switch(s[i])
		{
			case ')':prio += 100;break;
			case '(':prio -= 100;break;
			case '+':p = prio + 1;break;
			case '-':p = prio + 1;break;
			case '*':p = prio + 2;break;
			case '^':p = prio + 3;break;//分配优先级 
		}
		if(p < minn) minn = p,pos = i; //找到优先级最小的运算符的位置 
	}
	if(!pos) //如果没有运算符(只有括号和数字或未知数) 
	{
		for(i = l;i <= r;++ i) 
			if(s[i] == 'a') return a;//如果有未知数(还可能有括号，所以要从l到r枚举) 
		int x = 0;
		for(i = l;i <= r;++ i)
			if(s[i] >= '0'&&s[i] <= '9')
				x = x * 10 + (s[i] ^ 48);//得到数字 
		return x;
	}
	else switch(s[pos])
	{
		case '^':return quick_pow(calc(s,l,pos - 1,a),calc(s,pos + 1,r,a)) % mod;
		case '*':return calc(s,l,pos - 1,a) * calc(s,pos + 1,r,a) % mod; 
		case '+':return (calc(s,l,pos - 1,a) + calc(s,pos + 1,r,a)) % mod; 
		case '-':return (calc(s,l,pos - 1,a) - calc(s,pos + 1,r,a) + mod) % mod; //递归求解 
	}
}

int main()
{
	int n,len;
	read(ch,len);
	scanf("%d",&n); 
	register int i,j;
	for(i = 7;i <= 20;++ i) 
		num[i] = ((num[i - 1] - num[i - 2] + mod) % mod * 1ll * num[i - 3] % mod + num[i - 4]) % mod;
	for(i = 0;i <= 20;++ i)
		ans[i] = calc(ch,1,len,num[i]);
	for(i = 1;i <= n;++ i)
	{
		read(ch,len);
		bool flag = true;
		for(j = 0;j <= 20;++ j)
			if(ans[j] != calc(ch,1,len,num[j]))
				flag = false;
		if(flag) printf("%c",'A' + i - 1);
	}
	return 0; 
}
