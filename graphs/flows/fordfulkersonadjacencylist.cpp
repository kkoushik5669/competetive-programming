#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Edge {
public:
    int from, to;
    Edge* residual;
    long long flow, cost;
    const long long capacity, originalCost;

    Edge(int from, int to, long long capacity, long long cost = 0)
        : from(from), to(to), capacity(capacity), originalCost(cost), cost(cost), flow(0) {}

    // Check if the edge is a residual edge
    bool isResidual() {
        return capacity == 0;
    }

    // Calculate remaining capacity of the edge
    long long remainingCapacity() {
        return capacity - flow;
    }

    // Augment flow along the edge
    void augment(long long bottleNeck) {
        flow += bottleNeck;
        residual->flow -= bottleNeck;
    }

    // To display the edge info
    string toString(int s, int t) {
        string u = (from == s) ? "s" : ((from == t) ? "t" : to_string(from));
        string v = (to == s) ? "s" : ((to == t) ? "t" : to_string(to));
        return "Edge " + u + " -> " + v + " | flow = " + to_string(flow) + " | capacity = " + to_string(capacity) + " | is residual: " + (isResidual() ? "true" : "false");
    }
};

class FordFulkersonDfsSolverAdjacencyList {
private:
    int n, s, t;
    long long maxFlow;
    bool solved;
    vector<vector<Edge*>> graph;
    vector<int> visited;
    vector<bool> minCut;
    int visitedToken;

    // DFS to find an augmenting path
    long long dfs(int node, long long flow) {
        if (node == t) return flow;
        visited[node] = visitedToken;

        for (Edge* edge : graph[node]) {
            long long rcap = edge->remainingCapacity();
            if (rcap > 0 && visited[edge->to] != visitedToken) {
                long long bottleNeck = dfs(edge->to, min(flow, rcap));

                // Augment flow if a path is found
                if (bottleNeck > 0) {
                    edge->augment(bottleNeck);
                    return bottleNeck;
                }
            }
        }
        return 0;
    }

    void solve() {
        for (long long f = dfs(s, LLONG_MAX / 2); f != 0; f = dfs(s, LLONG_MAX / 2)) {
            visitedToken++;
            maxFlow += f;
        }

        for (int i = 0; i < n; i++) {
            if (visited[i] == visitedToken) minCut[i] = true;
        }
    }

public:
    FordFulkersonDfsSolverAdjacencyList(int n, int s, int t) : n(n), s(s), t(t), maxFlow(0), solved(false), visited(n, 0), minCut(n, false), visitedToken(1) {
        graph.resize(n);
    }

    // Add an edge to the flow network
    void addEdge(int from, int to, long long capacity, long long cost = 0) {
        Edge* e1 = new Edge(from, to, capacity, cost);
        Edge* e2 = new Edge(to, from, 0, -cost);
        e1->residual = e2;
        e2->residual = e1;
        graph[from].push_back(e1);
        graph[to].push_back(e2);
    }

    // Get the maximum flow in the flow network
    long long getMaxFlow() {
        if (!solved) {
            solve();
            solved = true;
        }
        return maxFlow;
    }

    // Get the graph after solving the flow problem
    vector<vector<Edge*>>& getGraph() {
        if (!solved) {
            solve();
            solved = true;
        }
        return graph;
    }

    // Get the minimum cut of the flow network
    vector<bool> getMinCut() {
        if (!solved) {
            solve();
            solved = true;
        }
        return minCut;
    }
};

// Example from slides
void exampleFromSlides() {
    int n = 12;
    int s = n - 2;
    int t = n - 1;

    FordFulkersonDfsSolverAdjacencyList solver(n, s, t);

    solver.addEdge(s, 1, 2);
    solver.addEdge(s, 2, 1);
    solver.addEdge(s, 0, 7);

    solver.addEdge(0, 3, 2);
    solver.addEdge(0, 4, 4);

    solver.addEdge(1, 4, 5);
    solver.addEdge(1, 5, 6);

    solver.addEdge(2, 3, 4);
    solver.addEdge(2, 7, 8);

    solver.addEdge(3, 6, 7);
    solver.addEdge(3, 7, 1);

    solver.addEdge(4, 5, 8);
    solver.addEdge(4, 8, 3);

    solver.addEdge(5, 8, 3);

    solver.addEdge(6, t, 1);
    solver.addEdge(7, t, 3);
    solver.addEdge(8, t, 4);

    cout << "Max Flow: " << solver.getMaxFlow() << endl;

    vector<vector<Edge*>> graph = solver.getGraph();
    for (auto& edges : graph) {
        for (Edge* e : edges) {
            if (e->to == s || e->from == t) continue;
            if (e->from == s || e->to == t || e->from < e->to) {
                cout << e->toString(s, t) << endl;
            }
        }
    }
}

int main() {
    exampleFromSlides();
    return 0;
}
