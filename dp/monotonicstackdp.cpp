#include<bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long 
const int mod=998244353;
ll add(ll a,ll b){
	return (a+b)%mod;
}
int main()
{
	//1.dont get stuck on one approach
	//2.think and code
    fastio;
    int t;cin>>t;
    outer : while(t--)
    {
    	
    int n;cin>>n;
    vector<ll>dp(n);vector<int>a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    	stack<int>st;vector<ll>pref(n,0);ll currsum=0;
    for(int i=0;i<n;i++){
    	while(st.size() && a[st.top()]>a[i]){currsum=(currsum-dp[st.top()]+mod)%mod;st.pop();}
    	if(st.size()==0){
    		dp[i]=((i>=1) ?pref[i-1]:0)+1;dp[i]%=mod;
    	}
    	else{
    		dp[i]=(currsum+pref[i-1]-pref[st.top()]+mod)%mod;
    	}	
    	pref[i]=(((i>=1) ?pref[i-1]:0)+dp[i])%mod;st.push(i);currsum+=dp[i];
    }
    int suffmin=a[n-1];ll ans=0;
    for(int i=n-1;i>=0;i--){
    	suffmin=min(suffmin,a[i]);
    	if(suffmin==a[i]){
    		ans=add(ans,dp[i]);
    	}
    	
    }
    cout<<ans<<endl;
    }
    return 0;
}
//problem codeforces :-(Array collapse) https://codeforces.com/problemset/problem/1913/D
