//problemlink:-https://codeforces.com/contest/86/problem/D
#include<bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
mt19937 rnd(std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count());
int randint(int L, int R) {
    uniform_int_distribution<int> dist(L, R);
    return dist(rnd);
}
typedef  long long ll;
int occ[1000001];
int main()
{
    //1.dont get stuck on one approach
    //2.think and code
    fastio;
    //withoutupdates
    //using sorting comparator
    //mo's algorithm for finding prefix sums
    int n;cin>>n;
    vector<ll>a(n);int q;cin>>q;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    
    vector<pair<pair<int,int>,int>>queries;
    vector<ll>ans(q);int id=0;
    while(q--){
        int l,r;cin>>l>>r;--l;--r;
        queries.push_back({{l,r},id});id++;
    }
    int s=sqrt(n);
    sort(queries.begin(),queries.end(),[&](pair<pair<int,int>,int>&a,pair<pair<int,int>,int>&b){
        int x=a.first.first/s;
        int y=b.first.first/s;
        if(x!=y){return x<y;}
        return a.first.second<b.first.second;
    });
    ll sum=0;
    int r=-1;
    int l=0;
    for(int i=0;i<(int)queries.size();i++){
        int R=queries[i].first.second;
        int L=queries[i].first.first;ll val=0;
        while(l<L){
            ll x=occ[a[l]];
             val+=(1-(2*x))*a[l];
            occ[a[l]]--;
            l++;
        }
        while(l>L){
            --l;
            ll x=occ[a[l]];
            val+=(1+(2*x))*(a[l]);
            occ[a[l]]++;
        }
        while(r<R){
            ++r;
            ll x=occ[a[r]];
            val+=(1+2*x)*a[r];
            occ[a[r]]++;
        }
        while(r>R){
            ll x=occ[a[r]];
            val+=(1-(2*x))*a[r];
            occ[a[r]]--;
            --r;
        }sum+=val;
        ans[queries[i].second]=sum;
    }
    for(int i=0;i<(int)ans.size();i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}
