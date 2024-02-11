#define ll              long long
#define vi              vector<int >
#define vil             vector<ll >
#define pb              push_back
#define fi              first
#define sc              second
#define pii             pair<int , int >
//this code repeat three steps
//1.first find the centroid of the currtree
//2.find the number of paths with length k are present with a path which contain this node
//3.now go to each subtree and find the new centroid in them (delete the current centroid you have).
const int N   = 500050;
const int INF = 1e9+100;
ll sol,k,ans;
struct CentroidDecomposition {
    /// cd for Centroid Tree
    /// e for Main tree
	vector<vi> cd, &e;
	/// tocheck for checking a node is already in centroid tree or not?
	vector<bool> tocheck;
	/// p for tracking parent of a node
	/// cnt for counting length
	vi size, p,cnt;
	/// centroid Tree root
	int root;
	CentroidDecomposition(vector<vi> &tree) : e(tree) {
		int sz = e.size();
		tocheck.assign(sz, true);
		col.assign(sz, false);
		cd.assign(sz, vi());
		p.assign(sz, -1);
		cnt.assign(N, 0);
		size.assign(sz, 0);
		dfs(0);
		root = decompose(0, sz,-1);
	}
	void dfs(int u) {
		for (int v : e[u]) {
			if (v == p[u]) continue;
			p[v] = u;
			dfs(v);
			size[u] += 1 + size[v];
		}
	}
/// we can solve it for any amount of k
void dfs2(int u,int p,int val,bool flag)
{
    if(flag) cnt[val]++;
    else cnt[val]--;
    for(auto v : e[u])
    {
        if(tocheck[v] && v!=p)
        {
            dfs2(v,u,val+1,flag);
        }
    }

}
void solve(int u,int p,int val)
{
    if(val>k) return ;
    sol+=cnt[k-val];
    for(auto v : e[u])
    {
        if(tocheck[v] && v!=p)
        {
            solve(v,u,val+1);
        }
    }
}
/// finiding centroid and get answer for this centroid
	int decompose(int _u, int sz,int par) {
		int u = _u;
		while (true) {
			int nu = -1;
			for (int v : e[u]) {
				if (!tocheck[v] || v == p[u]) continue;
				if (1 + size[v] > sz / 2) nu = v;
			}
			if (sz - 1 - size[u] > sz / 2 && p[u] != -1
				&&tocheck[p[u]]) nu = p[u];
			if (nu != -1) u = nu; else break;
		}
		for (int v = p[u]; v != -1 && tocheck[v]; v = p[v])
			size[v] -= 1 + size[u];
		sol=0;
		dfs2(u,par,0,1);
		sol+=cnt[k];
		for(auto X : e[u])
        {
            if(tocheck[X])
            {
                dfs2(X,u,1,0);
                solve(X,u,1);
                dfs2(X,u,1,1);
            }
        }
        ans+=sol/2;
        dfs2(u,par,0,0);
		tocheck[u] = false;
		for (int v : e[u]) {
			if (!tocheck[v]) continue;
			int V2 = 1 + size[v];
			if (v == p[u]) V2 = sz - 1 - size[u];
			cd[u].push_back(decompose(v, V2,u));
		}
		return u;
	}
};

int main(){
  //finding all the paths of length k in a given tree.
	int n;
	cin >> n>>k;
	vector<vi> tree(n, vi());
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	CentroidDecomposition cd(tree);
	cout<<ans<<endl;
	return 0;
}
