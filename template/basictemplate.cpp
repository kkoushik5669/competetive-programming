#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> // for less
#define ll long long
#define ld long double
#define vi vector<int>
#define vvi vector<vector<int>>
#define ff first
#define ss second
#define pb push_back
#define all(e) e.begin(),e.end()
#define to_upper(s1) transform(s1.begin(), s1.end(), s1.begin(), ::toupper);
#define to_lower(s2) transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
#define mod 1000000007
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define precise(n) fixed<<setprecision(n)
#define amax(a,b) a=max(a,b)
#define amin(a,b) a=min(a,b)
#define bug(...)  __f (#__VA_ARGS__, __VA_ARGS__)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repl(i,a,b) for(int i=a-1;i>=b;i--)
#define tiii tuple<int,int,int>
#define pii pair<int,int>
#define printa(a,x,y) for(int i=x;i<y;i++)cout<<a[i]<<" ";cout<<endl;
#define printv(v) for(auto it:v)cout<<it<<" ";cout<<endl;
#define printp(v) for(auto it:v)cout<<it.first<<" "<<it.second<<endl;
#define reada(a,x,y) for(int i=x;i<y;i++){cin>>a[i];}
#define readv(v,n) for(int i=0;i<n;i++){cin>>v[i];}
#define reads(s,n) for(int i=0;i<n;i++){int x; cin>>x; s.insert(x);}
const ll inf=(1LL<<62);
const ld ep=0.000000001;
const ld pi=acos(-1.0);
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set=tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
//red black trees.
//*find_by_order();//it finds the element at that index
//order_of_key();//it find the number of elements strictly less than the key
template<typename... T>void read(T&... args) { ((cin >> args), ...);}
template<typename... T>void print(T&&... args) { ((cout << args << " "), ...);}
template<typename... T>void printl(T&&... args) { ((cout << args << " "), ...); cout<<'\n';}
template <typename Arg1>void __f (const char* name, Arg1&& arg1) { cout << name << " = " << arg1 << endl; }
template <typename Arg1, typename... Args>void __f (const char* names, Arg1&& arg1, Args&&... args)
{
    const char* comma = strchr (names + 1, ',');
    cout.write (names, comma - names) << " = " << arg1 << " , "; __f (comma + 1, args...);
}
const ll N=100001;
void solve()
{
    
}
signed main()
{
    fastio;
    clock_t z=clock();
    ll t=1;
    // cin>>t;
    while(t--)
    {
    solve();
    }
    cerr<<"Run time :"<<((double)(clock()-z)/CLOCKS_PER_SEC);
}
