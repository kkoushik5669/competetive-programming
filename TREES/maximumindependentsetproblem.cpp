#include<bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
mt19937 rnd(std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count());
int randint(int L, int R) {
    uniform_int_distribution<int> dist(L, R);
    return dist(rnd);
}
typedef long long ll;
const int N=200005;
int dp[N][2];
int p[N][2];
vector<vector<int>>adj;
void dfs(int src,int par=-1){
    if(adj[src].size()==1 and src!=0){
        dp[src][0]=0;
        dp[src][1]=1;
        return;
    }
    for(auto i:adj[src]){
        if(i==par)continue;
        dfs(i,src);
        dp[src][1]+=dp[i][0];
        dp[src][0]+=max(dp[i][0],dp[i][1]);
    }
    dp[src][1]++;
    
}
int main()
{
    //1.dont get stuck on one approach
    //2.think and code
    fastio;
    int t;cin>>t;
    outer : while(t--)
    {
    int n;cin>>n;adj.assign(n,{});
    for(int i=0;i<n-1;i++){
        int a,b;cin>>a>>b;--a;--b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(0);
    int mxans=dp[0][0];
    function<void(int,int)>dfs2=[&](int src,int par){
        if(par!=-1){
            p[src][1]+=p[par][0];
            p[src][0]+=max(p[par][0],p[par][1]);
        }
      for(auto i:adj[src]){
        if(i==par)continue;
        p[src][1]+=dp[i][0];
        p[src][0]+=max(dp[i][0],dp[i][1]);
      }  
      p[src][1]++;
      for(auto i:adj[src]){
        if(i==par)continue;
        p[src][1]-=dp[i][0];
        p[src][0]-=max(dp[i][0],dp[i][1]);
        dfs2(i,src);
        p[src][1]+=dp[i][0];
        p[src][0]+=max(dp[i][0],dp[i][1]);
      }
      mxans=max(mxans,p[src][0]+(adj[src].size()==1));
    };
    dfs2(0,-1);
        cout<<mxans<<endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<2;j++){
                dp[i][j]=0;p[i][j]=0;
            }
        }
    }
    
    return 0;
}
//problem link:-https://codeforces.com/problemset/problem/1984/E
