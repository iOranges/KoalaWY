#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;
const int MOD = 100003;
typedef long long ll;

ll m, n;

ll pow_mod( ll a, ll b ) {
	ll ans = 1;
	while(b) {
		if( b&1 ) ans = ans * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return ans;
}

int main() {
	scanf( "%lld%lld", &m, &n );
	ll ans = pow_mod(m%MOD, n);
	ans = (ans - m * pow_mod((m-1)%MOD, n-1) % MOD + MOD) % MOD;
	printf( "%lld\n", ans );
	return 0;
}
