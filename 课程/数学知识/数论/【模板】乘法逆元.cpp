#include<cstdio>
long long inv[3000005]; //inv[i]��ʾi����Ԫ [i����Ԫ��Ϊ��i^(-1) mod pͬ�����] 
//a/b mod p = a * b^(-1) mod p = a * inv[b] mod p 

int main()
{
    int n;
    register int i;
    long long p;
    scanf("%d%lld",&n,&p);
    inv[1] = 1;
    printf("1\n");
    for(i = 2;i <= n;++ i)
    {
        //��p = i * k + r,��p / i = k,p % i = r    ==����ͬ��
        //i * k + r == 0 (mod p)
        //i * k * r^(-1) * i^(-1) + r * r^(-1) * i^(-1) == 0 (mod p)
        //k * r^(-1) + i^(-1) == 0 (mod p)
        //i ^ (-1) == -k * r^(-1) (mod p)
        //inv[i] == 0 - (p / i * (p % i)^(-1)) (mod p)
        //inv[i] == 0 - (p / i * inv[p % i]) + p (mod p)
        //inv[i] == p - (p / i * inv[p % i])
        inv[i] = p - (p / i * inv[p % i]) % p;
        printf("%lld\n",inv[i]);
    }
    return 0;
}
