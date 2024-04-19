#include<bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main()
{
	//1.dont get stuck on one approach
	//2.think and code
    fastio;
    int t;cin>>t;
    outer : while(t--)
    {
    	int n;cin>>n;
    	vector<int>a(n);
    	vector<int>cnt(n+1,0);
    	for(int i=0;i<n;i++){cin>>a[i];cnt[a[i]]++;}
    	vector<long long>dp(n+1,0);
 		for(int i=1;i<=n;i++){
 			for(int j=i;j<=n;j+=i){
 				dp[i]+=cnt[j];
 			}
 			dp[i]=(dp[i]*(dp[i]-1));
 			dp[i]/=2;
 		}   
 		vector<int>mark(n+1,0);
 		for(int i=n;i>=1;i--){
 			for(int j=2*i;j<=n;j+=i){
 				dp[i]-=dp[j];
 			}	
 		}
    //we are counting all the numbers with possible gcd g but it also include 2*g,3*g,
    // at the end we just exclude the number of pairs with gcd 2g,3g,..
      //here dp[i] stores the number of pairs with gcd g in the given array
 		for(int i=1;i<=n;i++){
 			if(cnt[i]>0){
 				for(int j=i;j<=n;j+=i){
 					mark[j]=1;
 				}
 			}
 		}
 		long long ans=0;
 		for(int i=1;i<=n;i++){
 			if(!mark[i]){
 				ans+=dp[i];
 			}
 		}
 		cout<<ans<<endl;
    }
    return 0;
}
//practice problem:-https://codeforces.com/problemset/problem/1884/D
