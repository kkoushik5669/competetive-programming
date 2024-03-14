#include<bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int dp[11][11][2];
vector<int>num;
int mem(int d,int cnt,int k,int f,int len){
	if(cnt>k)return 0;
	if(len==num.size()){
		if(cnt==k)return 1;
		return 0;
	}
	if(dp[len][cnt][f]!=-1)return dp[len][cnt][f];
	int lim=-1;
	if(f==1){
		lim=9;
	}
	else{
		lim=num[len];
	}int res=0;
	for(int i=0;i<=lim;i++){
		int nf=f;
		int ncnt=cnt;
		if(i==d){ncnt++;}
		if(i<lim){nf=1;}
		res+=mem(d,ncnt,k,nf,len+1);
	}
return dp[len][cnt][f]=res;
}
int solve(int x,int d,int k){
	num.clear();
	int y=x;
	while(y){
		num.push_back(y%10);
		y/=10;
	}
	reverse(num.begin(),num.end());
	// for(auto it:num)cout<<it<<" ";
	for(int i=0;i<11;i++){for(int j=0;j<11;j++){for(int k=0;k<2;k++){dp[i][j][k]=-1;}}}
	return mem(d,0,k,0,0);
}
int main()
{
	//1.dont get stuck on one approach
	//2.think and code
    fastio;
    //digit dp 
    //basic model
    //numbers less than or equal to <=x
    //has the digit d exactly k times
    int a,b;cin>>a>>b;
    int d;cin>>d;
    int k;cin>>k;
    cout<<solve(b,d,k)-solve(a-1,d,k)<<endl;
    return 0;
}
