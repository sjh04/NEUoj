#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct vertex
{
    int value;
    vector<pair<int, int>> children;
};

void Dijkstra(vector<vertex> &vertex, vector<int> &dist)
{
    vector<bool> visited(vertex.size(), false);
    dist[0] = 0;
    for (auto &c : vertex[0].children)
    {
        dist[c.first] = c.second;
    }
    visited[0] = true;
    while (1)
    {
        int min = INT_MAX;
        int min_index = -1;
        for (int i = 0; i < vertex.size(); i++)
        {
            if (!visited[i] && dist[i] < min)
            {
                min = dist[i];
                min_index = i;
            }
        }
        if (min_index == -1)
        {
            break;
        }
        visited[min_index] = true;
        for (auto &c : vertex[min_index].children)
        {
            if (dist[c.first] > dist[min_index] + c.second)
            {
                dist[c.first] = dist[min_index] + c.second;
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<vertex> vertices(n);
    for (int i = 0; i < n; i++)
    {
        int value, k;
        cin >> value >> k;
        vertices[i].value = value;
        for (int j = 0; j < k; j++)
        {
            int child, weight;
            cin >> child >> weight;
            vertices[i].children.push_back({child, weight});
        }
    }
    vector<int> dist(n, INT_MAX);
    Dijkstra(vertices, dist);
    for (int i = 0; i < n; i++)
    {
        cout << vertices[i].value << " " << dist[i] << endl;
    }
    return 0;
}