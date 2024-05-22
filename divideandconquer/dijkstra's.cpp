#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

typedef tuple<int, int, int> node;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            cin >> a[i][j];
    int q;
    cin >> q;
    vector<array<int, 5>> queries;
    for (int i=0; i<q; i++) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        queries.push_back({r1, c1, r2, c2, i});
    }

    vector<vector<vector<int>>> dist(n, vector<vector<int>>(n, vector<int>(m)));

    auto dijkstra = [&] (int s, int t, int l, int r) -> void {
        for (int i=0; i<n; i++)
            for (int j=l; j<=r; j++)
                dist[s][i][j] = INF;
        priority_queue<node, vector<node>, greater<node>> pq;
        pq.emplace(dist[s][s][t] = a[s][t], s, t);
        while (!pq.empty()) {
            auto [d, x, y] = pq.top();
            pq.pop();
            if (d > dist[s][x][y])
                continue;
            for (int i=0; i<4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (0 <= nx && nx < n && l <= ny && ny <= r && d + a[nx][ny] < dist[s][nx][ny])
                    pq.emplace(dist[s][nx][ny] = d + a[nx][ny], nx, ny);
            }
        }
    };

    vector<int> ret(q, INF);

    auto solve = [&] (auto &self, int l, int r, const vector<array<int, 5>> &queries) -> void {
        if (l > r)
            return;
        int x = (l + r) / 2;
        for (int i=0; i<n; i++)
            dijkstra(i, x, l, r);
        vector<array<int, 5>> left, right;
        for (auto [r1, c1, r2, c2, i] : queries) {
            for (int j=0; j<n; j++)
                ret[i] = min(ret[i], dist[j][r1][c1] + dist[j][r2][c2] - a[j][x]);
            if (c1 < x && c2 < x)
                left.push_back({r1, c1, r2, c2, i});
            else if (c1 > x && c2 > x)
                right.push_back({r1, c1, r2, c2, i});
        }
        self(self, l, x - 1, left);
        self(self, x + 1, r, right);
    };

    solve(solve, 0, m - 1, queries);
    for (int x : ret)
        cout << x << "\n";

    return 0;
}
//problem link:-https://www.hackerrank.com/challenges/shortest-path/problem
