//problem link:-https://codeforces.com/contest/1721/problem/E
//mysolution
#include<bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
mt19937 rnd(std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count());
int randint(int L, int R) {
    uniform_int_distribution<int> dist(L, R);
    return dist(rnd);
}
typedef long long ll;
int alr[1000050];
int aut[1000015][26];
void prefix_function(string s) {
    int n = (int)s.length();
    for (int i = 1; i < n; i++) {
        int j = alr[i-1];
        while (j > 0 && s[i] != s[j])
            j = alr[j-1];
        if (s[i] == s[j])
            j++;
        alr[i] = j;
    }
}
void rem(string &s,string &x){
    int n=s.length();
    int m=x.length();
    s+=x;
    for (int i = n; i < n+m; i++) {
        for (int c = 0; c < 26; c++) {
          //applying automaton on query string
            if (i > 0 && 'a' + c != s[i])
                aut[i][c] = aut[alr[i-1]][c];
            else
                aut[i][c] = i + ('a' + c == s[i]);
        }
        alr[i] = aut[alr[i-1]][s[i]-'a'];
    }
    for(int i=0;i<m;i++)s.pop_back();
}
int main()
{
    //1.dont get stuck on one approach
    //2.think and code
    fastio;
    // int t;cin>>t;
    // outer : while(t--)
    {
        string s;cin>>s;
        int q;cin>>q;int n=s.length();
       prefix_function(s);
       //o(n)
      //applying automaton on given string
       for (int i = 0; i < n; i++) {
        for (int c = 0; c < 26; c++) {
            if (i > 0 && 'a' + c != s[i])
                aut[i][c] = aut[alr[i-1]][c];
            else
                aut[i][c] = i + ('a' + c == s[i]);
        }
        }
        while(q--){
            string x;cin>>x;
            rem(s,x);
            for(int i=n;i<n+(int)x.length();i++){cout<<alr[i]<<" ";}
           cout<<endl;
        }
    }
    return 0;
}
