void print_divisors(int n) {
        // Code here.
        vector<int>ans;
	    for(int i=1;i<=sqrt(n);i++)
	    {   
	        if(n%i==0)
	        {
	            ans.push_back(i);
	            int t=n/i;
	          ans.push_back(t);
	        }
	        
	    }
	    
	    for(auto x:ans)
	    {
	        cout<<x<<" ";
	    }
    }
