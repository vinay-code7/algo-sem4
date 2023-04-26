#include <iostream>
#include <queue>
#include <map>
#include <map>
#include <vector>
using namespace std;

#define pair_ii pair<int, int>

class Graph
{
public:
    map<int, vector<pair_ii>> graph;

    void add_edge(int a, int b, int weight)
    {
        graph[a].push_back({b, weight});
        graph[b].push_back({a, weight});
    }

    vector<int> nodes()
    {
        vector<int> res;
        // map<int, vector<pair_ii>>::iterator itr;
        for (auto itr = graph.begin(); itr != graph.end(); itr++)
            res.push_back(itr->first);
        return res;
    }

    vector<pair_ii> neighbors(int src)
    {
        if (graph.find(src) == graph.end())
            return vector<pair_ii>();
        return graph.at(src);
    }
};

void primMST(Graph graph, int src)
{
    map<int, int> parent;
    map<int, int> key;
    map<int, bool> visited;

    for (int node : graph.nodes())
    {
        parent[node] = -1;
        key[node] = 9999;
        visited[node] = false;
    }

    key[src] = 0;

    priority_queue<pair<int, int>> pq;
    pq.push({0, src});

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        visited[u] = true;

        for (pair<int, int> nei : graph.neighbors(u))
        {
            int v = nei.first;
            int weight = nei.second;

            if (!visited[v] && weight < key[v])
            {
                parent[v] = u;
                key[v] = weight;
                pq.push({-weight, v});
            }
        }
    }

    for (int node : graph.nodes())
        printf("%c - %c\n", node + 'a', parent[node] + 'a');
}

int main()
{
    // int graph[V][V] = {
    //     // a b c  d  e  f  g  h  i
    //     {0, 4, 0, 0, 0, 0, 0, 8, 0},   // a
    //     {4, 0, 8, 0, 0, 0, 0, 11, 0},  // b
    //     {0, 8, 0, 7, 0, 4, 0, 0, 2},   // c
    //     {0, 0, 7, 0, 9, 14, 0, 0, 0},  // d
    //     {0, 0, 0, 9, 0, 10, 0, 0, 0},  // e
    //     {0, 0, 4, 14, 10, 0, 2, 0, 0}, // f
    //     {0, 0, 0, 0, 0, 2, 0, 1, 6},   // g
    //     {8, 11, 0, 0, 0, 0, 1, 0, 7},  // h
    //     {0, 0, 2, 0, 0, 0, 6, 7, 0},   // i
    // };

    Graph graph;

    // graph.add_edge(0, 1, 2);
    // graph.add_edge(0, 3, 6);
    // graph.add_edge(1, 2, 3);
    // graph.add_edge(1, 3, 8);
    // graph.add_edge(1, 4, 5);
    // graph.add_edge(2, 4, 7);
    // graph.add_edge(3, 4, 9);


    // a b c d e f g h i
    // 0 1 2 3 4 5 6 7 8
    int edges[14][3] = {
        {0, 1, 4},
        {0, 7, 8},
        {1, 2, 8},
        {1, 7, 11},
        {2, 3, 7},
        {2, 5, 4},
        {2, 8, 2},
        {3, 4, 9},
        {3, 5, 14},
        {4, 5, 10},
        {5, 6, 2},
        {6, 7, 1},
        {6, 8, 7},
        {7, 8, 7},
    };

    for (int i = 0; i < 14;i++)
    {
        int a = edges[i][0];
        int b = edges[i][1];
        int w = edges[i][2];
        graph.add_edge(a, b, w);
    }

    primMST(graph, 0);
}