class Tree {
public:
    vector<vector<int>> adj, up;    
    vector<int> d, tin, tout;
    int n, timer;
    Tree(int x){
        n = x;
        adj.resize(n + 1);d.resize(n + 1);
        up.resize(n + 1);
        tin.resize(n + 1);
        tout.resize(n + 1);
        for (int i = 1; i <= n; i++) adj[i].clear();
        for (int i = 0; i <= n; i++) up[i].resize(20, 0);
    }
    void tedge(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void build(){
        for (int j = 1; j < 20; j++){
            for (int i = 1; i <= n; i++){
                up[i][j] = up[up[i][j - 1]][j - 1];
            }
        }
    }
    void dfs(int u, int par){
        tin[u] = ++timer;
        for (int v : adj[u]){
            if (v != par){
                d[v] = d[u] + 1;
                up[v][0] = u;
                dfs(v, u);
            }
        }
        tout[u] = ++timer;
    }
    void dfs(int root = 1){
        d[root] = 0;
        timer = 0;
        dfs(root, -1);
        build();
    }
    int lca(int a, int b){
        if (d[a] < d[b]) swap(a, b);
        int del = d[a] - d[b];
        for (int i = 0; i < 20; i++) if (del >> i & 1) a = up[a][i];
        if (a == b) return a;
        for (int i = 19; i >= 0; i--) if (up[a][i] != up[b][i]){
            a = up[a][i];
            b = up[b][i];
        }
        return up[a][0];
    }
    int dist(int a, int b){
        return d[a] + d[b] - 2 * d[lca(a, b)];
    }
};
