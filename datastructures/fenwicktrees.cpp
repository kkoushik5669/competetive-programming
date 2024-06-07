struct FenwickTree {
    vector<ll> bit;  // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, (ll)0);
    }

    FenwickTree(vector<ll> const &a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            update(i, a[i]);
    }
    void update(int p, ll x) {
        for (; p <= n; p |= (p + 1)) {
            bit[p] += x;
        }
    }
    ll get(int p) {
        ll ret = 0;

        for (; p > 0; --p) {
            ret += bit[p];
            p &= (p + 1);
        }

        return ret;
    }

    ll get(int l, int r) {
        return get(r) - get(l - 1);
    }
};
struct FenwickTree2D {
    vector<vector<int>> bit;
    int n, m;
    FenwickTree2D(int n,int m){
    	this->n=n;
    	this->m=m;bit.assign(n,{});
    	for(int i=0;i<n;i++){bit[i].resize(m);}
    }
    // init(...) { ... }
	FenwickTree2D(vector<vector<int>> &a) : FenwickTree2D(a.size(),a[0].size()) {
        for (size_t i = 0; i < a.size(); i++)
          {
          	for(size_t j=0;j<a[i].size();j++){
          		add(i,j,a[i][j]);
          	}
          }
    }
    int sum(int x, int y) {
        int ret = 0;
        for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
            for (int j = y; j >= 0; j = (j & (j + 1)) - 1)
                ret += bit[i][j];
        return ret;
    }

    void add(int x, int y, int delta) {
        for (int i = x; i < n; i = i | (i + 1))
            for (int j = y; j < m; j = j | (j + 1))
                bit[i][j] += delta;
    }
};
