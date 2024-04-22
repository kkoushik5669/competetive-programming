#include<bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main()
{
    //1.dont get stuck on one approach
    //2.think and code
//we color (the whole grid into only three colors) why?
    fastio;
    int t;cin>>t;
    outer : while(t--)
    {
        int n;cin>>n;
        string s[n];vector<vector<pair<int,int>>>ans(3);
        for(int i=0;i<n;i++){cin>>s[i];
        for(int j=0;j<n;j++){
            if(s[i][j]=='X'){
                ans[(i+j)%3].push_back({i,j});
            }
        }
    }
        if(ans[0].size()<=ans[1].size() and ans[0].size() <=ans[2].size()){
            for(auto i:ans[0]){
                s[i.first][i.second]='O';
            }
        }
        else if(ans[1].size()>=ans[2].size() and ans[2].size()<=ans[0].size()){
            for(auto i:ans[2]){
                s[i.first][i.second]='O';
            }
        }
        else{
            for(auto i:ans[1]){
                s[i.first][i.second]='O';
            }
        }
        for(int i=0;i<n;i++){
            cout<<s[i]<<endl;
        }
    }
    return 0;
}
//problem link:-https://codeforces.com/contest/1450/problem/C1
