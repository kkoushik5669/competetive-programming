ll MaxGcd(ll n, vector<ll>arr) {
        ll m=INT_MIN;
        
        for(int i=0;i<n;i++) m=max(m,arr[i]);
        vector<ll> cnt(m+1,0);
        for(int i=0;i<n;i++) cnt[arr[i]]++;
        
        for(int i=m;i>=2;i--){
            ll c=0;
            for(int j=(m/i);j>=1;j--){
                c+=cnt[i*j];
            }
            
            if(c>1) return i;
        }
        return 1;
    } 
