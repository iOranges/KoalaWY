#include <bits/stdc++.h>
using namespace std;
char s[200];//����n
int ans[101];//��
int a[101],b[101],c[101],temp[101];//Ч��������
void mul(int a[], int b[], int bv, int c[],int rv)//low����
//       a*b=c       bv-->b��λ��   rv-->���λ��&&av(�ֶ�ɾȥ)
{
    for(register int i=0;i<rv;++i) c[i]=0;
    for(register int i=0;i<bv;++i)
    {
        if (b[i])
        {
            for(register int j=0;j<rv-i;++j)
            {
                c[i+j]=a[j]*b[i]+c[i+j];
                c[i+j+1]=c[i+j+1]+c[j+i]/10;
                c[i+j]=c[i+j]%10;
            }
        }
    }
}
int main()
{
    int k,dq,num;
    cin>>s>>k;
    int len=strlen(s);
    for(register int i=0;i<len;i++) a[len-i-1]=s[i]-'0';//����洢��int��
    for(register int i=0;i<k;i++) temp[i]=a[i];//��һ��temp����洢�Ա���ÿ�γ˷����¸�ֵ 
    ans[0]=1;
    for(register int i=0;i<k;i++)//i��ʾ���˵ڼ�λ
    {
        for(register int j=0;j<=i;j++) b[j]=temp[j];   
        dq=b[i];//dq��ʾ��ǰλ������
        num=0;
        do
        {
            mul(a,b,i+1,c,i+1);
            num++;
            for(register int n=0;n<k;n++)  b[n]=c[n];
        }while(num<10&&b[i]!=dq);
        //����ѳ���ѭ��������||ÿһλ���Ѿ�����10��������δѭ�����ж�û��ѭ���ڣ�����
        if(b[i]!=dq)//û��ѭ����
        {
            cout<<-1<<endl;
            return 0;
        }
        for(register int j=0;j<k;j++) b[j]=a[j];
        //��b����a�Ȼ�˷� 
        //��ʱnumΪ������ı�λѭ������
        for(register int j=0;j<num-1;j++)
        {
            mul(a,b,k,c,k);
            for(register int n=0;n<101;n++) a[n]=c[n];
        }
		//����a
        mul(ans,&num,1,c,101);
        for(register int n=0;n<101;n++) ans[n]=c[n];
        //ans���ϵ�ǰλ����ѭ������������ans
    }
    int t=100;
    while(!ans[t]) t--;//ȥ��ǰ��0
    while(t>=0)
    {
        cout<<ans[t];//���ans
        t--;
    }
    return 0;
}
