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
    ll n,x;cin>>n>>x;
    vector<ll>arr,brr;
    for(int i=0;i<n;i++)
    {
        ll k;cin>>k;
        arr.push_back(k);
    }
    for(int i=0;i<n;i++)
    {
        ll k;cin>>k;
        brr.push_back(k);
    }
    vector<ll>dp(x+1,0);
    for(int i=0;i<n;i++)
    {
        for(int j=x;j>=arr[i];j--)
        {
            dp[j]=max(dp[j-arr[i]]+brr[i],dp[j]);
        }
    }
    cout<<dp[x]<<endl;
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
