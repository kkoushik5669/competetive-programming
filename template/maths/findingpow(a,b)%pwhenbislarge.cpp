//iterativeapproach according to fermats theorem pow(a,p-1)%p  is equal to 1 where p is prime.
//A^B mod M = ( A^(M-1) * A^(M-1) *.......* A^(M-1) * A^(x) ) mod M
//Where x is B mod M-1 and A ^ (M-1) continues B/(M-1) times
//Now, from Fermat’s Little Theorem,  
//A ^ (M-1) mod M = 1.
//Hence, 
//A^B mod M = ( 1 * 1 * ....... * 1 * A^(x) ) mod M
ll power(ll x, ll y, ll p)
{
    ll res = 1; // Initialize result
 
    // Update x if it is more than or
    // equal to p
    x = x % p;
 
    while (y > 0) {
       
        // If y is odd, multiply x
        // with the result
        if (y & 1)
            res = (res * x) % p;
 
        // y must be even now
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}
// Driver Code
int main()
{
    ll a = 3;
 
    // String input as b is very large
    string b = "100000000000000000000000000";
   // you can change the b;
    ll remainderB = 0;
    ll MOD = 1000000007;
 
    // Reduce the number B to a small number
    // using Fermat Little
    for (int i = 0; i < b.length(); i++)
        remainderB = (remainderB * 10 +
                       b[i] - '0') % (MOD - 1);
 
    cout << power(a, remainderB, MOD) << endl;
    return 0;
}
