#include<bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
struct SCC{
	vector<std::vector<int>> G;
	vector<std::vector<int>> G_rev;
	int size;
	SCC(int n):G(n),G_rev(n),size(n){}
	int add_ver(){
		G.push_back({});
		G_rev.push_back({});
		size++;
		return size-1;
	}
	void add_edge(int from,int to){
		assert(0<=to&&to<size);
		assert(0<=from&&from<size);
		G[from].push_back(to);
		G_rev[to].push_back(from);
	}
 
	void dfs1(std::vector<int> &order,std::vector<int> &seen,int ind,int &now){
		if(seen[ind]!=0) return;
		seen[ind]=-1;
		for(auto x:G[ind]){
			dfs1(order,seen,x,now);
		}
		order[now]=ind;
		now++;
	}
	void dfs2(std::vector<int> &seen,int ind,int rank){
		if(seen[ind]!=-1) return;
		seen[ind]=rank;
		for(auto x:G_rev[ind]){
			dfs2(seen,x,rank);
		}
	}
	std::vector<std::vector<int>> tp_sort(){
		std::vector<int> seen(size,0),order(size);
		int now=0;
		for(int i=0;i<size;i++) dfs1(order,seen,i,now);
		now=0;
		for(int i=size-1;i>=0;i--){
			if(seen[order[i]]==-1){
				dfs2(seen,order[i],now);
				now++;
			}
		}
		std::vector<std::vector<int>> ans(now);
		for(int i=0;i<size;i++){
			ans[seen[i]].push_back(i);
		}
		return ans;
	}
	std::vector<int> for_two_sat(){
		std::vector<int> seen(size,0),order(size);
		int now=0;
		for(int i=0;i<size;i++) dfs1(order,seen,i,now);
		now=0;
		for(int i=size-1;i>=0;i--){
			if(seen[order[i]]==-1){
				dfs2(seen,order[i],now);
				now++;
			}
		}
		return seen;
	}
};
int main()
{
	//1.dont get stuck on one approach
	//2.think and code
    fastio;
    int t;cin>>t;
    outer : while(t--)
    {
    	int n,m;cin>>n>>m;
    	//form scc's store the edge wt's for the scc's how? size of the comp and weight of the whole scc
    	vector<vector<int>>adj(n);
    	vector<int>a(n);
    	for(int i=0;i<n;i++)cin>>a[i];
    		
    	SCC G(n);
    	for(int i=0;i<m;i++){
    		int a,b;cin>>a>>b;--a;--b;
    		G.add_edge(a,b);
    	}map<int,int>cc;
    		map<int,long long>wt;
    	vector<vector<int>>ans=G.tp_sort();
    	int x=ans.size();
    	map<int,int>belong;
    	vector<vector<int>>newgraph(x+1);map<int,int>indegree;
    	for(int i=0;i<ans.size();i++){
    		for(auto j:ans[i]){
    			belong[j]=i;cc[i]++;wt[i]+=a[j];
    		}
    	}
    	for(int i=0;i<n;i++){
    		for(auto j:G.G[i]){
    			if(belong[i]!=belong[j]){
    				newgraph[belong[i]].push_back(belong[j]);
    				indegree[belong[j]]++;
    				//cout<<belong[i]<<" "<<belong[j]<<endl;
    			}
    		}
    	}
    	for(int i=0;i<ans.size();i++){
    		if(indegree[i]==0){newgraph[x].push_back(i);indegree[i]++;}
    	}
    	queue<int>q;
    	q.push(x);
    	vector<pair<int,long long>>dp(x+1,{0,LLONG_MAX});
    	dp[x]={0,0};
    	while(q.size()){
    		int ff=q.front();q.pop();
    		for(auto i:newgraph[ff]){
    			indegree[i]--;
    			if(indegree[i]==0){
    				q.push(i);
    			}
    			int newsz=dp[ff].first+cc[i];
    			long long newwt=dp[ff].second+wt[i];
    			if(newsz==dp[i].first){dp[i]={newsz,min(dp[i].second,newwt)};}
    			else if(newsz>dp[i].first){dp[i]={newsz,newwt};}
    		}
    	}
    	int maxsz=0;
    	long long maxval=LLONG_MAX;
    	for(int i=0;i<=x;i++){
    		if(maxsz<dp[i].first){maxsz=dp[i].first;maxval=dp[i].second;}
    		else if(maxsz==dp[i].first){maxval=min(maxval,dp[i].second);}
    	}cout<<maxsz<<" "<<maxval<<endl;
    }
    return 0;
}
//problem link:-https://codeforces.com/problemset/problem/1900/E
