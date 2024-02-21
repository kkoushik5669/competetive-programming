#include <iostream>
#include <utility>
#include <vector>
#include <deque>
using namespace std;
typedef pair<int, int> edge;
const int inf = 1e9;

int n, m, k;
vector<edge> G[400005];
int dist[400005];

int main(void)
{
  cin >> n >> m >> k;
  int u, v, a, s;
  for(int i = 1; i <= m; i++){
    cin >> u >> v >> a;
    if(a) G[u].push_back(edge(v, 1)), G[v].push_back(edge(u, 1));
    else G[n+u].push_back(edge(n+v, 1)), G[n+v].push_back(edge(n+u, 1));
  }
  for(int i = 1; i <= k; i++){
    cin >> s;
    G[s].push_back(edge(n+s, 0)), G[n+s].push_back(edge(s, 0));
  }
  
  deque<int> deq;
  deq.push_back(1);
  for(int i = 1; i <= 2*n; i++) dist[i] = inf;
  dist[1] = 0;
  
  while(deq.size()){
    int v = deq.front();
    deq.pop_front();
    for(int i = 0; i < (int)G[v].size(); i++){
      int u = G[v][i].first, c = G[v][i].second;
      if(dist[u] > dist[v] + c){
        dist[u] = dist[v] + c;
        if(c == 0) deq.push_front(u);
        else deq.push_back(u);
      }
    }
  }
  
  int ans = min(dist[n], dist[2*n]);
  if(ans == inf) ans = -1;
  cout << ans << endl;
  
  return 0;
}
//problem link :- https://atcoder.jp/contests/abc277/tasks/abc277_e
