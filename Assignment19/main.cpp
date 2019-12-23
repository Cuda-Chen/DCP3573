#include <bits/stdc++.h>
using namespace std;

#define INF 100000001 // 10^8 + 1

// distance[src][dst]

class Graph
{
public:
    Graph(): numOfVertex(0) {};
    Graph(int n);
    void addEdge(int src, int dst, int weight);
    void initializeDistance();
    void floydWarshall();
    int minimalTime();
private:
    int numOfVertex;
    vector<vector<int>> adjMatrix;
    vector<vector<int>> distance;
};

Graph::Graph(int n): numOfVertex(n)
{
    adjMatrix.resize(numOfVertex);
    for(int i = 0; i < numOfVertex; i++)
    {
        adjMatrix[i].resize(numOfVertex, INF);
        for(int j = 0; j < numOfVertex; j++)
        {
            if(i == j)
            {
                adjMatrix[i][j] = 0;
            }
        }
    }
}

void Graph::addEdge(int src, int dst, int weight)
{
    adjMatrix[src][dst] = weight;
}

void Graph::initializeDistance()
{
    distance.resize(numOfVertex);

    for(int i = 0; i < numOfVertex; i++)
    {
        distance[i].resize(numOfVertex);
        for(int j = 0; j < numOfVertex; j++)
        {
            distance[i][j] = adjMatrix[i][j];
        }
    }
}

void Graph::floydWarshall()
{
    initializeDistance();

    for(int k = 0; k < numOfVertex; k++)
    {
        for(int i = 0; i < numOfVertex; i++)
        {
            for(int j = 0; j < numOfVertex; j++)
            {
                if(distance[i][j] > distance[i][k] + distance[k][j])
                {
                    distance[i][j] = distance[i][k] + distance[k][j];
                }
            }
        }
    }
}

int Graph::minimalTime()
{
    int sum = 0;
    for(int i = 1; i <= numOfVertex - 1; i++)
    {
        //cout << "distance[0][" << i << "] = " << distance[0][i] << endl;
        //cout << "distance[" << i << "][0] = " << distance[i][0] << endl;

        sum += distance[0][i];
        sum += distance[i][0];
    }

    return sum;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    int numOfEdge;
    cin >> n >> numOfEdge;
    Graph g(n + 1);
    int src, dst, weight;
    for(int i = 0; i < numOfEdge; i++)
    {
        cin >> src >> dst >> weight;
        g.addEdge(src, dst, weight);
    }

    g.floydWarshall();

    int sum = g.minimalTime();
    cout << sum << endl;

    return 0;
}
