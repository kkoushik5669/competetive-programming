#include<bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
vector<int>num;
vector<int> pow10(10);
int dp[10][82][82][2];
int mem(int len,int digm,int summ,int f,int k){
	if(len==num.size()){
		if(digm==0 and summ==0 )return 1;
		return 0;
	}
	if(dp[len][digm][summ][f]!=-1)return dp[len][digm][summ][f];
	int res=0;
	int lim=-1;
	if(f){lim=9;}
	else lim=num[len];
	for(int i=0;i<=lim;i++){
		int nf=f;
		if(i<lim)nf=1;
		res+=mem(len+1,(digm+(i*pow10[len])%k)%k,(summ+i)%k,nf,k);
	}
	return dp[len][digm][summ][f]=res;
}
int solve(int x,int k){
	num.clear();
	int y=x;
	while(y){
		num.push_back(y%10);
		y/=10;
	}reverse(num.begin(),num.end());
	int len=num.size();pow10[len-1]=1;
	for(int i=0;i<10;i++){for(int j=0;j<82;j++){for(int k=0;k<82;k++){for(int l=0;l<2;l++)dp[i][j][k][l]=-1;}}}
	for(int i=len-2;i>=0;i--){
		pow10[i]=pow10[i+1]*10;pow10[i]%=k;
	}
	return mem(0,0,0,0,k);
}
int main()
{
	//1.dont get stuck on one approach
	//2.think and code
    fastio;
    int t;cin>>t;int i=1;
    outer : while(t--)
    {
    	int a,b,k;cin>>a>>b>>k;
    	int ans=0;
    	if(k>81){ans=0;}
    	else{
    		ans=solve(b,k)-solve(a-1,k);
    	}
    	cout<<"Case "<<i<<": "<<ans<<endl;i++;
    }
    return 0;
}
//problem link:-https://vjudge.net/problem/LightOJ-1068
