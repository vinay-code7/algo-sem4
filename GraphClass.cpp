#include <vector>
#include <map>
using namespace std;

#define pair_ii pair<int, int>

class Graph_Weighted_Directed
{
public:
    map<int, vector<pair_ii>> graph;

    void add_edge(int from, int to, int weight)
    {
        graph[from].push_back({to, weight});
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

class Graph_Weighted : public Graph_Weighted_Directed
{
public:
    void add_edge(int a, int b, int weight)
    {
        Graph_Weighted_Directed::add_edge(a, b, weight);
        Graph_Weighted_Directed::add_edge(b, a, weight);
    }
};

class Graph_Directed : public Graph_Weighted_Directed
{
public:
    void add_edge(int from, int to)
    {
        Graph_Weighted_Directed::add_edge(from, to, 0);
    }

    vector<int> neighbors(int src)
    {
        vector<int> res;
        for (pair_ii p : Graph_Weighted_Directed::neighbors(src))
            res.push_back(p.first);
        return res;
    }
};

class Graph : public Graph_Directed
{
public:
    void add_edge(int a, int b)
    {
        Graph_Directed::add_edge(a, b);
        Graph_Directed::add_edge(b, a);
    }
};
