#include<bits/stdc++.h>
using namespace std;
struct grade{int k,s;}a[6666];
int n,m,line,temp,i;
bool cmp(grade a,grade b)
{
	if(a.s>b.s) return true;//按成绩从大到小排列 
	else if(a.s<b.s) return false;
	else//若成绩相等则按学号从小到大排列 
	{
		if(a.k<b.k) return true;
		else return false;
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)
		scanf("%d%d",&a[i].k,&a[i].s);
	sort(a+1,a+n+1,cmp);//进行排序 
	temp=(int)m*1.5;//划定分数线 
	line=a[temp].s;//该分数线的分数 
	i=1;
	while(1)
	{
		if(a[i].s<line)//记录下最后一个比分数线高的人的位置 
		{
			--i;
			break;
		}
		++i;
	}
	printf("%d %d\n",line,i);//输出分数线分数与人数 
	for(int j=1;j<=i;j++)
		printf("%d %d\n",a[j].k,a[j].s);//按序输出 
}
