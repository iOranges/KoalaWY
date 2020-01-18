#include<cstdio>
#define swap(x,y) (x ^= y ^= x ^= y)
bool remov[8][6],hasans;
int mp[10][6],pre[6][8][6],n,order[6][4];
void Drop()
{
	register int i,j,k;
	for(i = 1;i <= 7;++ i)
		for(j = 1;j <= 5;++ j)
			if(!mp[i][j]&&mp[i + 1][j])
			{
				swap(mp[i][j],mp[i + 1][j]);
				k = i - 1;
				while(k > 0&&!mp[k][j])
					swap(mp[k + 1][j],mp[k][j]),-- k;
			}
}

bool Clear()
{
	bool flag = false;
	register int i,j;
	for(i = 1;i <= 7;++ i)
		for(j = 1;j <= 5;++ j)
			if(mp[i][j])
			{
				if(mp[i][j - 1] == mp[i][j]&&mp[i][j + 1] == mp[i][j])
					remov[i][j] = remov[i][j - 1] = remov[i][j + 1] = flag = true;
				if(mp[i - 1][j] == mp[i][j]&&mp[i + 1][j] == mp[i][j])
					remov[i][j] = remov[i + 1][j] = remov[i - 1][j] = flag = true;
			}
	if(!flag) return false;
	for(i = 1;i <= 7;++ i)
		for(j = 1;j <= 5;++ j)
			if(remov[i][j])
				remov[i][j] = mp[i][j] = 0;
	Drop();
	return true;
}

inline void Copy(int step,bool ctrlc)
{
	register int i,j;
	if(ctrlc)
		for(i = 1;i <= 7;++ i)
			for(j = 1;j <= 5;++ j)
				pre[step][i][j] = mp[i][j];
	else 
		for(i = 1;i <= 7;++ i)
			for(j = 1;j <= 5;++ j)
				mp[i][j] = pre[step][i][j];
}

inline void Move(int x,int y,int g)
{
	swap(mp[x][y],mp[x][y + g]);
	Drop();
	while(Clear());
}

inline bool check()
{
	register int i;
	for(i = 1;i <= 5;++ i)
		if(mp[1][i]) return false;
	return true;
}

void dfs(int step)
{
	if(hasans) return;
	if(step > n) 
	{
		if(check())
		{
			register int i;
			for(i = 1;i <= n;++ i)
				printf("%d %d %d\n",order[i][2] - 1,order[i][1] - 1,order[i][3]);
			hasans = true;
		}
		return ;
	}
	Copy(step,true);
	for(int j = 1;j <= 5;++ j)
		for(int i = 1;i <= 7;++ i)
			if(mp[i][j])
			{
				if(j + 1 <= 5&&mp[i][j + 1] != mp[i][j])
				{
					Move(i,j,1);
					order[step][1] = i,order[step][2] = j,order[step][3] = 1;
					dfs(step + 1);
					Copy(step,false);
				}
				if(j - 1 > 0&&!mp[i][j - 1])
				{
					Move(i,j,-1);
					order[step][1] = i,order[step][2] = j,order[step][3] = -1;
					dfs(step + 1);
					Copy(step,false);
				} 
			}
}

int main()
{
	scanf("%d",&n);
	register int i,j;
	for(i = 1;i <= 5;++ i)
		for(j = 1;j <= 8;++ j)
		{
			scanf("%d",&mp[j][i]);
			if(!mp[j][i]) break;
		}
	dfs(1);
	if(!hasans) printf("-1");
	return 0;
}

