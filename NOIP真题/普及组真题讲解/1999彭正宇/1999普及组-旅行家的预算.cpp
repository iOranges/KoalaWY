#include<bits/stdc++.h>
using namespace std;
double d[10],price[10],start,d1,c,d2,p,minn=99999,l,fee;//l ����  fee ������Ǯ
int n,k;   //k��ʾÿ�ξ���ʱ�����ĸ�����վ 
int main()
{
	scanf("%lf%lf%lf%lf%d",&d1,&c,&d2,&p,&n);price[0]=p;
	double x=c*d2;  //xΪ����������� 
	for(int i=1;i<=n;i++) scanf("%lf%lf",&d[i],&price[i]);
	for(int i=1;i<=n;i++)
		if(d[i]-d[i-1]>x) {cout<<"No Solution";return 0;}
	while(d1-start)
	{
		for(int i=k+1;d[i]-start<=x&&i<=n;i++)
			if(price[i]<minn) {minn=price[i];k=i;}  //k��¼ѡ������վ�±� 
		if(minn<=p) {fee+=((d[k]-start)/d2-l)*p;l=(d[k]-start)/d2;}
		//��Χ�ڵļ���վ���Լ������ˣ��Ǿ�ʹ�ӵ��͸պ���֧�ֵ����������վ
		else if(d1-start>x) {fee+=(c-l)*p;l=c;}
		//�������ָ���Ƿ�Χ�ڵļ���վ�����Լ��󣬲����޷�һ�ε����յ㣬����Ӧ�����Լ��������վֱ�Ӽ���
		else {fee+=((d1-start)/d2-l)*p;break;}
		//�������ָ���Ƿ�Χ�ڵļ���վ�����Լ��󣬵���һ�ε����յ㣬���Ҿ�ֱ�ӱ����յ�
		l-=(d[k]-start)/d2;start=d[k];p=minn;minn=99999;  //p�趨Ϊ֮ǰһ������Ǯ 
	}
	printf("%.2lf",fee);
}
