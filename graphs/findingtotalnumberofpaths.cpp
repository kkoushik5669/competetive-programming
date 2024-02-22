#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef basic_string<int> BI;
typedef long long ll;
typedef pair<int,int> PII;
typedef double db;
mt19937 mrand(random_device{}()); 
ll mod;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=210000;
int n,m,vis[N],ans;
VI e[N];
void dfs(int x) {
	vis[x]=1;
	++ans;
	if (ans>=1000000) {
		printf("%d\n",ans);
		exit(0);
	}
	for (auto v:e[x]) if (!vis[v]) {
		dfs(v);
	}
	vis[x]=0;
}
int main() {
	scanf("%d%d", &n,&m);
	for (int i=1;i<=m;i++) {
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].pb(v);
		e[v].pb(u);
	}
	dfs(1);
	printf("%d\n",ans);
}
//problem link:-https://atcoder.jp/contests/abc284/tasks/abc284_e
