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
ll n;vector<ll>adj[100001];
ll size[100001];
ll mini=1e9;ll cent1,cent2;

void dfs(ll node,ll parent)
{
    ll maxi=0;
    size[node]=1;
    for(auto child:adj[node])
    {
        if(child==parent){continue;}
    dfs(child,node);
        size[node]+=size[child];
        maxi=max(maxi,size[child]);
    }
    maxi=max(maxi,n-size[node]);
    if(maxi<mini){mini=maxi,cent1=node,cent2=0;}
    else if(maxi==mini){cent2=node;}
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
    cout<<cent1<<" "<<cent2<<endl;
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
