#include <iostream>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using mint = static_modint<998244353>;
mint dp[110][110][2];

int main() {
	int n, a, b, p, q;
	cin >> n >> a >> b >> p >> q;
	for (int i = 0; i < n; i++) for (int f = 0; f < 2; f++) {
		dp[n][i][f] = 1;
		dp[i][n][f] = 0;
	}
	for (int i = n - 1; i >= 0; i--) {
		for (int j = n - 1; j >= 0; j--) {
			for (int k = 1; k <= p; k++) {
				dp[i][j][0] += dp[min(n, i + k)][j][1];
			}
			dp[i][j][0] /= p;
			for (int k = 1; k <= q; k++) {
				dp[i][j][1] += dp[i][min(n, j + k)][0];
			}
			dp[i][j][1] /= q;
		}
	}
	cout << dp[a][b][0].val() << '\n';
}
//problem link:-https://atcoder.jp/contests/abc298/tasks/abc298_e
