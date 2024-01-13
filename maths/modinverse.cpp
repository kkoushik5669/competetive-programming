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
