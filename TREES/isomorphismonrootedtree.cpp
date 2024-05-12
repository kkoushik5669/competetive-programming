#include<bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
mt19937 rnd(std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count());
int randint(int L, int R) {
    uniform_int_distribution<int> dist(L, R);
    return dist(rnd);
}
typedef long long ll;
vector<vector<int>>adj;
map<vector<int>,int>type;
int last;
map<int,int>symmetry;
int dfs(int src,int par){
  vector<int>child;
  for(auto i:adj[src]){
    if(i==par)continue;
    child.push_back(dfs(i,src));
  }
  sort(child.begin(),child.end());
  if(type.find(child)==type.end()){
    map<int,int>cnt;
    for(auto i:child){cnt[i]++;}int odd=0;int bad=0;
    for(auto i:cnt){
      if((i.second&1)){
        odd++;
        bad+=!symmetry[i.first];
      }
    }
    symmetry[last]=(odd<=1 and bad==0);
    type[child]=last;
    last++;
  }
  return type[child];
}
int main()
{
  //1.dont get stuck on one approach
  //2.think and code
    fastio;
    int t;cin>>t;
    outer : while(t--)
    {last=1;
      int n;cin>>n;adj.assign(n,{});
      type.clear();
      symmetry.clear();
      for(int i=0;i<n-1;i++){
        int a,b;cin>>a>>b;--a;--b;
        adj[a].push_back(b);
        adj[b].push_back(a);
      }
      cout<<(symmetry[dfs(0,-1)] ? "YES":"NO")<<endl;
    }
    return 0;
}
//problem link:-https://codeforces.com/contest/1800/problem/G
