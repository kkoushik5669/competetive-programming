vector<int>primes;vector<bool>isprime(N);
bool prime(ll n) {if (n < 2) return false;for (int x = 2; x*x <= n; x++) {if (n%x == 0) return false;}return true;}
void seives()
{int i;for(i=2;i*i<N;i++){if(isprime[i]==false){primes.push_back(i);for(int j=i*i;j<N;j+=i){isprime[j]=true;}}}for(;i<N;i++){if(isprime[i]==false){primes.push_back(i);}}}
//O(nlnln(rootn))
