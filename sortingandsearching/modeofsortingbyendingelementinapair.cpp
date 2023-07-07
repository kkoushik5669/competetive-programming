#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	#ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);
	    freopen("output.txt","w",stdout);
	#endif
	ll n;cin>>n;
	vector<pair<int,int>>vec;
	for(int i=0;i<n;i++){int a,b;cin>>b>>a;vec.push_back({a,b});}
	sort(vec.begin(),vec.end());
	ll ans=0;int l=0;
	for(int i=0;i<n;i++)
	{
		if(vec[i].second>=l)
		{
			ans++;l=vec[i].first;
		}
	}
	cout<<ans<<endl;
	return 0;
}
