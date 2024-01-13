int phi(int n) {
    int result = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}
//some properties of phi;
//phi(p) =p-1 when p is a prime
//phi(p ^k)=p^k-p^k-1
//phi(a*b)=phi(a)*phi(b) where a and b are relatively prime
//phi(ab)=phi(a)*phi(b)*(d/phi(d)) with d=__gcd(a,b)
//phi(n)=n(1-1/p1)(1-1/p2)(1-1/p3)..with this formula calculate phi(n)
