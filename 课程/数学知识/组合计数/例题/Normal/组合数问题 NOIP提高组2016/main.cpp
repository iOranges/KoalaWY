#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>

using namespace std;

int n,m,k;

int kfac[5],kcnt[5],kidx;
int numfac[2010][5];
int ans[2010][2010];
void prelude() {
    // �ֽ�������k
    for( int i = 2; k > 1; ++i ) if( k % i == 0 ) {
        kfac[kidx] = i;
        while( k % i == 0 ) {
            k /= i; kcnt[kidx]++;
        }
        ++kidx;
    }
    // ��2-2000�ֽ���������ֻ�ֽ�k���
    for( int i = 2; i <= 2000; ++i )
    for( int j = 0; j < kidx; ++j ) if( i % kfac[j] == 0 ) {
        int num = i;
        while( num % kfac[j] == 0 ) {
            num /= kfac[j]; numfac[i][j]++;
        }
    }
    // ǰ׺�ͼ�n!��k���������
    for( int i = 3; i <= 2000; ++i )
    for( int j = 0; j < kidx; ++j )
        numfac[i][j] += numfac[i-1][j];
    // ����
    for( int i = 1; i <= 2000; ++i ) // ����C(i,j)
    for( int j = 1; j <= i; ++j ) {
        ans[i][j] = 1;
        for( int k = 0; k < kidx; ++k )
            if( numfac[i][k] - numfac[j][k] - numfac[i-j][k] < kcnt[k] ) ans[i][j] = 0;
    }
    // ��άǰ׺�ͼ���
    for( int i = 1; i <= 2000; ++i ) for( int j = 2; j <= 2000; ++j ) ans[i][j] += ans[i][j-1];
    for( int i = 2; i <= 2000; ++i ) for( int j = 1; j <= 2000; ++j ) ans[i][j] += ans[i-1][j];
}

int main() {
    int T; scanf( "%d%d", &T, &k );
    prelude();
    while( T-- ) {
        int n,m; scanf( "%d%d", &n, &m );
        printf( "%d\n", m>n ? ans[n][n] : ans[n][m] );
    }
    return 0;
}
