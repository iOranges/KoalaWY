#include<bits/stdc++.h>
using namespace std;
int xh[11]={1,1,4,4,2,1,1,4,4,2};//���С�� 
int k,b[205],c[205],d[205],p[205],q[205],ss[205],tot1,tot2=2,t;
//d����:�нӸ�����������ת��
//c����:��������ĺ�kλ
//ss����:�洢���
//b����:��¼c���һλѭ����һ��ʱ��c����
//p,q����:����b���� 
//tot1 �����¼c����
//��ѭ����λ�� 
char a[105];
void mul1(int x[],int y[],int z[])//�߾�*�߾� 
{
	for(int i=1;i<=k;i++)
		for(int j=1;j<=k;j++)
		{
			z[i+j-1]+=x[i]*y[j];
			z[i+j]+=z[i+j-1]/10;
			z[i+j-1]%=10;
		}
}
void mul2(int x[],int y,int z[])//�;�*�߾� 
{
	for(int i=1;i<=k;i++)
	{
		z[i]+=x[i]*y;
		z[i+1]+=z[i]/10;
		z[i]%=10;
	}
}
int main()
{
	
	scanf("%s%d",a+1,&k);int len=strlen(a+1);
	for(int i=len;i>=len-k+1;i--) c[++tot1]=a[i]-'0';
	for(int i=1;i<=k;i++) b[i]=c[i];
	for(int i=1;i<xh[c[1]];i++)
	{
		memset(d,0,sizeof(d));
		mul1(b,c,d);
		for(int j=1;j<=k;j++) b[j]=d[j];
	}
	ss[1]=xh[c[1]];
	for(int i=1;i<=k;i++) q[i]=p[i]=b[i];
	while(tot2<=k)
	{
		for(int i=1;i<=k;i++) b[i]=c[i];
		while(t<11)
		{
			memset(d,0,sizeof(d));
			mul1(b,p,d);t++;
			for(int i=1;i<=k;i++) b[i]=d[i];
			if(b[tot2]==c[tot2]) break;
			memset(d,0,sizeof(d));
			mul1(q,p,d);
			for(int i=1;i<=k;i++) q[i]=d[i];
		}
		if(t==11){cout<<-1;return 0;}//���ĳһλѭ������10�λ�δ����ѭ��,�����-1 
		for(int i=1;i<=k;i++) p[i]=q[i];
		memset(d,0,sizeof(d));
		mul2(ss,t,d);
		for(int i=1;i<=100;i++) ss[i]=d[i];
		tot2++;t=0;
	}
	int len1=105;
	while(ss[len1]==0&&len1>1) len1--;//ȥ����λ0 
	for(int i=len1;i>=1;i--) printf("%d",ss[i]);
}
