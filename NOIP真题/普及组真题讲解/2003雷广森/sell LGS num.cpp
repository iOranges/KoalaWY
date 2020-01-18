#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1005;
const int base=100000;
int k=0,num=0,soli=1;char a[1000000];
struct bign{
    ll len,s[maxn];//len:长度 maxn:位数
    bign(){len=1;memset(s,0,sizeof s);}//                      -----------------------------------①构造函数:初始化
    void zero(){while(len>1&&s[len]==0) len--;}//              -----------------------------------②去掉高位0
    void write(char a[]){//                                    -----------------------------------③存入:四个一位
        int lena=strlen(a);
        int k=1;
        for(int i=0;i<lena;i++){
            s[len]+=(a[lena-i-1]-'0')*k;k=k*10;//逆序输入后正序存入;
            if(k==base) len++,k=1;}//k:计数 乘法 
    }
    void print(){//第一位不得这么弄 ↓
        for(int i=100;i>=1;i--){
            printf("%05lld",s[i]);
            if(i%10==1) putchar('\n');
        }//                                                    -----------------------------------④高精输出
    }
    void read(){char a[maxn*5];scanf("%s",a);write(a);}//      -----------------------------------⑤高精读入
    void operator=(int b){//                                   -----------------------------------⑥重载等号
        char a[maxn*5];
        sprintf(a,"%d",b);
        write(a);
    }
    bool operator<(bign b){//                                   -----------------------------------一：重载小于
        if(len<b.len) return true;
        if(len>b.len) return false;//比位数
        for(int i=len;i>=1;i--){//一位一位地比
            if(s[i]<b.s[i]) return true;
            else if(s[i]>b.s[i]) return false;
        }return false;//相等
    }
    bool operator>(bign b){//                                  -----------------------------------二：重载大于
        return b<*this;}
    bool operator>=(bign b){//                                 -----------------------------------三：重载大等
        return !(*this<b);}
    bool operator==(bign b){//                                 -----------------------------------四：重载等等
        return !(*this>b)&&!(*this<b);}
    bool operator!=(bign b){//                                 -----------------------------------五：重载非等
        return (*this>b)||(*this<b);}
    bool operator<=(bign b){//                                 -----------------------------------六：重载小等
        return !(*this>b);}
    bool operator!=(int b){//                                  -----------------------------------1：重载int非等
        bign c;c=b;return *this!=c;}
    bool operator>(int b){//                                   -----------------------------------2：重载int大于
        bign c;c=b;return *this>c;}
    bool operator<(int b){//                                   -----------------------------------3：重载int小于
        bign c;c=b;return *this<c;}
    bool operator<=(int b){//                                  -----------------------------------4：重载int小等
        bign c;c=b;return *this<=c;}
    bool operator>=(int b){//                                  -----------------------------------5：重载int大等
        bign c;c=b;return *this>=c;}
    bool operator==(int b){//                                  -----------------------------------6：重载int等等
        bign c;c=b;return c==*this;}
    bign operator+(bign b){
        bign c;
        c.len=max(len,b.len)+1;
        for(int i=1;i<c.len;i++){
            c.s[i]+=s[i]+b.s[i];
            c.s[i+1]=c.s[i]/base;
            c.s[i]%=base;}
        c.zero();
        return c;}
    bign operator+(int b){
        bign c;c=b;
        return *this+c;}
    bign operator-(bign b){
        bign c;c.len=len;
        for(int i=1;i<=len;i++){
            c.s[i]=s[i]-b.s[i];
            if(c.s[i]<0) c.s[i]+=base,s[i+1]--;}
        c.zero();
        return c;}
    bign operator-(int b){
        bign c;c=b;
        return *this-c;}
    bign operator*(bign b){
        bign c;
        c.len=len+b.len+1;
        for(int i=1;i<=len;i++){
            for(int j=1;j<=b.len;j++){
                if(i+j>500) break;
                c.s[i+j-1]+=s[i]*b.s[j];
                if(c.s[i+j-1]>=base){
                    c.s[i+j]+=c.s[i+j-1]/base;
                    c.s[i+j-1]-=c.s[i+j-1]/base*base;}
            }
        }
        c.zero();
        return c;}
    bign operator*(int b){//                                 -----------------------------------6：重载*
        bign c;c=b;
        return *this*c;}
    bign operator/(bign b){
        bign c;bign temp;
        for(int i=len;i>=1;i--){//                           -----------------------------------6：重载/
            temp=temp*base+s[i];//将/转换为 *（二分找商）
            c.len=len;
            int l=0,r=base,mid,ans;
            while(l<=r){
                mid=(l+r)/2;
                if(b*mid<=temp){
                    ans=mid;
                    l=mid+1;}
                else
                    r=mid-1;
            }
            temp=temp-b*ans;
            c.s[i]=ans;}
        c.zero();
        return c;}
    bign operator/(int b){
        bign c;c=b;
        return *this/c;}
    bign operator%(bign b){
        return *this-*this/b*b;}
    bign operator%(int b){
        bign c;c=b;
        return *this%c;}
};
int main(){
    bign use;
    use=2;
    bign mo,sum;
    sum=1;
    cin>>num;
    printf("%lld\n",(ll)(num*0.30102999566)+1);
    while(num){
        if(num&1) sum=sum*use%mo;
        use=use*use;
        num/=2;
    }
    sum=sum-1;
    sum.print();
    return 0;
}
