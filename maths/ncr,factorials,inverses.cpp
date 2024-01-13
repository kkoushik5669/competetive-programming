vector<ll>ifact,inverse,fact;
void inv(ll p=mod){inverse.resize(maxn);inverse[0] = inverse[1] = 1;for (int i = 2; i <= N; i++){inverse[i] = inverse[p % i] * (p - p / i) % p;}}
void InverseofFactorial(ll p=mod){ifact.resize(maxn);ifact[0] = ifact[1] = 1;for (int i = 2; i <= N; i++){ifact[i] = (inverse[i] * ifact[i - 1]) % p;}}
void factorial(ll p=mod){fact.resize(maxn);fact[0] = 1;for (int i = 1; i <= N; i++) {fact[i] = (fact[i - 1] * i) % p;}}
ll ncr(ll n,ll r,ll c = mod){ return mul(mul(ifact[r],ifact[n-r],c),fact[n],c); }  
