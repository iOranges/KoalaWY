#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>

using namespace std;
typedef long long ll;
const int MAXN = 10005;

int n, a[MAXN];

namespace DP {
    ll dp[MAXN][2][2][2]; // dp[列][左下][下方][右下]
    void init() {
        switch( a[0] ) {
        case 0: dp[0][0][0][0] = 1; break;
        case 1: dp[0][0][1][0] = dp[0][0][0][1] = 1; break;
        case 2: dp[0][0][1][1] = 1; break;
        }
    }
    void solve() {
        for( int i = 0; i < n-1; ++i ) {
            if( a[i] == 0 ) {
                dp[i+1][0][0][0] += dp[i][0][0][0];
                dp[i+1][0][0][1] += dp[i][0][0][0];
            } else if( a[i] == 1 ) {
                dp[i+1][0][0][0] += dp[i][1][0][0];
                dp[i+1][0][0][1] += dp[i][1][0][0];
                dp[i+1][1][0][0] += dp[i][0][1][0];
                dp[i+1][1][0][1] += dp[i][0][1][0];
                dp[i+1][0][1][0] += dp[i][0][0][1];
                dp[i+1][0][1][1] += dp[i][0][0][1];
            } else if( a[i] == 2 ) {
                dp[i+1][1][0][0] += dp[i][1][1][0];
                dp[i+1][1][0][1] += dp[i][1][1][0];
                dp[i+1][0][1][0] += dp[i][1][0][1];
                dp[i+1][0][1][1] += dp[i][1][0][1];
                dp[i+1][1][1][0] += dp[i][0][1][1];
                dp[i+1][1][1][1] += dp[i][0][1][1];
            } else if( a[i] == 3 ) {
                dp[i+1][1][1][0] += dp[i][1][1][1];
                dp[i+1][1][1][1] += dp[i][1][1][1];
            }
        }
    }
    void printans() {
        if( a[n-1] == 0 ) cout << dp[n-1][0][0][0] << endl;
        else if( a[n-1] == 1 ) cout << dp[n-1][1][0][0] + dp[n-1][0][1][0] << endl;
        else if( a[n-1] == 2 ) cout << dp[n-1][1][1][0] << endl;
    }
}

int main() {
    scanf( "%d", &n );
    for( int i = 0; i < n; ++i ) {
        scanf( "%d", a+i );
        if( a[i] > 3 || a[i] < 0 ) {
            printf( "0\n" ); return 0;
        }
    }
    if( a[0] == 3 || a[n-1] == 3 ) {
        printf( "0\n" ); return 0;
    }
    DP::init(); DP::solve(); DP::printans();
    return 0;
}
