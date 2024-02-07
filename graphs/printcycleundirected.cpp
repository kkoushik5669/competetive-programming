int n;cin>>n;adj.resize(n+1);
        for(int i=0;i<n;i++){int a,b;cin>>a>>b;adj[a].push_back(b);adj[b].push_back(a);}
        vector<bool>vis(n+1,false);
        vector<int>now;vector<int>p(n+1,0);
        vector<bool>mark(n+1,false);stack<int>st;
        function<bool(int,int)>dfs=[&](int v,int u)
        {
            if(vis[v])
            {
                now.push_back(v);
                        while(st.size() && st.top()!=v)
                        {
                            now.push_back(st.top());
                            st.pop();
                        }return true;
            }
            vis[v]=1;
            st.push(v);
            for(auto it:adj[v])
            {
                if(it!=u)
                {  
                    if(dfs(it,v))return true;
                }
            }st.pop();
            return false;
        };
        dfs(1,0);for(auto it:now){cout<<it<<" ";}
