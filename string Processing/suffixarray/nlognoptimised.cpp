#include<bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
void count_sort(vector<int>&p,vector<int>&c)
{
    int n=p.size();
        
    vector<int>cnt(n,0);
    for(auto it:c){cnt[it]++;}
    vector<int>p_new(n);
    vector<int>pos(n);
    pos[0]=0;
    for(int i=1;i<n;i++)
    {
        pos[i]=pos[i-1]+cnt[i-1];
    }
    for(auto x:p)
    {
        int i=c[x];
        p_new[pos[i]]=x;
        pos[i]++;
    }
    p=p_new;
    
}
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
    {
        for(int i=0;i<n;i++)
        {
            p[i]=(p[i]-(1LL<<k)+n)%n;
        }
        count_sort(p,c);
        vector<int>c_new(n);
        c_new[p[0]]=0;
        for(int i=1;i<n;i++)
        {
            pair<int,int>prev={c[p[i-1]],c[(p[i-1]+(1LL<<k))%n]};
            pair<int,int>now={c[p[i]],c[(p[i]+(1LL<<k))%n]};
            if(now==prev){c_new[p[i]]=c_new[p[i-1]];}
            else c_new[p[i]]=1+c_new[p[i-1]];
        }
        c=c_new;
        k++;
    }
    for(int i=0;i<n;i++)cout<<p[i]<<" ";
        cout<<endl;
    for(int i=0;i<n;i++){cout<<s.substr(p[i])<<endl;}
    return 0;
}
