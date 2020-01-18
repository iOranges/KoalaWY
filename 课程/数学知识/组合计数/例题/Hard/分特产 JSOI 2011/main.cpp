#include <cstring>
#include <algorithm>
#include <cstdio>

using namespace std;
typedef long long ll;
const int N = 2010;
const int MOD = 1e9+7;
int _w;

int n, m, a[N];

int C[N][N], f[N][N];
void prelude() {
	C[0][0] = 1;
	for( int i = 1; i < N; ++i ) {
		C[i][0] = 1;
		for( int j = 1; j <= i; ++j )
			C[i][j] = (C[i-1][j-1] + C[i-1][j]) % MOD;
	}
	for( int i = 1; i <= n; ++i )
		for( int j = 1; j <= 1000; ++j )
			f[i][j] = C[j+i-1][i-1];
}

int calc( int x ) {
	int ans = 1;
	for( int i = 1; i <= m; ++i )
		ans = int(1LL * ans * f[x][a[i]] % MOD);
	return int(1LL * ans * C[n][x] % MOD);
}

int main() {
	_w = scanf( "%d%d", &n, &m );
	for( int i = 1; i <= m; ++i )
		_w = scanf( "%d", a+i );
	prelude();
	int ans = 0;
	for( int i = n; i >= 1; --i )
		if( (n-i) & 1 ) {
			ans = (ans - calc(i) + MOD) % MOD;
		} else {
			ans = (ans + calc(i)) % MOD;
		}
	printf( "%d\n", ans );
	return 0;
}
