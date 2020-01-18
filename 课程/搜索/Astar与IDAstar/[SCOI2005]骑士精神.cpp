#include<cstdio>
#include<iostream>
#define swap(x,y) (x ^= y ^= x ^= y)
using std::cin;
bool flag;
int goal[6][6]=
{{0,0,0,0,0,0},
{0,1,1,1,1,1},
{0,0,1,1,1,1},
{0,0,0,2,1,1},
{0,0,0,0,0,1},
{0,0,0,0,0,0}};
int mp[6][6],mov[8][2] = {{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{1,-2},{-1,2},{-1,-2}};
int calc()
{
	int cnt = 0;
	register int i,j;
	for(i = 1;i <= 5;++ i)
		for(j = 1;j <= 5;++ j)
			if(mp[i][j] != goal[i][j])
				++ cnt;
	return cnt;
}

void IDA(int x,int y,int maxdep,int dep)
{
	if(dep == maxdep)
	{
		if(!calc()) flag = true;
		return;
	}
	for(int i = 0;i < 8;++ i)
	{
		int xx = x + mov[i][0],yy = y + mov[i][1];
		if(xx < 1||xx > 5||yy < 1||yy > 5) continue;
		swap(mp[x][y],mp[xx][yy]);
		if(dep + calc() <= maxdep)
			IDA(xx,yy,maxdep,dep + 1);
		swap(mp[x][y],mp[xx][yy]);
	}
}

int main()
{
	int t,x,y;
	char ch;
	register int i,j;
	scanf("%d",&t);
	while(t --)
	{
		flag = false;
		for(i = 1;i <= 5;++ i)
			for(j = 1;j <= 5;++ j)
			{
				cin >> ch;
				if(ch == '*') mp[i][j] = 2,x = i,y = j;
				else mp[i][j] = ch - '0';
			}
		for(i = 0;i <= 15;++ i)
		{
			IDA(x,y,i,0);
			if(flag)
			{
				printf("%d\n",i);
				break;
			}
		}
		if(!flag) printf("-1\n");
	}
	return 0;
}
