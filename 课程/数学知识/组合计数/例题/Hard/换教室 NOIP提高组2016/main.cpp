#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;
const int MAXN = 2010;
const int MAXM = 2010;
const int MAXV = 310;
const int INF = 0x3f3f3f3f;

int n,m,v,e,c[MAXN],d[MAXN];
double k[MAXN];

namespace graph {
    int g[MAXV][MAXV];
    void init() { memset( g, 0x3f, sizeof(g) ); }
    void addedge( int u, int v, int w ) {
        g[u][v] = g[v][u] = min( g[u][v], w );
    }
    void floyd() {
        for( int k = 1; k <= v; ++k )
        for( int i = 1; i <= v; ++i )
        for( int j = 1; j <= v; ++j )
            g[i][j] = min( g[i][j], g[i][k] + g[k][j] );
    }
}
using graph::addedge;
using graph::floyd;
using graph::g;

namespace DP {
    double dp[MAXN][MAXN][2];
    void init() {
        for( int i = 1; i <= n; ++i )
        for( int j = 0; j <= m; ++j )
            dp[i][j][0] = dp[i][j][1] = INF;
        dp[1][0][0] = 0;
        if( m > 0 ) dp[1][1][0] = dp[1][1][1] = 0;
    }
    double calc( int i1, bool c1, int i2, bool c2 ) {
        if( c1 && c2 ) {
            double e = 0;
            e += g[c[i1]][c[i2]] * (1-k[i1]) * (1-k[i2]);
            e += g[d[i1]][c[i2]] * k[i1] * (1-k[i2]);
            e += g[c[i1]][d[i2]] * (1-k[i1]) * k[i2];
            e += g[d[i1]][d[i2]] * k[i1] * k[i2];
            return e;
        }
        else if( c1 ) {
            double e = 0;
            e += g[c[i1]][c[i2]] * (1-k[i1]);
            e += g[d[i1]][c[i2]] * k[i1];
            return e;
        }
        else if( c2 ) {
            double e = 0;
            e += g[c[i1]][c[i2]] * (1-k[i2]);
            e += g[c[i1]][d[i2]] * k[i2];
            return e;
        }
        else return g[c[i1]][c[i2]];
    }
    void dpf() {
        for( int i = 2; i <= n; ++i ) {
            for( int j = 0; j <= min(i,m); ++j ) {
                if( j > 0 ) {
                    if( j > 1 ) // 上一个教室也申请了
                        dp[i][j][1] = min( dp[i][j][1], dp[i-1][j-1][1] + calc(i-1,1,i,1) );
                    dp[i][j][1] = min( dp[i][j][1], dp[i-1][j-1][0] + calc(i-1,0,i,1) );
                    if( j <= i-1 ) dp[i][j][0] = min( dp[i][j][0], dp[i-1][j][1] + calc(i-1,1,i,0) );
                }
                if( j <= i-1 ) dp[i][j][0] = min( dp[i][j][0], dp[i-1][j][0] + calc(i-1,0,i,0) );
            }
        }
    }
}

int main() {
    scanf( "%d%d%d%d", &n, &m, &v, &e );
    for( int i = 1; i <= n; ++i ) scanf( "%d", &c[i] );
    for( int i = 1; i <= n; ++i ) scanf( "%d", &d[i] );
    for( int i = 1; i <= n; ++i ) scanf( "%lf", &k[i] );
    graph::init();
    for( int i = 1; i <= v; ++i ) addedge(i,i,0);
    for( int i = 1; i <= e; ++i ) {
        int u,v,w; scanf( "%d%d%d", &u, &v, &w );
        if( u != v ) addedge(u,v,w);
    }
    floyd(); DP::init(); DP::dpf();
    double ans = INF;
    for( int i = 0; i <= m; ++i ) {
        ans = min( ans, DP::dp[n][i][0] );
        if( i > 0 ) ans = min( ans, DP::dp[n][i][1] );
    }
    printf( "%.2lf\n", ans );
    return 0;
}
