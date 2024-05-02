	#include<bits/stdc++.h>
	using namespace std;
	#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	struct item
	{
	    int val;
	};
	struct segtree
	{
	    int size;
	 	vector<item>values;
	    item NEUTRAL_ELEMENT={0};
	    item merge(item a,item b)
	    {return {max(a.val,b.val)
	        };
	    }  
	    item single(int v)
	    {
	        return {v};
	    }
	    void init(int n)
	    {
	        size=1;
	        while(size<n ){size*=2;}
	        values.resize(2*size);
	    }
	    void build(int n,int x,int lx,int rx)
	    {
	        if(rx-lx==1)
	        {if(lx<n)
	            {
	                values[x]={0};
	            }return;
	        }
	        int m=(lx+rx)>>1;
	        build(n,2*x+1,lx,m);
	        build(n,2*x+2,m,rx);
	        values[x]=merge(values[2*x+1],values[2*x+2]);
	    }
	    void build(int n)
	    {
	        build(n,0,0,size);
	    }
	    void set(int i ,int v,int x,int lx,int rx)
	    {
	        if(rx-lx==1)
	        {
	            values[x]=single(v);return;
	        }
	        int m=(lx+rx)>>1;
	        if(i<m)
	        {
	            set(i,v,2*x+1,lx,m);
	        }
	        else
	        {
	            set(i,v,2*x+2,m,rx);
	        }
	        values[x]=merge(values[2*x+1],values[2*x+2]);
	    }
	    void set(int i,int v)
	    {
	        set(i,v,0,0,size);
	    }
	    item calc(int l,int r,int x,int lx,int rx)
	    {
	        if(lx>=r || l>=rx){return NEUTRAL_ELEMENT;}
	        if(lx>=l and rx<=r){return values[x];}
	        int m=(lx+rx)/2;
	        item s1=calc(l,r,2*x+1,lx,m);
	        item s2=calc(l,r,2*x+2,m,rx);
	        return merge(s1,s2);
	    }
	    item calc(int l,int r)
	    {
	        return calc(l,r,0,0,size);
	    }
	};
	int n;vector<vector<int>>adj;
	const int N=200005;	
	int sz[N];
	int heavy[N];
	void computeHeavyEdges(int src=0,int par=-1){
		sz[src]=1;int currheavy=-1;
		for(auto i:adj[src]){
			if(i==par)continue;
			computeHeavyEdges(i,src);
			if(currheavy==-1){
				currheavy=i;
			}
			else{
				if(sz[currheavy]<sz[i]){currheavy=i;}
			}
			sz[src]+=sz[i];
		}
		heavy[src]=currheavy;
	}int chain[N];int father[N];
	void computeHeavychains(int src=0,int par=-1){
		if(par!=-1){chain[heavy[src]]=chain[src];father[src]=par;}
		for(auto i:adj[src]){
			if(i==par)continue;
		computeHeavychains(i,src);
		}
	}
	int timer;
	int assignNodes[N];
	void SetHeavyEdges(int src=0,int par=-1){
		assignNodes[src]=timer;timer++;
		if(heavy[src]!=-1){SetHeavyEdges(heavy[src],src);}	
		for(auto i:adj[src]){
			if(i==par || i==heavy[src])continue;
			SetHeavyEdges(i,src);
		}
	}
	//here tin,tout are only used to check if node u is ancestor of node v or node v
	 //is an ancestor of node u
	 //the remaining code is just using binary lifting
	struct LCA{
		
	int l;
	int x;
	vector<int> tin, tout;
	vector<vector<int>> up;

	void dfs(int v, int p)
	{
	    tin[v] = ++x;
	    up[v][0] = p;
	    for (int i = 1; i <= l; ++i)
	        up[v][i] = up[up[v][i-1]][i-1];

	    for (int u : adj[v]) {
	        if (u != p)
	            dfs(u, v);
	    }

	    tout[v] = ++x;
	}

	bool is_ancestor(int u, int v)
	{
	    return tin[u] <= tin[v] && tout[u] >= tout[v];
	}

	int lca(int u, int v)
	{
	    if (is_ancestor(u, v))
	        return u;
	    if (is_ancestor(v, u))
	        return v;
	    for (int i = l; i >= 0; --i) {
	        if (!is_ancestor(up[u][i], v))
	            u = up[u][i];
	    }
	    //now we are at the node just below the lca
	    return up[u][0];
	}

	void preprocess(int root,int n) {
	    tin.resize(n);
	    tout.resize(n);
	    x = 0;
	    l = ceil(log2(n));
	    up.assign(n, vector<int>(l + 1));
	    dfs(root, root);
	}
	};
	int querypath(int src,int par,segtree st){int ans=0;
		while(chain[src]!=chain[par]){
			ans=max(ans,st.calc(assignNodes[chain[src]],assignNodes[src]+1).val);
			src=father[chain[src]];
		}ans=max(ans,st.calc(assignNodes[par],assignNodes[src]+1).val);
		return ans;	
	}
	int main()
	{
		//1.dont get stuck on one approach
		//2.think and code
	    fastio;
	    cin>>n;timer=0;
	    adj.assign(n,{});
	    vector<int>val(n);
	    for(int i=0;i<n;i++)cin>>val[i];
	    for(int i=0;i<n-1;i++){
	    	int a,b;cin>>a>>b;--a;--b;adj[a].push_back(b);
	    	adj[b].push_back(a);
	    }
	    computeHeavyEdges();
	    computeHeavychains();iota(chain,chain+n,0);
	    SetHeavyEdges();
	    segtree st;st.init(n);st.build(n);
	    for(int i=0;i<n;i++){
	    	st.set(assignNodes[i],val[i]);
	    	}
	    LCA lca;lca.preprocess(0,n);
	    int q;cin>>q;
	    while(q--){
	    	int type;
	    	cin>>type;
	    	if(type==1){int i;cin>>i;--i;
	    		int x;cin>>x;
	    		st.set(assignNodes[i],x);
	    	}
	    	else{
	    		int a,b;cin>>a>>b;--a;--b;
	    		int l=lca.lca(a,b);
	    		cout<<max(querypath(a,l,st),querypath(b,l,st))<<endl;
	    	}
	    }
	    return 0;
	}
