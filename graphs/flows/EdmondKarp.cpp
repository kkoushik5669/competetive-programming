#include<bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int INF=1e9;
int n;
vector<vector<int>> capacity;
vector<vector<int>> adj;

int bfs(int s, int t, vector<int>& parent) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<int, int>> q;
    q.push({s, INF});

    while (!q.empty()) {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();

        for (int next : adj[cur]) {
            if (parent[next] == -1 && capacity[cur][next]) {
                parent[next] = cur;
                int new_flow = min(flow, capacity[cur][next]);
                if (next == t)
                    return new_flow;
                q.push({next, new_flow});
            }
        }
    }

    return 0;
}

int maxflow(int s, int t) {
    int flow = 0;
    vector<int> parent(n);
    int new_flow;

    while (new_flow = bfs(s, t, parent)) {
        flow += new_flow;
        int cur = t;
        while (cur != s) {
            int prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }

    return flow;
}
int main()
{
    //1.dont get stuck on one approach
    //2.think and code
    //edmond karp is just like ford fulkerson but by using bfs we are mostly considering the shortest augumented paths first
    //the overall complexity is o(v+E)*(vE)=o(v*E^2)
    fastio;
    cin>>n;
    int m;cin>>m;
    adj.assign(n,{});
    capacity.resize(n,{});
    for(int i=0;i<n;i++){capacity[i].assign(n,INF);}
    for(int i=0;i<m;i++)
    {
        int a,b,c;cin>>a>>b>>c;--a;--b;
        adj[a].push_back(b);
        capacity[a][b]=c;
    }
    int source;int sink;
    cin>>source>>sink;--source;--sink;
    cout<<maxflow(source,sink)<<endl;
    return 0;
}
