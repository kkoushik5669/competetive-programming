#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <cmath>
#include <climits>

using namespace std;
class Edge {
public:
        int from, to;
        Edge* residual;
        long long flow, capacity, originalCost;

        Edge(int from, int to, long long capacity, long long cost = 0)
            : from(from), to(to), flow(0), capacity(capacity), originalCost(cost) {
            this->residual = nullptr;
        }

        bool isResidual() const {
            return capacity == 0;
        }

        long long remainingCapacity() const {
            return capacity - flow;
        }

        void augment(long long bottleNeck) {
            flow += bottleNeck;
            residual->flow -= bottleNeck;
        }

        string toString(int s, int t) const {
            string u = (from == s) ? "s" : ((from == t) ? "t" : to_string(from));
            string v = (to == s) ? "s" : ((to == t) ? "t" : to_string(to));
            return "Edge " + u + " -> " + v + " | flow = " + to_string(flow) + " | capacity = " + to_string(capacity) +
                   " | is residual: " + (isResidual() ? "true" : "false");
        }
    };
class NetworkFlowSolverBase {
protected:
    static constexpr long long INF = LLONG_MAX / 2;
    
    

    int n, s, t;
    long long maxFlow = 0;
    long long minCost = 0;
    vector<bool> minCut;
    vector<vector<Edge*>> graph;
    vector<int> vis;
    int visitedToken = 1;
    bool solved = false;

    void visit(int i) {
        vis[i] = visitedToken;
    }

    bool visited(int i) const {
        return vis[i] == visitedToken;
    }

    void markAllNodesAsUnvisited() {
        visitedToken++;
    }

    void execute() {
        if (solved) return;
        solved = true;
        solve();
    }

public:
    NetworkFlowSolverBase(int n, int s, int t) : n(n), s(s), t(t), minCut(n), vis(n) {
        graph.resize(n);
    }

    virtual ~NetworkFlowSolverBase() {
        for (auto& edges : graph) {
            for (auto& edge : edges) {
                delete edge;
            }
        }
    }

    void addEdge(int from, int to, long long capacity) {
        if (capacity < 0) throw invalid_argument("Capacity < 0");
        Edge* e1 = new Edge(from, to, capacity);
        Edge* e2 = new Edge(to, from, 0);
        e1->residual = e2;
        e2->residual = e1;
        graph[from].push_back(e1);
        graph[to].push_back(e2);
    }

    void addEdge(int from, int to, long long capacity, long long cost) {
        Edge* e1 = new Edge(from, to, capacity, cost);
        Edge* e2 = new Edge(to, from, 0, -cost);
        e1->residual = e2;
        e2->residual = e1;
        graph[from].push_back(e1);
        graph[to].push_back(e2);
    }

    vector<vector<Edge*>> getGraph() {
        execute();
        return graph;
    }

    long long getMaxFlow() {
        execute();
        return maxFlow;
    }

    long long getMinCost() {
        execute();
        return minCost;
    }

    vector<bool> getMinCut() {
        execute();
        return minCut;
    }

    virtual void solve() = 0;
};

class CapacityScalingSolverAdjacencyList : public NetworkFlowSolverBase {
private:
    long long delta = 0;

    long long dfs(int node, long long flow) {
        if (node == t) return flow;

        visit(node);
        for (auto edge : graph[node]) {
            long long cap = edge->remainingCapacity();
            if (cap >= delta && !visited(edge->to)) {
                long long bottleNeck = dfs(edge->to, min(flow, cap));
                if (bottleNeck > 0) {
                    edge->augment(bottleNeck);
                    return bottleNeck;
                }
            }
        }
        return 0;
    }

public:
    CapacityScalingSolverAdjacencyList(int n, int s, int t) : NetworkFlowSolverBase(n, s, t) {}

    void addEdge(int from, int to, long long capacity) {
        NetworkFlowSolverBase::addEdge(from, to, capacity);
        delta = max(delta, capacity);
    }

    void solve() override {
        delta = 1LL << (63 - __builtin_clzll(delta));
        for (long long f = 0; delta > 0; delta /= 2) {
            do {
                markAllNodesAsUnvisited();
                f = dfs(s, INF);
                maxFlow += f;
            } while (f != 0);
        }

        for (int i = 0; i < n; i++) {
            if (visited(i)) minCut[i] = true;
        }
    }
};

int main() {
    auto testSmallFlowGraph = []() {
        int n = 6;
        int s = n - 1;
        int t = n - 2;

        CapacityScalingSolverAdjacencyList solver(n, s, t);

        solver.addEdge(s, 0, 10);
        solver.addEdge(s, 1, 10);
        solver.addEdge(2, t, 10);
        solver.addEdge(3, t, 10);
        solver.addEdge(0, 1, 2);
        solver.addEdge(0, 2, 4);
        solver.addEdge(0, 3, 8);
        solver.addEdge(1, 3, 9);
        solver.addEdge(3, 2, 6);

        cout << solver.getMaxFlow() << endl; // 19
    };

    auto testExampleFromMySlides = []() {
        int n = 6;
        int s = n - 1;
        int t = n - 2;

        CapacityScalingSolverAdjacencyList solver(n, s, t);

        solver.addEdge(s, 0, 6);
        solver.addEdge(s, 1, 14);
        solver.addEdge(2, t, 11);
        solver.addEdge(3, t, 12);
        solver.addEdge(0, 1, 1);
        solver.addEdge(2, 3, 1);
        solver.addEdge(0, 2, 5);
        solver.addEdge(1, 2, 7);
        solver.addEdge(1, 3, 10);

        cout << solver.getMaxFlow() << endl; // 20
    };
  //Here we are considering the edges which has a really high remaining capacity first and then we are using the general appraoch
  //the overall complexity is o(E^2*log(U))->U is the maximum remaining capacity
  //we can also acheieve a complexity of O(E*V*log(U))->by using bfs approach
  
    testSmallFlowGraph();
    testExampleFromMySlides();

    return 0;
}
