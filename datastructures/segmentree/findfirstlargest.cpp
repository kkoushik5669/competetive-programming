#include<bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
struct item
{
    int val;
};
struct segtree
{
    int size;
     vector<item>values;
    item NEUTRAL_ELEMENT={INT_MIN};
    item merge(item a,item b)
    {return {max(a.val,b.val)
        };
    }  
    item single(int v)
    {
        return {v};
    }
    void init(int n)
    {
        size=1;
        while(size<n ){size*=2;}
        values.resize(2*size);
    }
    void build(vector<int>&a,int x,int lx,int rx)
    {
        if(rx-lx==1)
        {if(lx<(int)a.size())
            {
                values[x]=single(a[lx]);
            }return;
        }
        int m=(lx+rx)>>1;
        build(a,2*x+1,lx,m);
        build(a,2*x+2,m,rx);
        values[x]=merge(values[2*x+1],values[2*x+2]);
    }
    void build(vector<int>&a)
    {
        build(a,0,0,size);
    }
    void set(int i ,int v,int x,int lx,int rx)
    {
        if(rx-lx==1)
        {
            values[x]=single(v);return;
        }
        int m=(lx+rx)>>1;
        if(i<m)
        {
            set(i,v,2*x+1,lx,m);
        }
        else
        {
            set(i,v,2*x+2,m,rx);
        }
        values[x]=merge(values[2*x+1],values[2*x+2]);
    }
    void set(int i,int v)
    {
        set(i,v,0,0,size);
    }
    int findfirstlargest(int l,int r,int x,int lx,int rx,int val)
    {
        if(lx>=r || l>=rx){return -1;}
        if(rx-lx==1){if(values[x].val>=val){return lx;}return -1;}
        int m=(lx+rx)/2;
        int s1=-1;
        if(values[2*x+1].val>=val){
            s1=findfirstlargest(l,r,2*x+1,lx,m,val);
            return s1;
        }
        int s2=-1;
        if(values[2*x+2].val>=val){s2=findfirstlargest(l,r,2*x+2,m,rx,val);return s2;}
        return -1;
    }
    int findfirstlargest(int l,int r,int val)
    {
        return findfirstlargest(l,r,0,0,size,val);
    }
};
int main()
{
    //1.dont get stuck on one approach
    //2.think and code
    fastio;
    int n;cin>>n;int q;cin>>q;
    vector<int>a(n)  ;
    for(int i=0;i<n;i++)cin>>a[i];
    segtree st;st.init(n);
st.build(a);
while(q--){
int x;cin>>x;if(x==1){
    int i,v;cin>>i>>v;
    st.set(i,v);
}
    else{
        int v;cin>>v;
        cout<<st.findfirstlargest(0,n,v)<<endl;
    }
}
    return 0;
}
