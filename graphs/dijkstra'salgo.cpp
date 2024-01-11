priority_queue<iPair, vector<iPair>, greater<iPair> >
        pq;
    vector<int> dist(V, 1e18);

    pq.push(make_pair(0, src));
    dist[src] = 0;

    while (!pq.empty()) {

        int u = pq.top().second;
        pq.pop();
        list<pair<int, int> >::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i) {
            int v = (*i).first;
            int weight = (*i).second;
            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
