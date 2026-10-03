//NAME - MEET KUMAR
//ROLL NO- 25/DA/042
#include <iostream>
using namespace std;

#define V 5
#define INF 9999

void prims(int graph[V][V]) {
    int parent[V];
    int key[V];
    bool mst[V];

    for (int i = 0; i < V; i++) {
        key[i] = INF;
        mst[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++) {
        int min = INF, u;

        for (int v = 0; v < V; v++) {
            if (!mst[v] && key[v] < min) {
                min = key[v];
                u = v;
            }
        }

        mst[u] = true;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !mst[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    cout << "Prim's MST:\n";
    int total = 0;

    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i
             << " : " << graph[i][parent[i]] << endl;
        total += graph[i][parent[i]];
    }

    cout << "Total weight = " << total << endl;
}

int main() {

    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    prims(graph);

    return 0;
}