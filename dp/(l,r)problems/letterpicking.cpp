#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

int comp(char c, char d){
	return c < d ? -1 : (c > d ? 1 : 0);
}

int main() {
	int t;
	cin >> t;
	forn(_, t){
		string s;
		cin >> s;
		int n = s.size();
		vector<vector<int>> dp(n + 1, vector<int>(n + 1));
		for (int len = 2; len <= n; len += 2) forn(l, n - len + 1){
			int r = l + len;
			dp[l][r] = 1;
			{
				int res = -1;
				if (dp[l + 1][r - 1] != 0)
					res = max(res, dp[l + 1][r - 1]);
				else
					res = max(res, comp(s[l], s[r - 1]));
				if (dp[l + 2][r] != 0)
					res = max(res, dp[l + 2][r]);
				else
					res = max(res, comp(s[l], s[l + 1]));
				dp[l][r] = min(dp[l][r], res);
			}
			{
				int res = -1;
				if (dp[l + 1][r - 1] != 0)
					res = max(res, dp[l + 1][r - 1]);
				else
					res = max(res, comp(s[r - 1], s[l]));
				if (dp[l][r - 2] != 0)
					res = max(res, dp[l][r - 2]);
				else
					res = max(res, comp(s[r - 1], s[r - 2]));
				dp[l][r] = min(dp[l][r], res);
			}
		}
		if (dp[0][n] == -1)
			cout << "Alice\n";
		else if (dp[0][n] == 0)
			cout << "Draw\n";
		else
			cout << "Bob\n";
	}
	return 0;
}
//problem link:-https://codeforces.com/contest/1728/problem/D
