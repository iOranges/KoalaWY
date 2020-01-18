#include <bits/stdc++.h>
/*
中缀转后缀用栈来实现,后缀表达式用队列承接 
然后动归... 
动态转移方程是真的难..
说实话我也是看了题解才弄明白这个方程(真的明白了吗..)
*/
using namespace std;
stack <char > sign;//输入的符号
queue <char > result;//转换后的表达式,我们用'!'表示这里有个数字要算 
char x;
string s;
int p = 10007,qwq,dp[2][2333333];//分别表示等于0 1的方案 
int main()
{
	result.push('!');//第一位肯定需要一个数字哒~
	int n;
	cin >> n >> s;
	for (int i = 0;i < n;i++)
	{
		if (s[i] == '*' || s[i] == '(')//优先级大直接push进去 
		{
			sign.push(s[i]);
		}
		if (s[i] == '+')//这个挺小的 
		{
			while(!sign.empty() && sign.top() == '*')//乘号优先级比他大,肯定先算乘号的再看这个加号 
			//也有可能前面没东西了,判断下empty 
			{
				x = sign.top();
				result.push(x);//队列后跟上现在的符号 
				sign.pop();//这个符号没用了再见 
			}
			sign.push(s[i]);//这个后面还要用 
		}
		if (s[i] == ')')//都看到右括号了就帮他找找cp吧(雾) 
		{
			while (sign.top() != '(')//这些都不是他的cp(一脸嫌弃) 
			{
				x = sign.top();
				result.push(x);//但是队列不嫌弃啊qwq,那就放进队列吧 
				sign.pop();//不是cp就再见 
			}
			sign.pop();//这个是cp!那就和他双宿双飞(雾) 
		}
		if (s[i] != '(' && s[i] != ')')//我的栈里不可能有括号(雾),都被上面那个给去掉了,就不存在括号后有数字了 
		{
			result.push('!');//但是其他的还是要的 
		}
	}
	while (!sign.empty())//残留物处理 
	{
		x = sign.top();
		result.push(x);
		sign.pop();
	}
	while(!result.empty())//开始计算! 
	{
		x = result.front();
		result.pop();
		//以qwq记录位置 
		if(x == '!')//这个是数字 
		{
			qwq++;//这里是数字,不会进行计算,并且增加了1个数字,那么位置肯定+1 
			dp[0][qwq] = 1;//方案肯定为1(你填个0就行啦..) 
			dp[1][qwq] = 1;//方案肯定为1(你填个1就行啦..)
		}
		
/*************************************************************************************
 *		dp[0][qwq]和dp[1][qwq]的顺序切记不可颠倒!									 *
 *		因为在 x == '*' 的情况中dp[0][qwq]更新要用到dp[1][qwq]的初始值 				 *
 *		所以dp[1][qwq]要在dp[0][qwq]之后更新										 *
 *		(在 x == '+' 中也是如此)													 *
 *************************************************************************************/
 
		else if(x == '*')//这个是乘号 
		{
			qwq--;//这里是运算符,想要计算就需要把这个符号插在2个数字之间,并且计算后会消耗1个数字,所以qwq-- 
			//dp[0][当前位置]代表在当前位置最终求得的值为0的情况总数 
			//dp[1][当前位置]代表在当前位置最终求得的值为1的情况总数
			//DP方程思路来源为题目所给的图像
			//-----------------------------------------------------------------------------------
			dp[0][qwq] = (dp[0][qwq + 1] * dp[1][qwq] + dp[0][qwq] * dp[1][qwq + 1]//这个是DP方程 
			+ dp[0][qwq] * dp[0][qwq + 1]) % p;
			dp[1][qwq] = (dp[1][qwq] * dp[1][qwq + 1]) % p;
			//-----------------------------------------------------------------------------------
		}
		else if(x == '+')//这个是加号 
		{
			qwq--;//这里是运算符,想要计算就需要把这个符号插在2个数字之间,并且计算后会消耗1个数字,所以qwq-- 
			//dp[0][当前位置]代表在当前位置最终求得的值为0的情况总数 
			//dp[1][当前位置]代表在当前位置最终求得的值为1的情况总数
			//DP方程思路来源为题目所给的图像
			//-----------------------------------------------------------------------------------
			dp[1][qwq] = (dp[0][qwq] * dp[1][qwq + 1] + dp[0][qwq + 1] * dp[1][qwq]//这个也是DP方程 
			+ dp[1][qwq] * dp[1][qwq + 1]) % p;
			dp[0][qwq] = (dp[0][qwq] * dp[0][qwq + 1]) % p;
			//-----------------------------------------------------------------------------------
		}
	}
	printf("%d",dp[0][1]);//算到最后位置为1,或者也可以 printf("%d",dp[0][qwq])
}
