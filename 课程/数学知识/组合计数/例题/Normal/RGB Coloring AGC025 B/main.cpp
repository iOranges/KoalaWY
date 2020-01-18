#include <cstring>
#include <algorithm>
#include <cstdio>

typedef long long ll;
const int N = 300010;
const int MOD = 998244353;
int _w;

int fpow( int a, int b ) {
	int c = 1;
	while(b) {
		if( b & 1 ) c = int(1LL * c * a % MOD);
		a = int(1LL * a * a % MOD);
		b >>= 1;
	}
	return c;
}

int inv( int x ) {
	return fpow(x, MOD-2);
}

ll n, a, b, k;

int C[N];

void prelude() {
	C[0] = 1;
	for( int i = 1; i <= n; ++i )
		C[i] = int(1LL * C[i-1] * (n-i+1) % MOD * inv(i) % MOD);
}

ll exgcd( ll a, ll b, ll &x, ll &y ) {
	if( !b ) {
		x = 1, y = 0;
		return a;
	} else {
		ll g = exgcd(b, a%b, y, x);
		y -= x*(a/b);
		return g;
	}
}

bool check( ll x ) {
	return x >= 0 && x <= n;
}

void solve() {
	ll g, x, y;
	g = exgcd(a, b, x, y);
	if( k % g ) {
		puts("0");
		return;
	}
	x *= k/g;
	y *= k/g;
	ll t = b/g;
	x %= t;
	x = (x + t) % t;
	int ans = 0;
	for( ll i = x; i <= n; i += t ) {
		ll j = (k-i*a)/b;
		if( !check(i) || !check(j) ) continue;
		ans = (ans + int(1LL * C[i] * C[j] % MOD)) % MOD;
	}
	printf( "%d\n", ans );
}

int main() {
	_w = scanf( "%lld%lld%lld%lld", &n, &a, &b, &k );
	prelude(), solve();
	return 0;
}
