#include<bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long 
const ll mod =1000000007;
const ll maxn=200005;
const int N=200005;
vector<ll>ifact,inverse,fact;

ll add(ll a, ll b, ll c = mod){ll res=a+b;return(res>=c?res-c:res);} 
ll mod_neg(ll a, ll b, ll c = mod){ll res;if(abs(a-b)<c)res=a-b;else res=(a-b)%c;return(res<0?res+c:res);} 
ll mul(ll a, ll b, ll c = mod){ll res=(ll)a*b;return(res>=c?res%c:res);} 
void inv(ll p=mod){inverse.resize(maxn);inverse[0] = inverse[1] = 1;for (int i = 2; i <= N; i++){inverse[i] = inverse[p % i] * (p - p / i) % p;}}
void InverseofFactorial(ll p=mod){ifact.resize(maxn);ifact[0] = ifact[1] = 1;for (int i = 2; i <= N; i++){ifact[i] = (inverse[i] * ifact[i - 1]) % p;}}
void factorial(ll p=mod){fact.resize(maxn);fact[0] = 1;for (int i = 1; i <= N; i++) {fact[i] = (fact[i - 1] * i) % p;}}
ll ncr(ll n,ll r,ll c = mod){ return mul(mul(ifact[r],ifact[n-r],c),fact[n],c); }  
// returns the number of solutions to the equation
// x_1 + x_2 + ... + x_n = s and 0 <= l <= x_i <= r
ll ans(int n,int s,int l,int r)
{
    if (s < l * n) return 0;
  s -= l * n;
  r -= l;
  ll val = 0;
  for (int k = 0; k <= n; k++) {
    ll cur = ncr(s - k - k * r + n - 1 + 1, n - 1 + 1) * ncr(n, k);
    if (k & 1) val -= cur;
    else val += cur;
  }
  return val;
}
int main()
{
    fastio;
    factorial();
    inv();
    InverseofFactorial();
    return 0;
}
