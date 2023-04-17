#include <iostream>
#include <deque>
#include "GraphClass.cpp"
using namespace std;

void DFS(Graph graph, int size, int source)
{
    deque<int> st;

    bool visited[size];
    for (int i = 0; i < size; i++)
        visited[i] = 0;

    st.push_back(source);
    while (!st.empty())
    {
        int node = st.back();
        st.pop_back();

        if (visited[node])
            continue;
        visited[node] = 1;

        cout << node << " ";
        for (int nei : graph.neighbors(node))
            st.push_back(nei);
    }
}

void BFS(Graph graph, int size, int source)
{
    deque<int> q;
    
    bool visited[size];
    for (int i = 0; i < size; i++)
        visited[i] = 0;

    q.push_back(source);
    while (!q.empty())
    {
        int node = q.front();
        q.pop_front();

        if (visited[node])
            continue;
        visited[node] = 1;

        cout << node << " ";
        for (int nei : graph.neighbors(node))
            q.push_back(nei);
    }
}

int main()
{
    /*
            0 --- 1
            |     |
            3 --- 2
             \   /
              \ /
               4
    */

    int num_nodes = 5;
    Graph graph;

    vector<vector<int>> edges;
    edges.push_back({0, 1});
    edges.push_back({1, 2});
    edges.push_back({2, 3});
    edges.push_back({3, 0});
    edges.push_back({3, 4});
    edges.push_back({2, 4});

    for (int i = 0; i < edges.size(); i++)
        graph.add_edge(edges[i][0], edges[i][1]);

    // // input number of nodes
    // cout << "Enter number of nodes: ";
    // int num_nodes;
    // cin >> num_nodes;

    // // initialization
    // Graph graph(num_nodes);

    // // input of edges
    // cout << "Enter number of edges: ";
    // int n;
    // cin >> n;
    // for (int i = 0; i < n; i++)
    // {
    //     cout << "Enter edge: ";
    //     int a, b;
    //     cin >> a >> b;
    //     graph.add_edge(a, b);
    // }

    // print dfs for each node
    cout << endl;
    for (int node : graph.nodes())
    {
        cout << "Node " << node << ": ";
        DFS(graph, num_nodes, node);
        cout << endl;
    }

    // print bfs for each node
    cout << endl;
    for (int node : graph.nodes())
    {
        cout << "Node " << node << ": ";
        BFS(graph, num_nodes, node);
        cout << endl;
    }
}