#include<bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long 
#define int long long 
int mod;
ll add(ll a, ll b, ll c = mod){ll res=a+b;return(res>=c?res-c:res);} 
ll mod_neg(ll a, ll b, ll c = mod){ll res;if(abs(a-b)<c)res=a-b;else res=(a-b)%c;return(res<0?res+c:res);} 
ll mul(ll a, ll b, ll c = mod){ll res=(ll)a*b;return(res>=c?res%c:res);} 
struct DSU {
	vector<int> e;
	void init(int n) { e = vector<int>(n, -1); }
	int get(int x) { return (e[x] < 0 ? x : e[x] = get(e[x])); }
	bool sameSet(int x, int y) { return get(x) == get(y); }
	int size(int x) { return -e[get(x)]; }
	bool unite(int x, int y) {
		x = get(x), y = get(y);
		if (x == y) return 0;
		if (e[x] > e[y]) swap(x, y);
		e[x] += e[y];
		e[y] = x;
		return 1;
	}
};
template<typename T>T binpow(T e, T n, T m = mod){T x=1,p=e;while(n){if(n&1)x=mul(x,p,m);p=mul(p,p,m);n>>=1;}return x;} 
main()
{
	//1.dont get stuck on one approach
	//2.think and code
    fastio;
    int n;cin>>n>>mod;
    vector<int>a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    vector<vector<int>>b;
//interesting question on MST .The harder part is to actually figure out whether it is actually dp or coming to conclusion that it is actually an MST problem.
//By the constraints we can build a complete graph .And assume the weight of the edges as (x power y+ y power x)modulo m 
//now just apply to reach all n nodes. for finding the maximum spanning tree.
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			int x=(add(binpow(a[i],a[j]) , binpow(a[j],a[i])));
			b.push_back({x,i,j});
		}
	}
	sort(b.begin(),b.end());
	reverse(b.begin(),b.end());
	DSU ds;
	ds.init(n+1);int ans=0;
	for(auto it:b)
	{
		if(ds.sameSet(it[1],it[2]))continue;
		ans+=it[0];
		ds.unite(it[1],it[2]);
		ds.unite(it[2],it[1]);
	}cout<<ans<<endl;
    return 0;
}
