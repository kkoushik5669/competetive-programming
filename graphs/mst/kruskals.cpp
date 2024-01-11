#include<bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
struct DSU {
    vector<int> e;
    void init(int n) { e = vector<int>(n, -1); }
    int get(int x) { return (e[x] < 0 ? x : e[x] = get(e[x])); }
    bool sameSet(int x, int y) { return get(x) == get(y); }
    int size(int x) { return -e[get(x)]; }
    bool unite(int x, int y) {
        x = get(x), y = get(y);
        if (x == y) return 0;
        if (e[x] > e[y]) swap(x, y);
        e[x] += e[y];
        e[y] = x;
        return 1;
    }
};
struct Edge {
    int u, v, weight;
    bool operator<(Edge const& other) {
        return weight < other.weight;
    }
};

int main()
{
    fastio;
    
int n;
vector<Edge> edges;

int cost = 0;
vector<Edge> result;
DSU dsu;dsu.init(n);
sort(edges.begin(), edges.end());
//in kurskals you are going to build the tree taking the smallest edge each time and adding it to the current tree using a dsu
for (Edge e : edges) {
    if (!dsu.sameSet(e.u,e.v)) {
        cost += e.weight;
        result.push_back(e);
        dsu.unite(e.u,e.v);
    }
}
    return 0;
}
