#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define vi vector<int>
#define vvi vector<vector<int>>
#define vll vector<ll>
#define to_upper(s1) transform(s1.begin(), s1.end(), s1.begin(), ::toupper);
#define to_lower(s2) transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
#define mod 1000000007
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define pi 3.14159265358979
#define vvll vector<vector<ll>>
#define precise(n) fixed<<setprecision(n)
using namespace std;
const ll N=100001;
vector<ll>adj[200001];
ll s[200001];
void dfs(ll node,ll parent)
{
    s[node]=1;
    for(auto it:adj[node])
    {
        if(it!=parent)
        {
            dfs(it,node);
            s[node]+=s[it];
        }
    }
}
ll n;
int findcentroid(ll node,ll parent)
{
    for(auto it:adj[node])
    {
        if(it!=parent and s[it]>n/2){return findcentroid(it,node);}
    }
    return node;
}
void solve()
{
    cin>>n;
    for(int i=0;i<n-1;i++)
    {
        ll a,b;cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,-1);
    cout<<findcentroid(1,-1);
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    fastio;
    ll t=1;
    //cin>>t;
    while(t--)
    {
    solve();
    }
    return 0;
}
