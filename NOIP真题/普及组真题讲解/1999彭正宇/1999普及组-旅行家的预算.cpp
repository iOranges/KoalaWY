#include<bits/stdc++.h>
using namespace std;
double d[10],price[10],start,d1,c,d2,p,minn=99999,l,fee;//l 油量  fee 所花的钱
int n,k;   //k表示每次决策时处于哪个加油站 
int main()
{
	scanf("%lf%lf%lf%lf%d",&d1,&c,&d2,&p,&n);price[0]=p;
	double x=c*d2;  //x为油箱最大容量 
	for(int i=1;i<=n;i++) scanf("%lf%lf",&d[i],&price[i]);
	for(int i=1;i<=n;i++)
		if(d[i]-d[i-1]>x) {cout<<"No Solution";return 0;}
	while(d1-start)
	{
		for(int i=k+1;d[i]-start<=x&&i<=n;i++)
			if(price[i]<minn) {minn=price[i];k=i;}  //k记录选定加油站下标 
		if(minn<=p) {fee+=((d[k]-start)/d2-l)*p;l=(d[k]-start)/d2;}
		//范围内的加油站比自己还便宜，那就使加的油刚好能支持到达这个加油站
		else if(d1-start>x) {fee+=(c-l)*p;l=c;}
		//这种情况指的是范围内的加油站都比自己贵，并且无法一次到达终点，所以应该在自己这个加油站直接加满
		else {fee+=((d1-start)/d2-l)*p;break;}
		//这种情况指的是范围内的加油站都比自己贵，但能一次到达终点，那我就直接奔向终点
		l-=(d[k]-start)/d2;start=d[k];p=minn;minn=99999;  //p设定为之前一步的油钱 
	}
	printf("%.2lf",fee);
}
