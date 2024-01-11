#include<bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long 
main()
{
    fastio;
    int n,q;cin>>n>>q;
    vector<vector<int>>sparse(n+1,vector<int>(22,0));
    for(int i=2;i<=n;i++)
    {
        cin>>sparse[i][0];
    }const int lgn=21;
    for(int j=1;j<=lgn;j++)
    {
        for(int i=1;i<=n;i++)
        {
            sparse[i][j]=sparse[sparse[i][j-1]][j-1];
        }
    }
    
    while(q--)
    {
        int i,k;cin>>i>>k;
        for(int j=lgn;j>=0;j--)
        {
            if((1LL<<j)<=k)
            {
                k-=(1LL<<j);
                i=sparse[i][j];
            }
        }
        if(i==0)cout<<-1<<endl;
        else cout<<i<<endl;
    }
    return 0;
}
