#include<bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define N 100001
#define mod 1000000007
int vis[N];int arr[N];
vector<int>adj[N],radj[N];vector<int>order;
void dfs(int cur)
{
    vis[cur]=1;
    for(auto it:adj[cur])
        if(!vis[it]) dfs(it);
    
    order.push_back(cur);
}
int col[N];
void dfs1(int cur,int comp)
{
    vis[cur]=1;col[cur]=comp;
    for(auto it:radj[cur])
        if(!vis[it]) dfs1(it,comp);
}
//time complexity for dfs is O(v+e)
int main()
{
    fastio;
    int n,m;cin>>n;for(int i=1;i<=n;i++){cin>>arr[i];}cin>>m;
    for(int i=0;i<m;i++){int x,y;cin>>x>>y;adj[x].push_back(y);radj[y].push_back(x);}
    for(int i=1;i<=n;i++){if(!vis[i])dfs(i);}
    memset(vis,0,sizeof(vis));
    int comp=1;
    reverse(order.begin(),order.end());
    for(auto it:order)
    {
        if(!vis[it])
        {
            dfs1(it,comp++);
            
        }
    }
    vector<int>scc[comp];
    for(int i=1;i<=n;i++){scc[col[i]].push_back(i);}
    return 0;
}
