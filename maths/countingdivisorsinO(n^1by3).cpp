//source :-https://codeforces.com/blog/entry/22317
N = input()
primes = array containing primes till 10^6
ans = 1
for all p in primes :
            if p*p*p > N:
                  break
            count = 1
            while N divisible by p:
                  N = N/p
                  count = count + 1
            ans = ans * count
if N is prime:
            ans = ans * 2
else if N is square of a prime:
            ans = ans * 3
else if N != 1:
            ans = ans * 4
