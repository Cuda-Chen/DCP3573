// find the path between given vertices in a directed graph
// https://www.techiedelight.com/find-path-between-vertices-directed-graph/

// finding the path that minimizes the maximum weight between two nodes
// https://stackoverflow.com/questions/29900927/algorithm-for-finding-the-path-that-minimizes-the-maximum-weight-between-two-nod

#include <bits/stdc++.h>
using namespace std;

#define INF 100000001 // 10^8 + 1

// distance[src][dst]

struct Edge 
{
    int src;
    int dst;
    int weight;

    bool operator<(Edge e) const
    {
        return weight < e.weight;
    }
};

class Graph
{
public:
    Graph(const vector<Edge> &edges);
    Graph(const vector<Edge> &edges, int n);
    bool isConnected(const Graph &graph, int src, int dst,
        vector<bool> &visited);
private:
    vector<vector<pair<int, int>>> adjList; // src -> <dst, weight>
};

Graph::Graph(const vector<Edge> &edges)
{
    for(auto &edge: edges)
    {
        adjList[edge.src].push_back(make_pair(edge.dst, edge.weight));
    }
}

Graph::Graph(const vector<Edge> &edges, int n)
{
    adjList.resize(n);

    for(auto &edge: edges)
    {
        adjList[edge.src].push_back(make_pair(edge.dst, edge.weight));
    }
}

// BFS to find if src and dst are connected
bool Graph::isConnected(const Graph &graph, int src, int dst,
    vector<bool> &visited)
{
    queue<int> q;
    visited[src] = true;

    q.push(src);

    while(!q.empty())
    {
        int v = q.front();
        q.pop();

        if(v == dst)
        {
            return true;
        }

        for(auto elem: graph.adjList[v])
        {
            auto u = elem.first;
            if(!visited[u])
            {
                visited[u] = true;
                q.push(u);
            }
        }
    }

    return false;
}

int maxBrightestRoad(vector<Edge> &edges, int src, int dst) 
{
    int low = -1, high = edges.size() - 1;
    while(high - low > 1)
    {
        int mid = low + (high - low) / 2;
        vector<Edge> subEdges = vector<Edge>(edges.begin(), edges.begin() + mid);
        int vertexCount = -1;
        for(auto &subEdge: subEdges)
        {
            if(subEdge.src > vertexCount)
            {
                vertexCount = subEdge.src;
            }
            if(subEdge.dst > vertexCount)
            {
                vertexCount = subEdge.dst;
            }
        }
        vertexCount += 1;
        cout << "subEdges.size(): " << subEdges.size() << " vertexCount: " << vertexCount << endl;
        //cout << "high " << high << " low " << low << " mid " << mid << endl; 
        //assert(subEdges.size() == vertexCount);
        Graph g(subEdges, vertexCount);
        vector<bool> visited(vertexCount);
        if(g.isConnected(g, src, dst, visited))
        {
            high = mid;
        }
        else
        {
            low = mid;
        }
    }

    return edges[high].weight;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int numsOfVertex, numsOfEdge, numsOfSlayer;
    cin >> numsOfVertex >> numsOfEdge >> numsOfSlayer;

    vector<Edge> edges;
    Edge temp;
    for(int i = 0; i < numsOfEdge; i++)
    {
        cin >> temp.src >> temp.dst >> temp.weight;
        edges.push_back(temp);   
    }

    vector<pair<int, int>> routes; // src -> dst
    pair<int, int> routeTemp;
    for(int i = 0; i < numsOfSlayer; i++)
    {
        cin >> routeTemp.first >> routeTemp.second;
        routes.push_back(routeTemp);
    }

    // first sort edges by their weight in increasing order for later use
    sort(edges.begin(), edges.end());
   
    Graph graph(edges, numsOfEdge);
    for(int i = 0; i < numsOfSlayer; i++)
    {
        vector<bool> visited(numsOfVertex);
        int src = routes[i].first, dst = routes[i].second;
        if(graph.isConnected(graph, src, dst, visited))
        {
            // print the brightest road
            //cout << src << " " << dst << " is connected" << endl;
            cout << maxBrightestRoad(edges, src, dst) << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
 
    return 0;
}
