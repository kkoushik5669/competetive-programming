#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define vi vector<int>
#define vvi vector<vector<int>>
#define vll vector<ll>
#define mod 1000000007
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define pi 3.14159265358979
#define vvll vector<vector<ll>>
using namespace std;
const ll N=100001;
void solve()
{
    ll n,k;cin>>n>>k;
    vector<ll>arr;
    for(int i=0;i<n;i++)
    {
        ll x;cin>>x;
        arr.push_back(x);
    }
    vector<ll>dp(k+1,1e9);
    dp[k]=0;
    for(int i=k-1;i>=0;i--)
    {
        for(int j=0;j<n;j++)
        {
            if(i+arr[j]<=k){dp[i]=min(dp[i+arr[j]]+1,dp[i]);}
        }
    }
    if(dp[0]==1e9){cout<<-1<<endl;return;}
    cout<<dp[0]<<endl;
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
