// https://www.geeksforgeeks.org/connected-components-in-an-undirected-graph/
// https://algorithms.tutorialhorizon.com/graph-find-number-of-non-reachable-vertices-from-a-given-vertex/

#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    Graph(int V);
    void addEdge(int v, int w);
    void dfs(int start, bool visited[]);
    int calculateVertices(int vertex);

private:
    int numsOfVertices;
    list<int> *adj;
};

Graph::Graph(int V)
{
    this->numsOfVertices = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v - 1].push_back(w - 1);
    adj[w - 1].push_back(v - 1);
}

void Graph::dfs(int start, bool visited[])
{
    visited[start] = true;
    //cout << start << " ";

    list<int>::iterator it;
    for(it = adj[start].begin(); it != adj[start].end(); it++)
    {
        if(!visited[*it])
        {
            dfs(*it, visited);
        }
    }
}

int Graph::calculateVertices(int vertex)
{
    bool visited[numsOfVertices];
    for(int i = 0; i < numsOfVertices; i++)
    {
        visited[i] = false;
    }
    dfs(vertex, visited);

    int count = 0;
    for(int i = 0; i < numsOfVertices; i++)
    {
        if(visited[i] == true)
        {
            count++;
        }
    }

    return count;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int V, E, src, dst;
    cin >> V >> E;
    Graph g(V);
    for(int i = 0; i < E; i++)
    {
        cin >> src >> dst;
        g.addEdge(src, dst);
    }
    

    for(int i = 0; i < V; i++)
    {
        cout << g.calculateVertices(i) - 1 << " ";
    }
    cout << endl;

    return 0;
}
