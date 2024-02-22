#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
constexpr int inf = 1000000010;
template<class T, class U> inline bool chmin(T &a, const U &b) { if (a > b) { a = b; return true; } return false; }

int main() {
	int h, w;
	cin >> h >> w;
	vector<vector<int>> a(h, vector<int>(w));
	rep(i, h) rep(j, w) cin >> a[i][j];
	vector<vector<vector<int>>> dp(h, vector<vector<int>>(2, vector<int>(2, inf)));
	dp[0][0][0] = 0;
	dp[0][0][1] = 1;
	for (int i = 1; i < h; i++) {
		rep(j, 2) {
			rep(k, 2) {
				rep(l, 2) {
					vector<int> x(w, -1);
					if (i != 1) x = a[i - 2];
					if (j) rep(m, w) x[m] = 1 - x[m];
					vector<int> y = a[i - 1];
					if (k) rep(m, w) y[m] = 1 - y[m];
					vector<int> z = a[i];
					if (l) rep(m, w) z[m] = 1 - z[m];
					bool ok = true;
					rep(m, w) if (x[m] != y[m] && y[m] != z[m] && (m == 0 || y[m] != y[m - 1]) && (m == w - 1 || y[m] != y[m + 1])) ok = false;
					if (i == h - 1) {
						rep(m, w) if (z[m] != y[m] && (m == 0 || z[m] != z[m - 1]) && (m == w - 1 || z[m] != z[m + 1])) ok = false;
					}
					if (ok) chmin(dp[i][k][l], dp[i - 1][j][k] + l);
				}
			}
		}
	}
	int ans = inf;
	rep(j, 2) rep(k, 2) chmin(ans, dp[h - 1][j][k]);
	cout << (ans == inf ? -1 : ans) << '\n';
}
//problem link:-https://atcoder.jp/contests/abc283/tasks/abc283_e
