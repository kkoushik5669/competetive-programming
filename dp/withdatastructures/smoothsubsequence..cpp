#include <bits/stdc++.h>
using namespace std;

#include <atcoder/all>

int op(int a, int b) { return max(a, b); }
int e() { return 0; }

const int A = 500010;

int main() {
    int n, d;
    cin >> n >> d;
    vector<int> a(n);
    for (int &e : a) cin >> e;
    atcoder::segtree<int, op, e> seg(A);
    for (int e : a) {
        int l = max(0, e - d);
        int r = min(A - 1, e + d);
        int mx = seg.prod(l, r + 1);
        seg.set(e, mx + 1);
    }
    cout << seg.all_prod() << '\n';
}
//problem link:-https://atcoder.jp/contests/abc339/tasks/abc339_e
