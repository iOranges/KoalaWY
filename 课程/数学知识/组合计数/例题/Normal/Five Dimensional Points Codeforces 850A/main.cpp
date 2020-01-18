#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1010;
int nowarn;

int n, x[MAXN][5];
vector<int> ans;

int check( int i, int j, int k ) {
	int x1[5], x2[5];
	for( int idx = 0; idx < 5; ++idx ) {
		x1[idx] = x[j][idx] - x[i][idx];
		x2[idx] = x[k][idx] - x[i][idx];
	}
	int ans = 0;
	for( int i = 0; i < 5; ++i )
		ans += x1[i] * x2[i];
	return ans > 0;
}

int main() {
	nowarn = scanf( "%d", &n );
	if( n > 40 ) {
		puts("0");
		return 0;
	}
	for( int i = 1; i <= n; ++i )
		for( int j = 0; j < 5; ++j )
			nowarn = scanf( "%d", &x[i][j] );
	for( int i = 1; i <= n; ++i ) {
		bool flag = true;
		for( int j = 1; j <= n; ++j )
			for( int k = 1; k <= n; ++k ) {
				if( i == j || i == k || j == k ) continue;
				if( check(i, j, k) ) flag = false;
			}
		if( flag ) ans.push_back(i);
	}
	printf( "%d\n", (int)ans.size() );
	for( int i = 0; i < (int)ans.size(); ++i )
		printf( "%d ", ans[i] );
	return 0;
}
