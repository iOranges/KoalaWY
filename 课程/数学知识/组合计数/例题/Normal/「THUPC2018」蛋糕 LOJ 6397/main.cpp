#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const int N = 4;
const int M = 9;
const ull MOD = 2148473648ULL;
const int SIDE = 0;
const int MID = 1;
int _w;

int T, x[N];
ull ans[M];

int tmp[N];
void check() {
	ull now = 1;
	int cnt = 0;
	for( int i = 0; i < N; ++i )
		if( tmp[i] == MID )
			now = now * (x[i] - 2) % MOD;
		else cnt += x[i] == 1 ? 2 : 1;
	ans[cnt] = (ans[cnt] + now) % MOD;
}
void dfs( int idx ) {
	if( idx == N ) {
		check();
		return;
	}
	tmp[idx] = SIDE, dfs(idx+1);
	if( x[idx] >= 2 ) dfs(idx+1);
	if( x[idx] >= 3 )
		tmp[idx] = MID, dfs(idx+1);
}

int main() {
	cin >> T;
	while( T-- ) {
		for( int i = 0; i < N; ++i )
			cin >> x[i];
		memset(ans, 0, sizeof ans);
		dfs(0);
		for( int i = 0; i < M; ++i )
			cout << ans[i] << " ";
		cout << endl;
	}
	return 0;
}
