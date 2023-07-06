vector<int>AllPrimeFactors(int n) {
	    // Code here
	    vector<int>v;
	    vector<bool>isprime(n+1,true);
	    for(int i=2;i*i<=n;i++){
	        if(isprime[i]){
	            for(int j=i*i;j<=n;j+=i){
	                isprime[j]=false;
	            }
	        }
	    }
    int last=0;
	    for(int i = 2; i <= sqrt(n); i++){
    	    if(n % i == 0 && isprime[i]){
    	        v.emplace_back(i);
            last=i;
    	    }
    	}
  if(isprime[n/last]){v.emplace_back(n/last);}
        return v;
	}
