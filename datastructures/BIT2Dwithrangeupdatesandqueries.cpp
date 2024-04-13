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
