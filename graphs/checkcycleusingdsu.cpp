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
ll f[N];
int find(int x)
{
    if(x==f[x]){return x;}
    return f[x]=find(f[x]);
}
void solve()
{
    ll m,n;cin>>n>>m;
    vector<ll>adj[n];
    ll self=0;
    for(int i=0;i<n;i++)
    {
        f[i]=i;
    }
    ll cycles=0;
    for(int i=0;i<m;i++)
    {
        ll a,b;cin>>a>>b;
        if(a==b){self++;continue;}
       if(find(a)==find(b)){cycles++;}f[find(a)]=find(b);
        // f[i]=i;
    }
  
    cout<<m-self+cycles<<endl;
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    fastio;
    ll t=1;
    cin>>t;
    while(t--)
    {
    solve();
    }
    return 0;
}
