#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 1000010;
const int MOD = 1e9+7;
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
int inv( int a ) {
	return fpow(a, MOD-2);
}

int n, k;

int fac[N], ifac[N];
double logfac[N];
void prelude() {
	fac[0] = 1;
	for( int i = 1; i <= n; ++i )
		fac[i] = int(1LL * fac[i-1] * i % MOD);
	ifac[n] = inv( fac[n] );
	for( int i = n; i >= 1; --i )
		ifac[i-1] = int(1LL * ifac[i] * i % MOD);
	logfac[0] = log(1);
	for( int i = 1; i <= n; ++i )
		logfac[i] = logfac[i-1] + log(i);
}
int C( int n, int m ) {
	return int(1LL * fac[n] * ifac[m] % MOD * ifac[n-m] % MOD);
}
double logC( int n, int m ) {
	return logfac[n] - logfac[n-m] - logfac[m];
}

struct Node {
	int n, m;
	Node() {}
	void init( int _n ) {
		n = _n, m = n/2;
	}
	int val() const {
		return C(n, m);
	}
	double logval() const {
		return logC(n, m);
	}
	bool operator<( const Node &rhs ) const {
		return logval() < rhs.logval();
	}
	bool nxt() {
		if( n & 1 ) {
			if( m <= n/2 ) m = n-m;
			else m = n-m-1;
		} else {
			if( m < n/2 ) m = n-m;
			else m = n-m-1;
		}
		return m >= 0;
	}
};

priority_queue<Node> pq;
void solve() {
	Node tmp;
	for( int i = 1; i <= n; ++i ) {
		tmp.init(i);
		pq.push(tmp);
	}
	int ans = 0;
	while( k-- ) {
		tmp = pq.top(), pq.pop();
		ans = (ans + tmp.val()) % MOD;
		if( tmp.nxt() ) pq.push(tmp);
	}
	printf( "%d\n", ans );
}

int main() {
	cin >> n >> k;
	prelude(), solve();
	return 0;
}
