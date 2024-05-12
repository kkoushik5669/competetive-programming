#include<bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
mt19937 rnd(std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count());
int randint(int L, int R) {
    uniform_int_distribution<int> dist(L, R);
    return dist(rnd);
}
typedef long long ll;
int main()
{
    //1.dont get stuck on one approach
    //2.think and code
    fastio;
    //withoutupdates
    //using sorting comparator
    //mo's algorithm for finding prefix sums
    int n;cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int q;cin>>q;
    vector<pair<pair<int,int>,int>>queries;
    vector<int>ans(q);int id=0;
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
    int sum=0;
    int r=-1;
    int l=0;
    for(int i=0;i<(int)queries.size();i++){
        int R=queries[i].first.second;
        int L=queries[i].first.first;
        while(r<R){
            ++r;
            sum+=a[r];
        }
        while(l<L){
            sum-=a[l];
            l++;
        }
        while(l>L){
            --l;
            sum+=a[l];
        }
        while(r>R){
            sum-=a[r];
            --r;
        }
        ans[queries[i].second]=sum;
    }
    for(int i=0;i<(int)ans.size();i++){
        cout<<ans[i]<<" ";
    }cout<<endl;
    return 0;
}
