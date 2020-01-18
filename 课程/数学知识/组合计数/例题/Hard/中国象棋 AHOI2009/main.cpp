#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;
typedef long long ll;
const int MAXN = 101;
const int MOD = 9999973;

int n,m;
ll dp[MAXN][MAXN][MAXN];

inline int C( int num ) { // �൱��C(num,2)
    return num*(num-1)/2;
}

int main() {
    scanf( "%d%d", &n, &m );
    dp[0][0][0] = 1;
    for( int i = 0; i < n; ++i ) // �ŵ�i+1��
    for( int j = 0; j <= m; ++j ) // ��1�����ӵ�����
    for( int k = 0; j+k <= m; ++k ) if( dp[i][j][k] ) { // ��2�����ӵ�����
        dp[i+1][j][k] = ( dp[i+1][j][k] + dp[i][j][k] ) % MOD; // ����
        if( m-j-k >= 1 ) dp[i+1][j+1][k] = ( dp[i+1][j+1][k] + dp[i][j][k]*(m-j-k) ) % MOD; // ��һ������û�����ӵ���һ��
        if( j >= 1 ) dp[i+1][j-1][k+1] = ( dp[i+1][j-1][k+1] + dp[i][j][k]*j ) % MOD; // ��һ��������һ�����ӵ���һ��
        if( m-j-k >= 2 ) dp[i+1][j+2][k] = ( dp[i+1][j+2][k] + dp[i][j][k]*C(m-j-k) ) % MOD; // ������������û�����ӵ�����
        if( m-j-k >= 1 && j >= 1 ) dp[i+1][j][k+1] = ( dp[i+1][j][k+1] + dp[i][j][k]*(m-j-k)*j ) % MOD; // ��������һ����û�����ӵ��У�һ������һ�����ӵ���
        if( j >= 2 ) dp[i+1][j-2][k+2] = ( dp[i+1][j-2][k+2] + dp[i][j][k]*C(j) ) % MOD; // ��������һ�����ӵ���
    }
    ll ans = 0;
    for( int i = 0; i <= m; ++i ) // ��1�����ӵ���
    for( int j = 0; i+j <= m; ++j ) { // 2�����ӵ���
        ans = ( ans + dp[n][i][j] ) % MOD;
    }
    printf( "%lld\n", ans );
    return 0;
}
