#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
const int mod =1000000007; 
const ll N=100001;
const ll maxn=100005;
vector<ll>ifact,inverse,fact;
template<typename T> T gcd(T a, T b){return(b?__gcd(a,b):a);} 
template<typename T> T lcm(T a, T b){return(a*(b/gcd(a,b)));} 
ll add(ll a, ll b, ll c = mod){ll res=a+b;return(res>=c?res-c:res);} 
ll mod_neg(ll a, ll b, ll c = mod){ll res;if(abs(a-b)<c)res=a-b;else res=(a-b)%c;return(res<0?res+c:res);} 
ll mul(ll a, ll b, ll c = mod){ll res=(ll)a*b;return(res>=c?res%c:res);} 
template<typename T>T binpow(T e, T n, T m = mod){T x=1,p=e;while(n){if(n&1)x=mul(x,p,m);p=mul(p,p,m);n>>=1;}return x;} 
template<typename T>T extended_euclid(T a, T b, T &x, T &y){T xx=0,yy=1;y=0;x=1;while(b){T q=a/b,t=b;b=a%b;a=t;t=xx;xx=x-q*xx;x=t;t=yy;yy=y-q*yy;y=t;}return a;}
void inv(ll p=mod){inverse.resize(maxn);inverse[0] = inverse[1] = 1;for (int i = 2; i <= N; i++){inverse[i] = inverse[p % i] * (p - p / i) % p;}}
void InverseofFactorial(ll p=mod){ifact.resize(maxn);ifact[0] = ifact[1] = 1;for (int i = 2; i <= N; i++){ifact[i] = (inverse[i] * ifact[i - 1]) % p;}}
void factorial(ll p=mod){fact.resize(maxn);fact[0] = 1;for (int i = 1; i <= N; i++) {fact[i] = (fact[i - 1] * i) % p;}}
ll ncr(ll n,ll r,ll c = mod){ return mul(mul(ifact[r],ifact[n-r],c),fact[n],c);}
ll mod_inverse(ll A, ll M=mod)
{ll m0 = M;ll y = 0, x = 1;
 if (M == 1)return 0;
    while (A > 1) {
        ll q = A / M;
        ll t = M;
        M = A % M, A = t;
        t = y;
        y = x - q * y;
        x = t;}
    if (x < 0)x += m0;
    return x;}
const int P = 998244353, Q = 1e9 + 33, R = 99999989;
const int base = 10;
struct Tree {
  int n;
  vector<vector<int>> g;
  Tree() {}
  Tree(int _n) : n(_n) {
    g.resize(n + 1);
  }
  void add_edge(int u, int v) {
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vector<int> bfs(int s) {
    queue<int> q;
    vector<int> d(n + 1, n * 2);
    d[0] = -1;
    q.push(s);
    d[s] = 0;
    while(!q.empty()) {
      int u = q.front();
      q.pop();
      for(auto v : g[u]) if(d[u] + 1 < d[v]) {
          d[v] = d[u] + 1;
          q.push(v);
        }
    }
    return d;
  }
  vector<int> get_centers() {
    auto du = bfs(1);
    int v = max_element(du.begin(), du.end()) - du.begin();
    auto dv = bfs(v);
    int u = max_element(dv.begin(), dv.end()) - dv.begin();
    du = bfs(u);
    vector<int> ans;
    for(int i = 1; i <= n; i++) if(du[i] + dv[i] == du[v] && du[i] >= du[v] / 2 && dv[i] >= du[v] / 2) {
        ans.push_back(i);
      }
    return ans;
  }
  //we need to assign canonical names to each vertex apparently.
  int yo(int u, int pre = 0) {
    vector<int> nw;
    for(auto v : g[u]) if(v != pre) nw.push_back(yo(v, u));
    int ans = 0;
    for(auto x : nw) {
      ans = add(ans ,binpow(P,x));
    }
    ans = add(mul(ans , Q) , R);
    return ans;
  }
  bool iso(Tree &t) {
    auto a = get_centers();
    auto b = t.get_centers();
//if the canonical names of both the centers are the same then it is isomorphic.
    for(auto x : a) for(auto y : b) if(yo(x) == t.yo(y)) return 1;
    return 0;
  }
};
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    Tree t1(n);
    for(int i = 1; i < n; i++) {
      int u, v;
      cin >> u >> v;
      t1.add_edge(u, v);
    }
    Tree t2(n);
    for(int i = 1; i < n; i++) {
      int u, v;
      cin >> u >> v;
      t2.add_edge(u, v);
    }
    if(t1.iso(t2)) cout << "YES\n";
    else cout << "NO\n";
  }
  return 0;
}
// https://www.spoj.com/problems/TREEISO/
