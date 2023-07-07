#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	#ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);
	    freopen("output.txt","w",stdout);
	#endif
	ll n;cin>>n;set<pair<ll,ll>>st;
	for(int i=0;i<n;i++)
	{
		int a,b;cin>>a>>b;st.insert({a,1});st.insert({b,-1});
	}
	ll ans=0;ll c=0;ll finalans=0;
	for(auto it:st)
	{
		ans+=it.second;
		if(ans==0){finalans++;}
		if(ans<0){ans=0;}
		if(ans>1){ans=1;}
	}
	cout<<finalans<<endl;
	return 0;
}
