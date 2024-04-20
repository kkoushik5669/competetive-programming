//this segtree applies ap from right to left
//you can update this segtree to get an ap applying from left to right
struct ap {
    int base, dif;
};
ap add(ap a, ap b)
{
    ap res;
    res.base = a.base + b.base;
    res.dif = a.dif + b.dif;
    return res;
}

int convert(ap a, int n)
{
    int res = (n*a.base);
    res += ((n*(n-1))/2ll)*a.dif;
    return res;
}

int st[4*N], cost[N];
ap lazy[4*N];
ap zero = {0, 0};

void propogate(int node, int l, int r)
{
    st[node] += convert(lazy[node], r-l+1);
    if(l!=r)
    {
        lazy[node*2+1] = add(lazy[node*2+1], lazy[node]);
        int mid = (l+r)/2;
        int rig = (r-mid);
        lazy[node].base += (rig*lazy[node].dif);
        lazy[node*2] = add(lazy[node*2], lazy[node]);
    }
    lazy[node] = zero;
}
void build(int node, int l, int r)
{
    if(l==r)
    {
        st[node] = cost[l];
        lazy[node] = zero;
        return;
    }
    int mid=(l+r)/2;
    build(node*2, l, mid);
    build(node*2+1, mid+1, r);
    st[node] = (st[node*2] + st[node*2+1]);
    lazy[node] = zero; 
    return;
}
void update(int node, int l, int r, int x, int y, ap val)
{
    if(lazy[node].base != 0 || lazy[node].dif != 0)
    propogate(node, l, r);
    if(y<x||x>r||y<l)
    return;
    if(l>=x&&r<=y)
    {
        st[node] += convert(val, r-l+1);
        if(l!=r)
        {
            lazy[node*2+1] = add(lazy[node*2+1], val);
            int mid = (l+r)/2;
            int rig = (r-mid);
            val.base += (rig*val.dif);
            lazy[node*2] = add(lazy[node*2], val);
        }
        return;
    }
    int mid=(l+r)/2;
    update(node*2+1, mid+1, r, x, y, val);
    if(y>mid)
    {
        int rig = (min(y, r)-mid);
        val.base += (rig*val.dif);
    }
    update(node*2, l, mid, x, y, val);
    st[node] = st[node*2] + st[node*2+1];
    return;
}
int query(int node, int l, int r, int x, int y)
{
    if(lazy[node].base != 0 || lazy[node].dif != 0)
    propogate(node, l, r);
    if(y<x||y<l||x>r)
    return 0;
    if(l>=x&&r<=y)
    return st[node];
    int mid=(l+r)/2;
    return query(node*2, l, mid, x, y) + query(node*2+1, mid+1, r, x, y);
}
