// https://www.geeksforgeeks.org/find-edge-disjoint-paths-two-vertices/

#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    Graph(): verticesNum(0) {};
    Graph(int n);
    void addEdge(int src, int dst, int weight = 1);
    bool isReachable(vector<vector<int>> residualGraph, int src, int dst, vector<int> parent);
    int findDisjointPaths(int src, int dst);
private:
    int verticesNum;
    vector<vector<int>> adjMatrix;
};

Graph::Graph(int n): verticesNum(n)
{
    adjMatrix.resize(verticesNum);
    for(int i = 0; i < verticesNum; i++)
    {
        adjMatrix[i].resize(verticesNum);
        for(int j = 0; j < verticesNum; j++)
        {
            adjMatrix[i][j] = 0;
        }
    }
}

void Graph::addEdge(int src, int dst, int weight)
{
    adjMatrix[src][dst] = weight;
    adjMatrix[dst][src] = weight;
}

// BFS with residual graph (for Ford-Fulkerson Algorithm)
bool Graph::isReachable(vector<vector<int>> resudualGraph, int src, int dst, vector<int> parent)
{
    vector<bool> visited(verticesNum, false);

    queue<int> q;
    q.push(src);
    visited[src] = true;
    parent[src] = -1; // assign -1 to indicate the source node
    //cout << "start from " << src << ", found ";

    while(!q.empty())
    {
        int u = q.front();
        q.pop();

        for(int v = 0; v < verticesNum; v++)
        {
            if(visited[v] == false && resudualGraph[u][v] > 0)
            {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
                //cout << v << " ";
            }
        }
    }

    cout << endl;

    // check whether dst is reachable from src
    return (visited[dst] == true);
}

// using Ford-Fulkerson Algorithm to find edge disjoint path
int Graph::findDisjointPaths(int src, int dst)
{
    vector<vector<int>> residualGraph(verticesNum, vector<int>(verticesNum));
    for(int i = 0; i < verticesNum; i++)
    {
        for(int j = 0; j < verticesNum; j++)
        {
            residualGraph[i][j] = adjMatrix[i][j];
        }
    }
    vector<int> parent(verticesNum);
    int maxFlow = 0;

    while(isReachable(residualGraph, src, dst, parent))
    {
        int pathFlow = INT_MAX;
        int u, v;

        for(v = dst; v != src; v = parent[v])
        {
            u = parent[v];
            pathFlow = min(pathFlow, residualGraph[u][v]);
        }

        for(v = dst; v != src; v = parent[v])
        {
            u = parent[v];
            residualGraph[u][v] -= pathFlow;
            residualGraph[v][u] += pathFlow;
        }

        maxFlow += pathFlow;
    }

    return maxFlow;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int verticesNum, edgesNum;
    cin >> verticesNum >> edgesNum;
    Graph g(verticesNum);
    int src, dst;
    for(int i = 0; i < edgesNum; i++)
    {
        cin >> src >> dst;
        g.addEdge(src, dst, 1);
    }

    cout << g.findDisjointPaths(0, verticesNum - 1) << endl;

    return 0;
}
