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
    	vector<int>c(n);
    	for(int i=0;i<n;i++)cin>>c[i];
    	vector<vector<int>>adj(n);
    	for(int i=0;i<n-1;i++){
    		int a,b;cin>>a>>b;--a;--b;adj[a].push_back(b);
    		adj[b].push_back(a);
    	}
    	vector<map<int,int>>mp(n);long long ans=0;
    	function<void(int,int)>dfs=[&](int src,int par){
    		//assuming the current node is the lca and also one end of the path
    		
    		for(auto it:adj[src]){
    			if(it==par)continue;
    			dfs(it,src);
    			auto i=mp[it].find(c[src]);
    			if(i!=mp[it].end()){
    				ans+=mp[it][c[src]];
    				mp[it].erase(i);
    			}
    			//small to large merging
    			if(mp[it].size()>mp[src].size()){
    				swap(mp[it],mp[src]);
    			}	
    		}
    		//assuming the current node is the lca but not at the end of the path
    		for(auto it:adj[src]){
    			if(it==par)continue;
    			for(auto i:mp[it]){
    				auto x=mp[src].find(i.first);
    				if(x!=mp[src].end()){
    					ans+=((long long)mp[src][i.first] * i.second);
    				}
    				mp[src][i.first]+=i.second;
    			}
    		}
    		mp[src][c[src]]++;
    	};
    	dfs(0,-1);
    	cout<<ans<<endl;
    }
    return 0;
}
//problem link:-https://codeforces.com/contest/1923/problem/E
