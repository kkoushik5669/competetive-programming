 long long power(ll n,ll r)
    {
       if(n==0){
           return 0;
       }
       if(r==0){
           return 1;
       }
       long long ans=power(n,r/2);
       if(r%2==0){
           return ((ans%mod)*(ans%mod))%mod;
       }
       else{
           return ((((ans%mod)*(ans%mod))%mod)*n)%mod;
       }
        
