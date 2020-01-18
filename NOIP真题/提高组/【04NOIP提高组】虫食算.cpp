#include<ctime>
#include<cstdio>
char a[30],b[30],c[30];
int n,s[30],res[30],p[30],tot,dic[30],use[30],app[30],flag;
bool check()
{
	register int i;
	for(i = n;i >= 1;-- i)
	{
		if(!dic[a[i]]||!dic[b[i]]||!dic[c[i]]) continue;
		if((s[a[i]] + s[b[i]]) % n != s[c[i]])
			if((s[a[i]] + s[b[i]] + 1) % n != s[c[i]])
				return false;
	}
	return true;
}

bool judge()
{
	register int i;
	int pre = 0,now;
	for(i = n;i >= 1;-- i)
	{
		now = s[a[i]] + s[b[i]] + pre;
		pre = now >= n;
		if(s[c[i]] ^ (now - (pre ? n : 0)))
			return false;
	}	
	return true;
}

void dfs(int x)
{
	if(flag) return;
	if(x == n&&judge()) 
	{
		for(int i = 0;i < n;++ i)
			res[i] = s[i];
		flag = 1;
		return;
	} 
	for(int i = n - 1;i >= 0;-- i)
		if(!use[i])
		{
			s[p[x + 1]] = i;
			dic[p[x + 1]] = 1;
			use[i] = 1;
			if(check())
				dfs(x + 1);
			dic[p[x + 1]] = 0;
			use[i] = 0;
		}
}

int main()
{
	scanf("%d",&n);
	register int i;
	scanf("%s%s%s",a + 1,b + 1,c + 1);
	for(i = n;i > 0;-- i)
	{
		a[i] -= 'A',b[i] -= 'A',c[i] -= 'A';
		if(!app[a[i]]) p[++tot] = a[i],app[a[i]] = 1;
		if(!app[b[i]]) p[++tot] = b[i],app[b[i]] = 1;
		if(!app[c[i]]) p[++tot] = c[i],app[c[i]] = 1;
	}
	dfs(0);
	for(i = 0;i < n;++ i)
		printf("%d ",res[i]);
	return 0;
}
