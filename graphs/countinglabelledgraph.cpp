#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define mod 1000000007
const ll N=1000;
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
int comb[N][N];
void pre() {
  for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) comb[i][j] = 0;
  for(int i=0;i<N;i++) comb[i][0]=1;
  for(int i=1;i<N;i++){
    for(int j=1;j<N;j++) comb[i][j]=add(comb[i-1][j-1],comb[i-1][j]);
  }
}
bool vis[N][N];
int dp[N][N], C[N], G[N];
int yo(int n, int k) {
  if(k > n) return 0;
  if(k == n) return 1;
  if(k == 0) return 0;  
  if(vis[n][k]) return dp[n][k];
  vis[n][k] = 1;
  int ans = 0;
  for(int s = 1; s <= n; s++){
    ans =add(ans, mul(mul(comb[n - 1][s - 1] , C[s]) , yo(n - s, k - 1)));
  }
  return dp[n][k] = ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  pre();
  for(int i = 1; i < N ; i++) G[i] = binpow(2,i*(i-1)/2);
  for(int n = 1; n < N; n++){
    int ans = 0;
    for(int k = 1; k < n; k++){
      ans += mul(mul(k , comb[n][k]) , mul(C[k] , G[n - k]));
    }
    ans /= n;
    C[n] = mod_neg(G[n] , ans);
  }
  int t; cin >> t;
  while(t--){
    int n, k ; cin >> n >> k;
    cout << yo(n, k)<<endl;
  }
  return 0;
}
// https://cp-algorithms.com/combinatorics/counting_labeled_graphs.html
