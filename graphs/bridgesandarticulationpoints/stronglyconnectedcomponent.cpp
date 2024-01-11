vector<vector<int>> adj, adj_rev;
vector<bool> used;
vector<int> order, component;
//What is a condensed graph?? It is formed by making a graph from different strongly connected components
//What is the root of a condensed graph .It is the one scc which has the maximum tout
//for each scc the one with the maximum tout is where we need to apply dfs from
//how to optimally find the nodes for maximum tout just find the topo sort brooo
//It can be proved that applying the dfs on a straight graph and a reverse graph would give you the same scc
//It is optimal to apply dfs on reverse graph because it will not visit other useless scc's .
void dfs1(int v) {
    used[v] = true;

    for (auto u : adj[v])
        if (!used[u])
            dfs1(u);

    order.push_back(v);
}

void dfs2(int v) {
    used[v] = true;
    component.push_back(v);

    for (auto u : adj_rev[v])
        if (!used[u])
            dfs2(u);
}

int main() {
    int n;
    // ... read n ...

    for (;;) {
        int a, b;
        // ... read next directed edge (a,b) ...
        adj[a].push_back(b);
        adj_rev[b].push_back(a);
    }

    used.assign(n, false);

    for (int i = 0; i < n; i++)
        if (!used[i])
            dfs1(i);

    used.assign(n, false);
    reverse(order.begin(), order.end());

    for (auto v : order)
        if (!used[v]) {
            dfs2 (v);

            // ... processing next component ...

            component.clear();
        }
}
