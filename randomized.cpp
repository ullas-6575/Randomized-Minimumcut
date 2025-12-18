#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v;
};

int Cut(int V, vector<Edge> edges) {
    int vertices = V;

    random_device rd;
    mt19937 gen(rd());

    while (vertices > 2 && !edges.empty()) {
        uniform_int_distribution<int> dist(0, edges.size() - 1);
        int idx = dist(gen);

        int u = edges[idx].u;
        int v = edges[idx].v;

        for (auto &e : edges) {
            if (e.u == v) e.u = u;
            if (e.v == v) e.v = u;
        }

    
        vector<Edge> newEdges;
        for (auto &e : edges) {
            if (e.u != e.v)
                newEdges.push_back(e);
        }

        edges = newEdges;
        vertices--;
    }

    return edges.size();
}

int main() {

     freopen("input.txt","r",stdin);
     freopen("output.txt","w",stdout);
    int V, E;
    cin >> V >> E;

    vector<Edge> edges;
    for (int i = 0; i < E; i++) {
        int a, b;
        cin >> a >> b;
        edges.push_back({a, b});
    }

    int ans = INT_MAX;

  
    for (int i = 0; i < V * V; i++) {
        ans = min(ans, Cut(V, edges));
    }

    cout << "Minimum Cut: " << ans << endl;
    return 0;
}
