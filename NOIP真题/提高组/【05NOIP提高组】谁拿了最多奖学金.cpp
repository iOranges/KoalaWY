#include<cstdio>
#include<algorithm>
using std::sort;
struct node{
	int w,id;
	char s[25];
	bool operator < (const node b) const{
		return w != b.w ? w > b.w : id < b.id;
	} 
}p[105];

int calc(int sorce,int judge,bool officer,bool west,int paper)
{
	int money = 0;
	if(sorce > 80 && paper > 0) money += 8000;
	if(sorce > 85 && judge > 80) money += 4000;
	if(sorce > 90) money += 2000;
	if(sorce > 85 && west) money += 1000;
	if(judge > 80 && officer) money += 850;
	return money;
 } 

int main()
{
	int a,b,c,n,sum = 0;
	char c1,c2;
	scanf("%d",&n);
	register int i;
	for(i = 1;i <= n;++ i)
	{
		scanf("%s%d%d %c %c%d",p[i].s,&a,&b,&c1,&c2,&c);
		p[i].id = i;
		p[i].w = calc(a,b,c1 == 'Y',c2 == 'Y',c);
		sum += p[i].w;
	}
	sort(p + 1,p + n + 1);
	printf("%s\n%d\n%d",p[1].s,p[1].w,sum);
	return 0;
 } 
