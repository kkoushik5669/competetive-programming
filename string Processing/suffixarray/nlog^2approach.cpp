#include<bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main()
{
    //1.dont get stuck on one approach
    //2.think and code
    fastio;
    string s;cin>>s;s+="$";
    int n=s.length();
    vector<int>c(n);vector<int>p(n); 
    {
        //k=0 this is the inital phase 
        vector<pair<char,int>>a;
        for(int i=0;i<n;i++)
        {
            a.push_back({s[i],i});
        }
        sort(a.begin(),a.end());
        for(int i=0;i<n;i++){p[i]=a[i].second;}
        c[p[0]]=0;
        for(int i=1;i<n;i++)
        {
            if(a[i].first==a[i-1].first){c[p[i]]=c[p[i-1]];}
            else c[p[i]]=1+c[p[i-1]];
        }
    }
    int k=0;
    while((1LL<<k)<n)
    {vector<pair<pair<int,int>,int>>a(n);
        for(int i=0;i<n;i++)
        {
            a[i]={{c[i],c[(i+(1LL<<k))%n]},i};
        }
        sort(a.begin(),a.end());
        for(int i=0;i<n;i++){p[i]=a[i].second;}
        c[p[0]]=0;
        for(int i=1;i<n;i++)
        {
            if(a[i].first==a[i-1].first){c[p[i]]=c[p[i-1]];}
            else c[p[i]]=1+c[p[i-1]];
        }k++;
    }
    for(int i=0;i<n;i++)cout<<p[i]<<" ";
        cout<<endl;
    return 0;
}
