#include <bits/stdc++.h>
using namespace std;
char s[200];//读入n
int ans[101];//答案
int a[101],b[101],c[101],temp[101];//效果在下面
void mul(int a[], int b[], int bv, int c[],int rv)//low精乘
//       a*b=c       bv-->b的位数   rv-->结果位数&&av(手动删去)
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
    for(register int i=0;i<len;i++) a[len-i-1]=s[i]-'0';//倒序存储并int化
    for(register int i=0;i<k;i++) temp[i]=a[i];//用一个temp数组存储以便于每次乘方重新赋值 
    ans[0]=1;
    for(register int i=0;i<k;i++)//i表示到了第几位
    {
        for(register int j=0;j<=i;j++) b[j]=temp[j];   
        dq=b[i];//dq表示当前位的数字
        num=0;
        do
        {
            mul(a,b,i+1,c,i+1);
            num++;
            for(register int n=0;n<k;n++)  b[n]=c[n];
        }while(num<10&&b[i]!=dq);
        //如果已出现循环，跳出||每一位上已经做了10次运算仍未循环，判断没有循环节，跳出
        if(b[i]!=dq)//没有循环节
        {
            cout<<-1<<endl;
            return 0;
        }
        for(register int j=0;j<k;j++) b[j]=a[j];
        //将b换成a等会乘方 
        //此时num为已求出的本位循环次数
        for(register int j=0;j<num-1;j++)
        {
            mul(a,b,k,c,k);
            for(register int n=0;n<101;n++) a[n]=c[n];
        }
		//更新a
        mul(ans,&num,1,c,101);
        for(register int n=0;n<101;n++) ans[n]=c[n];
        //ans乘上当前位数的循环次数并更新ans
    }
    int t=100;
    while(!ans[t]) t--;//去掉前导0
    while(t>=0)
    {
        cout<<ans[t];//输出ans
        t--;
    }
    return 0;
}
