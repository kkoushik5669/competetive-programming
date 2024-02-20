#include<bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long 
#define ll long long
const int mod=998244353;
ll add(ll a, ll b, ll c = mod){ll res=a+b;return(res>=c?res-c:res);} 
ll mod_neg(ll a, ll b, ll c = mod){ll res;if(abs(a-b)<c)res=a-b;else res=(a-b)%c;return(res<0?res+c:res);} 
ll mul(ll a, ll b, ll c = mod){ll res=(ll)a*b;return(res>=c?res%c:res);} 
int binpow(int a,int b)
{
	if(b==0)return 1;
	int ch=binpow(a,b/2);
	if(b&1)
	{
		return mul(ch,mul(ch,a));
	}
	else
	{
		return mul(ch,ch);
	}
}
vector<int>dp;
vector<vector<int>>adj;
 void dfs(int src, int par) {
        // Start with no children.
        dp[src] = 1;
        for (auto child : adj[src]) {
            if (child == par) {
                continue;
            }
            dfs(child, src);
            // Either ignore this children : dp[src]*1 way
            // Or take this children : dp[src]*dp[child] ways
            dp[src] =add(dp[src],mul( dp[src] , dp[child]));
        }
    }
main()
{
	//1.dont get stuck on one approach
	//2.think and code
    fastio;
    int t;cin>>t;
    while(t--)
    {int n;cin>>n;
    	adj.assign(n,{});
    	for(int i=0;i<n-1;i++){
    		int a,b;cin>>a>>b;
    		--a;--b;
    		adj[a].push_back(b);
    		adj[b].push_back(a);
    	}	
    	dp.assign(n,0);
    dfs(0,-1);int ans=0;
    for(int i=0;i<n;i++){ans=add(ans,dp[i]);
    }
    	cout<<ans<<endl;
    }
    return 0;
}
