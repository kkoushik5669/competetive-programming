#include<bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int nax=200005;
int child[30*nax][2];
int cnt[30*nax];
//applying operation on a trie
int dfs(int node){
	if(cnt[node]){
		return cnt[node];
	}
	vector<int>v;
	for(auto i:{0,1}){
		if(child[node][i]){
			v.push_back(dfs(child[node][i]));
		}
		else{
			v.push_back(0);
		}
	}
	return max(v[0]+min(1,v[1]),v[1]+min(1,v[0]));
}
int main()
{
	//1.dont get stuck on one approach
	//2.think and code
    fastio;
    int n;cin>>n;
    vector<int>a(n);int nxt=0;
//u can use this part as template
    for(int i=0;i<n;i++){
    	cin>>a[i];
    	int node=0;
    	for(int j=29;j>=0;j--){
    		if(!child[node][(a[i]>>j)&1])
    		{
    			child[node][(a[i]>>j)&1]=++nxt;
    		}
    		node=child[node][(a[i]>>j)&1];
    	}
    	cnt[node]++;
    }
    cout<<n-dfs(0)<<endl;
    return 0;
}
