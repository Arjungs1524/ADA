#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge { 	// Define an Edge structure
    int u, v, weight;
};

bool compareEdges(Edge e1, Edge e2) { 	// Comparator function to sort edges based on their weight
    return e1.weight < e2.weight;
}

class DSU {		// Disjoint Set Union (DSU) or Union-Find data structure
public: vector<int> parent, rank;
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int u) {
        if (u != parent[u]) {
            parent[u] = find(parent[u]); // Path compression
        }
        return parent[u];
    }

    void unite(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);
        if (rootU != rootV) {
            if (rank[rootU] > rank[rootV]) {
                parent[rootV] = rootU;
            } else if (rank[rootU] < rank[rootV]) {
                parent[rootU] = rootV;
            } else {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }
};

int main() {
    int V, E; // V = number of vertices, E = number of edges
    cout << "Enter the number of vertices and edges: ";
    cin >> V >> E;
    vector<Edge> edges(E);

    cout << "Enter the edges (u v weight) one by one:" << endl;
    for (int i = 0; i < E; ++i) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }

    sort(edges.begin(), edges.end(), compareEdges); 	// Sort edges based on their weight
    DSU dsu(V);

    vector<Edge> mst; // Store the edges of the Minimum Spanning Tree
    int mst_weight = 0;

    for (Edge e : edges) {
        if (dsu.find(e.u) != dsu.find(e.v)) {
            dsu.unite(e.u, e.v);
            mst.push_back(e);
            mst_weight += e.weight;
        }
    }

    cout << "Edges in the Minimum Spanning Tree:" << endl;	// Print the edges of the Minimum Spanning Tree
    for (Edge e : mst) {
        cout << e.u << " -- " << e.v << " == " << e.weight << endl;
    }
    cout << "Total weight of the Minimum Spanning Tree: " << mst_weight << endl;
    return 0;
}
// refer - https://www.youtube.com/watch?v=DMnDM_sxVig
