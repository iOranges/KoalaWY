#include<bits/stdc++.h>
using namespace std;
struct grade{int k,s;}a[6666];
int n,m,line,temp,i;
bool cmp(grade a,grade b)
{
	if(a.s>b.s) return true;//���ɼ��Ӵ�С���� 
	else if(a.s<b.s) return false;
	else//���ɼ������ѧ�Ŵ�С�������� 
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
	sort(a+1,a+n+1,cmp);//�������� 
	temp=(int)m*1.5;//���������� 
	line=a[temp].s;//�÷����ߵķ��� 
	i=1;
	while(1)
	{
		if(a[i].s<line)//��¼�����һ���ȷ����߸ߵ��˵�λ�� 
		{
			--i;
			break;
		}
		++i;
	}
	printf("%d %d\n",line,i);//��������߷��������� 
	for(int j=1;j<=i;j++)
		printf("%d %d\n",a[j].k,a[j].s);//������� 
}
