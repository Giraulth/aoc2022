// Program to find Dijkstra's shortest path using
// priority_queue in STL
#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f

// iPair ==> Integer Pair
typedef pair<int, int> iPair;

// This class represents a directed graph using
// adjacency list representation
class Graph
{
    int V; // No. of vertices

    // In a weighted graph, we need to store vertex
    // and weight pair for every edge
    list<pair<int, int>> *adj;

public:
    Graph(int V); // Constructor

    int minStep = 1000000000;

    // function to add an edge to graph
    void addEdge(int u, int v, int w);

    // prints shortest path from s to end e
    void shortestPath(int s, int e);
};

// Allocates memory for adjacency list
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<iPair>[V];
}

void Graph::addEdge(int u, int v, int w)
{
    adj[u].push_back(make_pair(v, w));
    // adj[v].push_back(make_pair(u, w));
}

// Prints shortest paths from src to all other vertices
void Graph::shortestPath(int src, int end)
{
    // Create a priority queue to store vertices that
    // are being preprocessed. This is weird syntax in C++.
    // Refer below link for details of this syntax
    // https://www.geeksforgeeks.org/implement-min-heap-using-stl/
    priority_queue<iPair, vector<iPair>, greater<iPair>>
        pq;

    // Create a vector for distances and initialize all
    // distances as infinite (INF)
    vector<int> dist(V, INF);

    // Insert source itself in priority queue and initialize
    // its distance as 0.
    pq.push(make_pair(0, src));
    dist[src] = 0;
    dist[end] = 1000000;

    /* Looping till priority queue becomes empty (or all
    distances are not finalized) */
    while (!pq.empty())
    {
        // The first vertex in pair is the minimum distance
        // vertex, extract it from priority queue.
        // vertex label is stored in second of pair (it
        // has to be done this way to keep the vertices
        // sorted distance (distance must be first item
        // in pair)
        int u = pq.top().second;
        pq.pop();

        // 'i' is used to get all adjacent vertices of a
        // vertex
        list<pair<int, int>>::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
        {
            // Get vertex label and weight of current
            // adjacent of u.
            int v = (*i).first;
            int weight = (*i).second;

            // If there is shorted path to v through u.
            if (dist[v] > dist[u] + weight)
            {
                // Updating distance of v
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));

            }

            if (dist[end]>minStep && dist[end] != 1000000)
                break;
        }
    }

    if(dist[end]<minStep)
        minStep = dist[end];

    
}

int M = 0;
int N = 0;
int endPos = 0;
vector<int> srcPos;
vector<vector<bool>> isVisited;
vector<string> heigth;

bool isVisitable(int x, int y, int i, int j)
{
    if (x >= 0 && x < N && y >= 0 && y < M)
    {
        int dest = int(heigth[x][y]);
        int src = int(heigth[i][j]) + 1;
        if (heigth[x][y] == 'E')
        {
            dest = int('z') + 1;
            endPos = x * M + y;
        }
        if (heigth[i][j] == 'E')
        {
            return false;
        }
        if (heigth[i][j] == 'S' || heigth[i][j] == 'a')
        {
            srcPos.push_back(i * M + j);
        }
        if (dest == src || int(heigth[i][j]) == 83 || dest < src)
        {
            return true;
        }
    }

    return false;
}

// Driver program to test methods of graph class
int main()
{

    std::ifstream file("day12.txt");

    string str;
    pair<int, int> start, end, currentPos;
    while (std::getline(file, str))
    {
        heigth.push_back(str);
        N++;
    }

    M = heigth[0].size();

    // create the graph given in above figure
    int V = M * N;
    Graph g(V);

    // make graph
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int currentNode = i * M + j;
            if (isVisitable(i + 1, j, i, j))
            {
                int visitNode = (i + 1) * M + j;
                g.addEdge(currentNode, visitNode, 1);
            }
            if (isVisitable(i - 1, j, i, j))
            {
                int visitNode = (i - 1) * M + j;
                g.addEdge(currentNode, visitNode, 1);
            }
            if (isVisitable(i, j + 1, i, j))
            {

                int visitNode = i * M + j + 1;
                g.addEdge(currentNode, visitNode, 1);
            }
            if (isVisitable(i, j - 1, i, j))
            {
                int visitNode = i * M + j - 1;
                g.addEdge(currentNode, visitNode, 1);
            }
        }
    }

    for (const auto & elt : srcPos){
        g.shortestPath(elt, endPos);
    }

    cout << g.minStep;

    return 0;
}