#include<cstdio>
#include<algorithm>
#define max(x,y) ((x) > (y) ? (x) : (y))
using std::sort;
struct node{
	int num,id;
	bool operator < (const node b) const{
		return num > b.num;
	}
}p[100];
bool lock[10][10],line[10][10],row[10][10],use[10][10];
int mp[10][10],ans = -1,q[10],ql[10],qr[10],score[10][10] =
{{0,0,0,0,0,0,0,0,0,0},
{0,6,6,6,6,6,6,6,6,6},
{0,6,7,7,7,7,7,7,7,6},
{0,6,7,8,8,8,8,8,7,6},
{0,6,7,8,9,9,9,8,7,6},
{0,6,7,8,9,10,9,8,7,6},
{0,6,7,8,9,9,9,8,7,6},
{0,6,7,8,8,8,8,8,7,6},
{0,6,7,7,7,7,7,7,7,6},
{0,6,6,6,6,6,6,6,6,6}},belong[10][10] =
{{0,0,0,0,0,0,0,0,0,0},
{0,1,1,1,2,2,2,3,3,3},
{0,1,1,1,2,2,2,3,3,3},
{0,1,1,1,2,2,2,3,3,3},
{0,4,4,4,5,5,5,6,6,6},
{0,4,4,4,5,5,5,6,6,6},
{0,4,4,4,5,5,5,6,6,6},
{0,7,7,7,8,8,8,9,9,9},
{0,7,7,7,8,8,8,9,9,9},
{0,7,7,7,8,8,8,9,9,9}};
void dfs(int x,int res,int tot)
{
	if(tot > 81)
	{
		ans = max(ans,res);
		return;
	}
	int i = (x - 1) / 9 + 1,j = (x - 1) % 9 + 1;
	if(lock[i][j])
		dfs(p[tot + 1].id,res + mp[i][j] * score[i][j],tot + 1);
	else for(int k = 1;k <= 9;++ k)
		if(!use[belong[i][j]][k]&&!line[i][k]&&!row[j][k])
		{
			use[belong[i][j]][k] = line[i][k] = row[j][k] = true;
			dfs(p[tot + 1].id,res + k * score[i][j],tot + 1);
			use[belong[i][j]][k] = line[i][k] = row[j][k] = false;
		}
 } 

int main()
{
	register int i,j;
	for(i = 1;i <= 9;++ i)
		for(j = 1;j <= 9;++ j)
		{
			scanf("%d",&mp[i][j]);
			if(mp[i][j]) 
			{
				++ q[belong[i][j]],++ ql[i],++ qr[j];
				lock[i][j] = true;
				use[belong[i][j]][mp[i][j]] = true;
				line[i][mp[i][j]] = true;
				row[j][mp[i][j]] = true;
			}	
		}
	for(i = 1;i <= 9;++ i)
		for(j = 1;j <= 9;++ j)
		{
			int x = (i - 1) * 9 + j;
			p[x].num = q[belong[i][j]] + ql[i] + qr[j];
			p[x].id = x;		
		}
	sort(p + 1,p + 82);
	dfs(p[1].id,0,1);
	printf("%d",ans);
	return 0;
}

