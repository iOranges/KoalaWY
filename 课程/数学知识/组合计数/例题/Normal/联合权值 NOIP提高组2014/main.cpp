#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector< int > g[ 200001 ];
int w[ 200001 ];
int n;
int maxw = 0;
int totw = 0;

void dfs( int v , int lastw )
{
    if( g[ v ].size() >= 2 )
    {
        int max1 = -1 , max2 = -1;
        int sum = 0;
        for( int i = 0 ; i < g[ v ].size() ; ++i )
        {
            int u = g[ v ][ i ];
            if( w[ u ] > max1 )
            {
                max2 = max1;
                max1 = w[ u ];
            }
            else if( w[ u ] > max2 )
            {
                max2 = w[ u ];
            }
            sum += w[ u ];
            sum %= 10007;
        }
        maxw = max( maxw , max1 * max2 );
        for( int i = 0 ; i < g[ v ].size() ; ++i )
        {
            int u = g[ v ][ i ];
            totw += w[ u ] * ( sum - w[ u ] );
            totw %= 10007;
        }
    }

    for( int i = 0 ; i < g[ v ].size() ; ++i )
    {
        int u = g[ v ][ i ];
        maxw = max( maxw , lastw * w[ u ] );
        totw += lastw * w[ u ];
        totw %= 10007;
        totw += lastw * w[ u ];
        totw %= 10007;
        g[ u ].erase( find( g[ u ].begin() , g[ u ].end() , v ) );
        dfs( u , w[ v ] );
    }
}

int main()
{
    scanf( "%d" , &n );
    for( int i = 1 ; i < n ; ++i )
    {
        int u , v;
        scanf( "%d%d" , &u , &v );
        g[ u ].push_back( v );
        g[ v ].push_back( u );
    }
    for( int i = 1 ; i <= n ; ++i )
    {
        scanf( "%d" , &w[ i ] );
    }

    dfs( 1 , 0 );

    printf( "%d %d\n" , maxw , totw );
    return 0;
}
