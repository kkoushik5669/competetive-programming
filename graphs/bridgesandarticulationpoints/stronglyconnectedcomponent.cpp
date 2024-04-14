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
	std::vector<std::vector<int>> givescc(){
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
    	}
    	vector<vector<int>>ans=G.givescc();
    	//ans now have your scc's
    	
    }
    return 0;
}
