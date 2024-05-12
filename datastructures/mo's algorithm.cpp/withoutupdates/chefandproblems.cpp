#include <bits/stdc++.h>
#define int long long int
#define endl "\n"
#define pb push_back
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(__null);

using namespace std;

const int b = 320;

signed main() {
    fastio()

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> v(n);
    for (auto &x : v) cin >> x;

    vector<array<int, 3>> qr(k);
    for (int i = 0; i < k; i++) {
        cin >> qr[i][0] >> qr[i][1];
        qr[i][0]--, qr[i][1]--, qr[i][2] = i;
    }

    sort(qr.begin(), qr.end(), [&](const auto & l, const auto & r) {
        if (l[0] / b != r[0] / b) return l[0] < r[0];
        return ((l[0] / b) & 1) ? l[1] > r[1] : l[1] < r[1];
    });

    deque<int> s[m + 1];
    vector<int> freq(n + 1), sum(n / b + 1);

    auto add = [&](int i) {
        auto &v1 = s[v[i]];
        if (!v1.empty()) {
            int k = v1.back() - v1.front();
            freq[k]--, sum[k / b]--;
        }

        if (v1.empty() || i > v1.back()) v1.push_back(i);
        else v1.push_front(i);

        int k = v1.back() - v1.front();
        freq[k]++, sum[k / b]++;
    };

    auto erase = [&](int i) {
        auto &v1 = s[v[i]];
        int k = v1.back() - v1.front();
        freq[k]--, sum[k / b]--;

        if (v1.back() == i) v1.pop_back();
        else v1.pop_front();

        if (!v1.empty()) {
            int k = v1.back() - v1.front();
            freq[k]++, sum[k / b]++;
        }
    };

    auto query = [&]() {
        for (int i = n / b; i >= 0; i--) {
            if (!sum[i]) continue;
            for (int j = min(i * b + b - 1, n); j >= i * b ; j--)
                if (freq[j])
                    return j;
        }

        return 0LL;
    };

    int l = 0, r = -1;
    vector<int> ans(k);
    for (auto &[a, b, in] : qr) {
        while (r < b) r++, add(r);
        while (l > a) l--, add(l);
        while (r > b) erase(r), r--;
        while (l < a) erase(l), l++;
        ans[in] = query();
    }

    for (auto &x : ans) cout << x << endl;

    return 0;
}
