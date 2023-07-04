bool Primecheck(int n)
{
    if(n == 1)
        return false ;
 
    for(int i = 2 ; i <= sqrt(n) ; i++)
    {
        if(n%i == 0)
        {
            return false ;
        }
    }
    return true;
}
 
const int N = 10000005;
vector<int> primes ;
vector<bool> isPrime(N,1);
 
void Sieve()
{
    isPrime[0] = isPrime[1] = 0;
    for(long long i = 2; i * i < N; i++)
        if(isPrime[i])
            for(int j = 2 * i; j < N; j += i)
                isPrime[j] = 0;
 
    for(int i = 0; i < N; i++)
    {
        if(isPrime[i])
            primes.push_back(i);
    }
}
